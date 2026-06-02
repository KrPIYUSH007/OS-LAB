/*Wont work on all systems
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define size 5
int buffer[size];
int in=0,out=0;
int pcount,ccount;
sem_t mutex,empty,full;
void* producer(void* args){
    for (int i=0;i<pcount;i++){
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in]=i;
        printf("Produceed%d at buffer[%d]", i, in);
        in=(in+1)%size;
        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}
void* consumer(void* args){
    for(int i=0;i<ccount;i++){
        sem_wait(&full);
        sem_wait(&mutex);
        int item=buffer[out];
        printf("Consumed item %d from buffer[%d]", item,out);
        out=(out+1)%size;
        sem_post(&mutex);
        sem_post(&empty);
        return NULL;
    }
}
int main(){
    pthread_t p,c;
    printf("Enter the number of items to produce");
    scanf("%d", &pcount);
    printf("Enter the number of items to consume");
    scanf("%d", &ccount);
    sem_init(&mutex,0,1);
    sem_init(&empty,0,size);
    sem_init(&full,0,0);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);
    pthread_join(p,NULL);
    pthread_join(c,NULL);
    return 0;

}*/
#include <stdio.h>

int mutex = 1;
int full = 0;
int empty;
int x = 0;

void producer()
{
    mutex--;

    x++;
    full++;
    empty--;

    printf("Produced Item %d\n", x);

    mutex++;
}

void consumer()
{
    mutex--;

    printf("Consumed Item %d\n", x);

    x--;
    full--;
    empty++;

    mutex++;
}

int main()
{
    int size, p_count, c_count;

    printf("Enter Buffer Size: ");
    scanf("%d", &size);

    printf("Enter Number of Items to Produce: ");
    scanf("%d", &p_count);

    printf("Enter Number of Items to Consume: ");
    scanf("%d", &c_count);

    empty = size;

    for(int i = 0; i < p_count; i++)
    {
        if(mutex == 1 && empty != 0)
            producer();
        else
            printf("Buffer Full\n");
    }

    for(int i = 0; i < c_count; i++)
    {
        if(mutex == 1 && full != 0)
            consumer();
        else
            printf("Buffer Empty\n");
    }

    printf("\nFinal Status:\n");
    printf("Full = %d\n", full);
    printf("Empty = %d\n", empty);

    return 0;
}

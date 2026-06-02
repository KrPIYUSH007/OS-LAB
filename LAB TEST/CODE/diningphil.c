//may not work
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX 10

int n;
sem_t forks[MAX];

void* philosopher(void* num)
{
    int id = *(int*)num;

    printf("Philosopher %d is thinking.\n", id);
    sleep(1);

    if(id == n - 1)
    {
        sem_wait(&forks[id]);
        printf("Philosopher %d picked up left fork %d.\n", id, id);

        sem_wait(&forks[(id + 1) % n]);
        printf("Philosopher %d picked up right fork %d.\n", id, (id + 1) % n);
    }
    else
    {
        sem_wait(&forks[(id + 1) % n]);
        printf("Philosopher %d picked up right fork %d.\n", id, (id + 1) % n);

        sem_wait(&forks[id]);
        printf("Philosopher %d picked up left fork %d.\n", id, id);
    }

    printf("Philosopher %d is eating.\n", id);
    sleep(1);

    sem_post(&forks[id]);
    sem_post(&forks[(id + 1) % n]);

    printf("Philosopher %d put down forks.\n", id);
    printf("Philosopher %d is thinking.\n", id);

    return NULL;
}

int main()
{
    pthread_t p[MAX];
    int ids[MAX];

    printf("Enter number of philosophers: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        sem_init(&forks[i], 0, 1);

    for(int i = 0; i < n; i++)
    {
        ids[i] = i;
        pthread_create(&p[i], NULL, philosopher, &ids[i]);
    }

    for(int i = 0; i < n; i++)
        pthread_join(p[i], NULL);

    return 0;
}
/*#include <stdio.h>

int mutex = 1;
int chopstick[5] = {1,1,1,1,1};

void philosopher(int n)
{
    int left = n;
    int right = (n + 1) % 5;

    if(chopstick[left] == 1 &&
       chopstick[right] == 1 &&
       mutex == 1)
    {
        mutex = 0;

        chopstick[left] = 0;
        chopstick[right] = 0;

        printf("\nPhilosopher %d is Eating", n + 1);

        chopstick[left] = 1;
        chopstick[right] = 1;

        printf("\nPhilosopher %d Finished Eating", n + 1);

        mutex = 1;
    }
    else
    {
        printf("\nPhilosopher %d is Waiting", n + 1);
    }
}

int main()
{
    int n;

    printf("Enter Philosopher Number (1-5): ");
    scanf("%d",&n);

    philosopher(n - 1);

    return 0;
}*/
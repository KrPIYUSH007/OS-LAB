#include <stdio.h>
void rms(int period[], int burst[], int remaining[], int n, int time_limit)
{
    int order[1000];//
    int times[1001];//
    int k = 0;//
    times[0] = 0;//
    int time = 0;
    while(time < time_limit)
    {
        int highest = -1;
        for(int i = 0; i < n; i++)
        {
            if(remaining[i] > 0)
            {
                if(highest == -1 || period[i] < period[highest])
                {
                    highest = i;
                }
            }
        }
        if(highest != -1)
        {
            printf("Time %d -> P%d\n", time, highest + 1);
            order[k] = highest;//
            remaining[highest]--;
        }
        else
        {
            printf("Time %d -> Idle\n", time);
            order[k] = -1;//
        }
        time++;
        k++;//
        times[k] = time;//
    }
    printf("\nGantt Chart:\n\n|");
    for(int i = 0; i < k; i++)
    {
        if(order[i] == -1)
            printf(" IDLE |");
        else
            printf(" P%d |", order[i] + 1);
    }
    printf("\n");
    for(int i = 0; i <= k; i++)
    {
        printf("%d\t", times[i]);
    }
    printf("\n");
}
int main()
{
    int n, time_limit;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int period[n];
    int burst[n];
    int remaining[n];
    for(int i = 0; i < n; i++)
    {
        printf("Enter Period and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &period[i], &burst[i]);
        remaining[i] = burst[i];
    }
    printf("Enter Total Simulation Time: ");
    scanf("%d", &time_limit);
    rms(period, burst, remaining,
        n, time_limit);
    return 0;
}
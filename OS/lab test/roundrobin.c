#include <stdio.h>

int main()
{
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n], resp[n];
    int visited[n];

    int completed = 0;
    int time = 0;

    int sumtat = 0, sumwt = 0, sumrt = 0;

    float avgtat, avgwt, avgrt;

    int order[1000];
    int times[1001];
    int k = 0;

    times[0] = 0;

    for(int i=0;i<n;i++)
    {
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);

        rt[i] = bt[i];
        visited[i] = 0;
    }

    while(completed < n)
    {
        int found = 0;

        for(int i=0;i<n;i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                found = 1;

                if(visited[i] == 0)
                {
                    resp[i] = time - at[i];
                    visited[i] = 1;
                }

                order[k] = i;

                if(rt[i] > tq)
                {
                    time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    time += rt[i];

                    ct[i] = time;

                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    sumtat += tat[i];
                    sumwt += wt[i];
                    sumrt += resp[i];

                    rt[i] = 0;
                    completed++;
                }

                k++;
                times[k] = time;
            }
        }

        if(found == 0)
        {
            order[k] = -1;

            time++;

            k++;
            times[k] = time;
        }
    }

    avgtat = (float)sumtat / n;
    avgwt = (float)sumwt / n;
    avgrt = (float)sumrt / n;

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i],
               resp[i]);
    }

    printf("\nAverage TAT = %.2f", avgtat);
    printf("\nAverage WT  = %.2f", avgwt);
    printf("\nAverage RT  = %.2f\n", avgrt);

    printf("\nGantt Chart:\n\n|");

    for(int i=0;i<k;i++)
    {
        if(order[i] == -1)
            printf(" IDLE |");
        else
            printf(" P%d |", order[i] + 1);
    }

    printf("\n");

    for(int i=0;i<=k;i++)
    {
        printf("%d\t", times[i]);
    }

    printf("\n");

    return 0;
}
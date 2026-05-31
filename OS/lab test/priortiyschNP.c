#include <stdio.h>

int main()
{
    int n, time = 0, completed = 0, highest, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], rt[n];
    int visited[n];

    int sumtat = 0, sumwt = 0, sumrt = 0;
    float avgtat, avgwt, avgrt;

    /* Gantt Chart */
    int order[2 * n];
    int times[2 * n + 1];
    int k = 0;

    times[0] = 0;//

    for(i = 0; i < n; i++)
    {
        printf("Enter AT, BT and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);

        visited[i] = 0;
    }

    while(completed < n)
    {
        highest = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && visited[i] == 0)
            {
                if(highest == -1 || pr[i] < pr[highest])
                    highest = i;
            }
        }

        if(highest == -1)
        {
            order[k] = -1;//
            time++;
            k++;//
            times[k] = time;//
            continue;
        }

        rt[highest] = time - at[highest];

        order[k] = highest;//

        time += bt[highest];

        ct[highest] = time;
        visited[highest] = 1;
        completed++;

        tat[highest] = ct[highest] - at[highest];
        wt[highest] = tat[highest] - bt[highest];

        sumtat += tat[highest];
        sumwt += wt[highest];
        sumrt += rt[highest];

        k++;//
        times[k] = time;//
    }

    avgtat = (float)sumtat / n;
    avgwt  = (float)sumwt / n;
    avgrt  = (float)sumrt / n;

    printf("\nP\tAT\tBT\tPRI\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               pr[i],
               ct[i],
               tat[i],
               wt[i],
               rt[i]);
    }

    printf("\nAverage TAT = %.2f", avgtat);
    printf("\nAverage WT  = %.2f", avgwt);
    printf("\nAverage RT  = %.2f\n", avgrt);

    printf("\nGantt Chart:\n\n|");

    for(i = 0; i < k; i++)
    {
        if(order[i] == -1)
            printf(" IDLE |");
        else
            printf(" P%d |", order[i] + 1);
    }

    printf("\n");

    for(i = 0; i <= k; i++)
    {
        printf("%d\t", times[i]);
    }

    printf("\n");

    return 0;
}
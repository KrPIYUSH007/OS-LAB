
//no need for this code
#include <stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int pr;
    int ct;
    int tat;
    int wt;
    int rt;
    int visited;
};

int main()
{
    int n, time = 0, completed = 0, highest, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    int sumtat = 0, sumwt = 0, sumrt = 0;
    float avgtat, avgwt, avgrt;

    /* Gantt Chart Arrays */
    int order[2 * n];
    int times[2 * n + 1];
    int k = 0;

    times[0] = 0;//

    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("Enter AT, BT and Priority for P%d: ", p[i].pid);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr);

        p[i].visited = 0;
    }

    while(completed < n)
    {
        highest = -1;

        for(i = 0; i < n; i++)
        {
            if(p[i].at <= time && p[i].visited == 0)
            {
                if(highest == -1 || p[i].pr < p[highest].pr)
                {
                    highest = i;
                }
            }
        }

        if(highest == -1)
        {
            order[k] = -1;   // IDLE
            time++;
            k++;//
            times[k] = time;//
            continue;
        }

        p[highest].rt = time - p[highest].at;

        order[k] = highest;//

        time += p[highest].bt;

        p[highest].ct = time;
        p[highest].visited = 1;
        completed++;

        p[highest].tat = p[highest].ct - p[highest].at;
        p[highest].wt = p[highest].tat - p[highest].bt;

        sumtat += p[highest].tat;
        sumwt += p[highest].wt;
        sumrt += p[highest].rt;

        k++;//3
        times[k] = time;//
    }

    avgtat = (float)sumtat / n;
    avgwt  = (float)sumwt / n;
    avgrt  = (float)sumrt / n;

    printf("\nP\tAT\tBT\tPRI\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].pr,
               p[i].ct,
               p[i].tat,
               p[i].wt,
               p[i].rt);
    }

    printf("\nAverage TAT = %.2f", avgtat);
    printf("\nAverage WT  = %.2f", avgwt);
    printf("\nAverage RT  = %.2f\n", avgrt);

    /* Gantt Chart */

    printf("\nGantt Chart:\n\n|");

    for(i = 0; i < k; i++)
    {
        if(order[i] == -1)
            printf(" IDLE |");
        else
            printf(" P%d |", p[order[i]].pid);
    }

    printf("\n");

    for(i = 0; i <= k; i++)
    {
        printf("%d\t", times[i]);
    }

    printf("\n");

    return 0;
}
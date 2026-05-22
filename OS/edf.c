#include <stdio.h>

struct Process
{
    int id;
    int burst;
    int deadline;
};

int main()
{
    int n;
    float util = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++)
    {
        p[i].id = i;

        printf("\nProcess %d:\n", i);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Deadline: ");
        scanf("%d", &p[i].deadline);

        util += (float)p[i].burst / p[i].deadline;
    }

    printf("\n===== Earliest Deadline First (EDF) =====\n");
    printf("CPU Utilization: %.2f\n", util);

    if(util <= 1)
        printf("Schedulable\n");
    else
        printf("NOT Schedulable\n");

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(p[i].deadline > p[j].deadline)
            {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nID\tBT\tDeadline\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", p[i].id, p[i].burst, p[i].deadline);
    }

    return 0;
}

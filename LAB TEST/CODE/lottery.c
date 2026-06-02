/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Process {
    int id, tickets;
};
void lottery(struct Process p[], int n, int time_slices) {
    int total_tickets = 0;
    for (int i = 0; i < n; i++) {
        total_tickets += p[i].tickets;
    }
    srand(time(0));
    for (int t = 0; t < time_slices; t++) {
        int winner = rand() % total_tickets;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += p[i].tickets;
            if (winner < sum) {
                printf("Time %d -> P%d\n", t, p[i].id);
                break;
            }
        }
    }
}
int main() {
    int n, time_slices;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter tickets for P%d: ", p[i].id);
        scanf("%d", &p[i].tickets);
    }
    printf("Enter number of time slices: ");
    scanf("%d", &time_slices);
    lottery(p, n, time_slices);
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void lottery(int id[], int tickets[],
             int n, int time_slices)
{
    int total_tickets = 0;

    for(int i = 0; i < n; i++)
    {
        total_tickets += tickets[i];
    }

    srand(time(0));

    int order[1000];
    int times[1001];

    times[0] = 0;

    for(int t = 0; t < time_slices; t++)
    {
        int winner = rand() % total_tickets;

        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum += tickets[i];

            if(winner < sum)
            {
                printf("Time %d -> P%d\n",
                       t,
                       id[i]);

                order[t] = i;
                break;
            }
        }

        times[t + 1] = t + 1;
    }

    printf("\nGantt Chart:\n\n|");

    for(int i = 0; i < time_slices; i++)
    {
        printf(" P%d |", id[order[i]]);
    }

    printf("\n");

    for(int i = 0; i <= time_slices; i++)
    {
        printf("%d\t", times[i]);
    }

    printf("\n");
}

int main()
{
    int n, time_slices;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int id[n];
    int tickets[n];

    for(int i = 0; i < n; i++)
    {
        id[i] = i + 1;

        printf("Enter tickets for P%d: ",
               id[i]);

        scanf("%d", &tickets[i]);
    }

    printf("Enter number of time slices: ");
    scanf("%d", &time_slices);

    lottery(id, tickets,
            n, time_slices);

    return 0;
}
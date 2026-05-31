#include <stdio.h>
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

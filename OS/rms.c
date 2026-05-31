#include <stdio.h>
struct Process {
    int id, period, burst, remaining;
};
void rms(struct Process p[], int n, int time_limit) {
    int time = 0;
    while (time < time_limit) {
        int highest = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0) {
                if (highest == -1 || p[i].period < p[highest].period) {
                    highest = i;
                }
            }
        }
        if (highest != -1) {
            printf("Time %d -> P%d\n", time, p[highest].id);
            p[highest].remaining--;
        } else {
            printf("Time %d -> Idle\n", time);
        }
        time++;
    }
}
int main() {
    int n, time_limit;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter period and burst time for P%d: ", p[i].id);
        scanf("%d %d", &p[i].period, &p[i].burst);
        p[i].remaining = p[i].burst;
    }
    printf("Enter total simulation time: ");
    scanf("%d", &time_limit);
    rms(p, n, time_limit);
    return 0;
}

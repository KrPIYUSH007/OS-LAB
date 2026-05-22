#include <stdio.h>

// FIFO Function
void FIFO(int pages[], int n, int f) {

    int frames[10];
    int i, j, k = 0;
    int found, pageFaults = 0;

    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\n========== FIFO ==========\n");

    for(i = 0; i < n; i++) {

        found = 0;

        // Check page hit
        for(j = 0; j < f; j++) {

            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // Page Fault
        if(found == 0) {

            frames[k] = pages[i];
            k = (k + 1) % f;

            pageFaults++;

            printf("Page %d -> ", pages[i]);

            for(j = 0; j < f; j++) {
                printf("%d ", frames[j]);
            }

            printf("(Fault)\n");
        }

        else {
            printf("Page %d -> Hit\n", pages[i]);
        }
    }

    printf("Total FIFO Page Faults = %d\n", pageFaults);
}


// LRU Function
void LRU(int pages[], int n, int f) {

    int frames[10], time[10];
    int i, j;
    int found, pageFaults = 0;
    int counter = 0;
    int min, pos;

    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\n========== LRU ==========\n");

    for(i = 0; i < n; i++) {

        found = 0;

        // Check page hit
        for(j = 0; j < f; j++) {

            if(frames[j] == pages[i]) {

                counter++;
                time[j] = counter;

                found = 1;
                break;
            }
        }

        // Page Fault
        if(found == 0) {

            min = time[0];
            pos = 0;

            // Find least recently used
            for(j = 1; j < f; j++) {

                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            counter++;

            frames[pos] = pages[i];
            time[pos] = counter;

            pageFaults++;

            printf("Page %d -> ", pages[i]);

            for(j = 0; j < f; j++) {
                printf("%d ", frames[j]);
            }

            printf("(Fault)\n");
        }

        else {
            printf("Page %d -> Hit\n", pages[i]);
        }
    }

    printf("Total LRU Page Faults = %d\n", pageFaults);
}


// Optimal Function
void Optimal(int pages[], int n, int f) {

    int frames[10];
    int i, j, k;
    int found, pageFaults = 0;
    int farthest, pos;

    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\n========== OPTIMAL ==========\n");

    for(i = 0; i < n; i++) {

        found = 0;

        // Check page hit
        for(j = 0; j < f; j++) {

            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // Page Fault
        if(found == 0) {

            farthest = -1;
            pos = -1;

            // Find optimal page
            for(j = 0; j < f; j++) {

                int nextUse = -1;

                for(k = i + 1; k < n; k++) {

                    if(frames[j] == pages[k]) {
                        nextUse = k;
                        break;
                    }
                }

                // If never used again
                if(nextUse == -1) {
                    pos = j;
                    break;
                }

                // Used farthest in future
                if(nextUse > farthest) {
                    farthest = nextUse;
                    pos = j;
                }
            }

            frames[pos] = pages[i];

            pageFaults++;

            printf("Page %d -> ", pages[i]);

            for(j = 0; j < f; j++) {
                printf("%d ", frames[j]);
            }

            printf("(Fault)\n");
        }

        else {
            printf("Page %d -> Hit\n", pages[i]);
        }
    }

    printf("Total Optimal Page Faults = %d\n", pageFaults);
}


// Main Function
int main() {

    int pages[50];
    int n, f, i;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Execute all algorithms
    FIFO(pages, n, f);

    LRU(pages, n, f);

    Optimal(pages, n, f);

    return 0;
}

#include <stdio.h>

int main() {
    int n, W, i, j;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int v[n], w[n];
    float r[n], total = 0;

    // Input
    for(i = 0; i < n; i++) {
        scanf("%d %d", &v[i], &w[i]);
        r[i] = (float)v[i] / w[i];
    }

    printf("Enter capacity: ");
    scanf("%d", &W);

    // Sort by ratio (descending)
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(r[j] < r[j + 1]) {
                float tr = r[j]; r[j] = r[j + 1]; r[j + 1] = tr;
                int tv = v[j]; v[j] = v[j + 1]; v[j + 1] = tv;
                int tw = w[j]; w[j] = w[j + 1]; w[j + 1] = tw;
            }
        }
    }

    // Knapsack logic
    for(i = 0; i < n; i++) {
        if(W >= w[i]) {
            total += v[i];
            W -= w[i];
        } else {
            total += v[i] * ((float)W / w[i]);
            break;
        }
    }

    printf("Max value = %.2f", total);
    return 0;
}
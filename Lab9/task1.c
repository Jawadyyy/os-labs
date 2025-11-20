#include <stdio.h>

int main() {

    int n, i, j;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], pid[n];

    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {

                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("\nGantt Chart:\n|");
    for (i = 0; i < n; i++) {
        printf("  P%d  |", pid[i]);
    }

    printf("\n0");
    int time = 0;
    for (i = 0; i < n; i++) {
        time += bt[i];
        printf("     %d", time);
    }

    return 0;
}

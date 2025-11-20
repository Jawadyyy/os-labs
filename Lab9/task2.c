#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n], completed[n];
    int i, time = 0, completedCount = 0;
    int prevProcess = -1;
    int contextSwitches = 0;

    int timeline[1000]; 
    int timelineIndex = 0;

    for (i = 0; i < n; i++) {
        printf("Enter AT and BT of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        completed[i] = 0;
    }

    while (completedCount < n) {
        int idx = -1, minRT = 99999;

        for (i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time && rt[i] < minRT && rt[i] > 0) {
                minRT = rt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            timeline[timelineIndex++] = -1;
            time++;
            continue;
        }

        if (prevProcess != idx && prevProcess != -1)
            contextSwitches++;

        timeline[timelineIndex++] = idx;

        rt[idx]--;
        time++;
        prevProcess = idx;

        if (rt[idx] == 0) {
            completed[idx] = 1;
            completedCount++;

            int finishTime = time;
            tat[idx] = finishTime - at[idx];
            wt[idx] = tat[idx] - bt[idx];
        }
    }

    printf("\nP\tAT\tBT\tWT\tTAT\n");
    float totalWT = 0, totalTAT = 0;
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT/n);
    printf("Average Turnaround Time: %.2f\n", totalTAT/n);
    printf("Context Switches: %d\n", contextSwitches);

    printf("\nGantt Chart:\n");

    printf(" ");
    for (i = 0; i < timelineIndex; i++) printf("------");
    printf("\n|");

    for (i = 0; i < timelineIndex; i++) {
        if (timeline[i] == -1)
            printf(" IDLE |");
        else
            printf(" P%d  |", timeline[i] + 1);
    }

    printf("\n ");
    for (i = 0; i < timelineIndex; i++) printf("------");

    printf("\n0");
    for (i = 1; i <= timelineIndex; i++) {
        printf("     %d", i);
    }

    printf("\n");

    return 0;
}

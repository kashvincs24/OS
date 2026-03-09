#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int wt;
    int tat;
    int completed;
};

int main() {
    int n, i, time = 0, completed = 0, min_bt, shortest;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].completed = 0;
    }

    float total_wt = 0, total_tat = 0;

    while(completed < n) {
        min_bt = 9999;
        shortest = -1;

        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].completed == 0) {
                if(p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    shortest = i;
                }
            }
        }

        if(shortest == -1) {
            time++;
        } else {
            p[shortest].wt = time - p[shortest].at;
            time += p[shortest].bt;
            p[shortest].tat = p[shortest].wt + p[shortest].bt;
            p[shortest].completed = 1;

            total_wt += p[shortest].wt;
            total_tat += p[shortest].tat;
            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

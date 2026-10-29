
#include <stdio.h>

#define MAX 50

typedef struct {
    int pid;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
} Process;

void calculateTimes(Process p[], int n, const char *title) {
    int totalWaiting = 0;
    int totalTurnaround = 0;

    p[0].waitingTime = 0;

    for (int i = 1; i < n; i++) {
        p[i].waitingTime =
            p[i - 1].waitingTime + p[i - 1].burstTime;
    }

    printf("\n===== %s =====\n", title);
    printf("PID\tBurst\tPriority\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        p[i].turnaroundTime =
            p[i].waitingTime + p[i].burstTime;

        totalWaiting += p[i].waitingTime;
        totalTurnaround += p[i].turnaroundTime;

        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid,
               p[i].burstTime,
               p[i].priority,
               p[i].waitingTime,
               p[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %.2f\n",
           (float)totalWaiting / n);

    printf("Average Turnaround Time: %.2f\n",
           (float)totalTurnaround / n);
}

void fcfsScheduling(Process p[], int n) {
    Process temp[MAX];

    for (int i = 0; i < n; i++)
        temp[i] = p[i];

    calculateTimes(temp, n, "FCFS Scheduling");
}

void priorityScheduling(Process p[], int n) {
    Process temp[MAX], key;

    for (int i = 0; i < n; i++)
        temp[i] = p[i];

    // Smaller number means higher priority.
    // Equal priorities retain their input order.
    for (int i = 1; i < n; i++) {
        key = temp[i];
        int j = i - 1;

        while (j >= 0 && temp[j].priority > key.priority) {
            temp[j + 1] = temp[j];
            j--;
        }

        temp[j + 1] = key;
    }

    calculateTimes(temp, n, "Priority Scheduling");
}

int main(void) {
    Process p[MAX];
    int n, choice;

    printf("CPU PROCESS SCHEDULING SIMULATOR\n");
    printf("================================\n");

    printf("Enter number of processes (1-%d): ", MAX);

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of processes!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nProcess P%d\n", p[i].pid);

        printf("Enter burst time: ");
        if (scanf("%d", &p[i].burstTime) != 1 ||
            p[i].burstTime <= 0) {
            printf("Burst time must be positive.\n");
            return 1;
        }

        printf("Enter priority (smaller = higher): ");
        if (scanf("%d", &p[i].priority) != 1 ||
            p[i].priority < 0) {
            printf("Invalid priority!\n");
            return 1;
        }
    }

    do {
        printf("\n========== MENU ==========\n");
        printf("1. FCFS Scheduling\n");
        printf("2. Priority Scheduling\n");
        printf("3. Compare Both Algorithms\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
            case 1:
                fcfsScheduling(p, n);
                break;

            case 2:
                priorityScheduling(p, n);
                break;

            case 3:
                fcfsScheduling(p, n);
                priorityScheduling(p, n);
                break;

            case 4:
                printf("Exiting simulator. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
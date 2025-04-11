#include <stdio.h>

void sortJobs(int n, int profit[], int deadline[], int jobId[]) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                temp = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = temp;

                temp = jobId[j];
                jobId[j] = jobId[j + 1];
                jobId[j + 1] = temp;
            }
        }
    }
}

int findMaxDeadline(int n, int deadline[]) {
    int max = deadline[0], i;
    for (i = 1; i < n; i++) {
        if (deadline[i] > max)
            max = deadline[i];
    }
    return max;
}

void jobSequencing(int n, int profit[], int deadline[], int jobId[]) {
    sortJobs(n, profit, deadline, jobId);
    int maxDeadline = findMaxDeadline(n, deadline);
    int schedule[maxDeadline], i, j, totalProfit = 0;

    for (i = 0; i < maxDeadline; i++) {
        schedule[i] = -1;
    }

    for (i = 0; i < n; i++) {
        for (j = deadline[i] - 1; j >= 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobId[i];
                totalProfit += profit[i];
                break;
            }
        }
    }

    printf("\nJob Sequence: ");
    for (i = 0; i < maxDeadline; i++) {
        if (schedule[i] != -1)
            printf("%d -> ", schedule[i]);
    }
    printf("\b\b \n");

    printf("Max Profit = %d\n", totalProfit);
}

int main() {
    int n, i;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    int profit[n], deadline[n], jobId[n];
    printf("Enter the profit and deadline of each job:\n");
    for (i = 0; i < n; i++) {
        jobId[i] = i + 1;
        scanf("%d %d", &profit[i], &deadline[i]);
    }

    jobSequencing(n, profit, deadline, jobId);
    return 0;
}

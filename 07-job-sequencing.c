#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
typedef struct {
    int id;        // Job ID
    int deadline;  // Deadline for the job
    int profit;    // Profit associated with the job
} Job;

// Function to compare two jobs based on their profit
int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

// Function to perform job sequencing and print the scheduled jobs
void jobSequencing(Job arr[], int n) {
    // Sort the jobs based on their profit (in non-increasing order)
    qsort(arr, n, sizeof(Job), compare);

    // Find the maximum deadline among the jobs
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > maxDeadline) {
            maxDeadline = arr[i].deadline;
        }
    }

    // Array to store the time slots
    int slots[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        slots[i] = -1; // -1 indicates slot is empty
    }

    // Schedule the jobs
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = arr[i].id;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    // Print the scheduled jobs
    printf("Scheduled Jobs:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (slots[i] != -1) {
            printf("Job %d (Profit: %d)\n", slots[i], arr[slots[i] - 1].profit);
        }
    }
    printf("Total Profit: %d\n", totalProfit);
}

int main() {
    // Example jobs
    Job arr[] = { {1, 4, 70}, {2, 2, 60}, {3, 4, 50}, {4, 3, 40}, {5, 1, 30} };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform job sequencing
    jobSequencing(arr, n);

    return 0;
}

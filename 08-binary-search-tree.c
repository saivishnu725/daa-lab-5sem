#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of probabilities from index i to j
float sum(float freq[], int i, int j) {
    float s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

// Function to calculate the minimum cost of searching keys from i to j
float optimalBST(float keys[], float freq[], int n) {
    // Create a 2D array to store the minimum cost
    float cost[n][n];

    // Initialize cost array with 0
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // Calculate the minimum cost for different subarrays
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = (float) INT_MAX;
            for (int r = i; r <= j; r++) {
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) +
                          sum(freq, i, j);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    // Return the minimum cost of searching keys from 0 to n-1
    return cost[0][n - 1];
}

int main() {
    float keys[] = {10, 12, 20};
    float freq[] = {0.34, 0.33, 0.33};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("The cost of the optimal BST is %.2f\n", optimalBST(keys, freq, n));

    return 0;
}

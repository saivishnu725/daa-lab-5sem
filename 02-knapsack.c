#include<stdio.h>

// Function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 knapsack problem using dynamic programming
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W]; // Return the maximum value that can be put in a knapsack of capacity W
}

int main() {
		// accept values from user
		// // // // // // // // // //						start
		/* int W, n; */
		
		/* printf("Enter the capacity: "); */
		/* scanf("%d", &W); */
		/* printf("Enter the number of items: "); */
		/* scanf("%d", &n); */

		/* int wt[n], val[n]; */
		
		/* printf("Enter %d weights: ", n); */
		/* for(int i = 0; i < n; i++) */
		/* 		scanf("%d", &wt[i]); */
		/* printf("Enter %d values: ", n); */
		/* for(int i = 0; i < n; i++) */
		/* 		scanf("%d", &val[i]); */
	 // // // // // // // // //								end 

		// predefined values
		// // // // // // // // //							start
    int val[] = {100, 60, 120};
    int wt[] = {5, 10, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    // // // // // // // // //							end 
		printf("Maximum value that can be obtained is %d\n", knapSack(W, wt, val, n));
    
		return 0;
}

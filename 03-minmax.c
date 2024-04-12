#include<stdio.h>

int min, max;

void minmax(int a[], int i, int j) {
		int mid, temp_min, temp_max;
		/* if i and j are equal, both min and max are the only exisitng element */
		if(i == j)
				min = max = a[i];
		/* if i is one less than j, only two elements exist --> compare directly and save them */
		else if(i == j - 1){
				min = (a[i] <= a[j]) ? a[i] : a[j];
				max = (a[i] >= a[j]) ? a[i] : a[j];
		}
		/* if there are more than two elements, divide it in half and repeat the process. */
		else {
				/* divide in half */
				mid = (i + j) / 2;
				/* call the function on the first half */
				minmax(a, i, mid);
				/* save the values of the first half in the temp variables */
				temp_min = min;
				temp_max = max;
				/* call the function on the second half */
				minmax(a, mid + 1, j);
				/* compare temp and current min & max to find ultimate min & max values respectively */
				if(temp_min < min)
						min = temp_min;
				if(temp_max > max)
						max = temp_max;
		}
}

int main() {
		int n;
		printf("Enter the number of elements: ");
		scanf("%d", &n);
		int a[n];
		printf("Enter %d elements: ", n);
		for(int i = 0; i < n; i++)
				scanf("%d", &a[i]);
		minmax(a, 0, n - 1);
		printf("Minimum value: %d\n", min);
		printf("Maximum value: %d\n", max);


}

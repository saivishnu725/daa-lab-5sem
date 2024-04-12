#include<stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int low, int high) {
	int i, pivot;
	pivot = a[high];
	i = low - 1;

	for(int j = low; j <= high; j++) {
		if(a[j] < pivot) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[high]);
	return (i + 1);
}

void sort(int a[], int low, int high) {
	if(low < high) {
		int p = partition(a, low, high);
		sort(a, low, p - 1);
		sort(a, p + 1, high);
	}
}

void display(int a[], int n) {
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	int n = 5;
	int a[] = {5, 1, 7, 2, 4};
	printf("Unsorted array: ");
	display(a, n);
	sort(a, 0, n - 1);
	printf("Sorted array: \t");
	display(a, n);
}

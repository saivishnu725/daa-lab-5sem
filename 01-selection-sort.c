#include<stdio.h>

void swap(int *a, int *b) {
		int temp = *a;
		*a = *b;
		*b = temp;
}

void display(int a[], int n) {
		for(int i = 0; i < n; i++)
				printf("%d ", a[i]);
		printf("\n");
}

void sort(int a[], int n) {
		int min;
		for(int i = 0; i < n-1; i++) {
				min = i;
				for(int j = i+1; j < n; j++) {
						if(a[j] < a[min])
								min = j;
				}
				if(min != i)
						swap(&a[min], &a[i]);
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
		sort(a, n);
		printf("Sorted array: ");
		display(a, n);
		return 0;
}

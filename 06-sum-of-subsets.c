#include <stdio.h>
#include <stdlib.h>

void display(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%*d", 5, A[i]);
    printf("\n");
}

void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum) {
    if (target_sum == sum) {
        display(t, t_size);
        subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        return;
    } else {
        for (int i = ite; i < s_size; i++) {
            t[t_size] = s[i];
            subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
        }
    }
}

void generateSubsets(int s[], int size, int target_sum) {
    int* tuplet_vector = (int*)malloc(size * sizeof(int));
    subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
    free(tuplet_vector);
}

int main() {
    int set[] = {1, 2, 3, 4};
    int size = sizeof(set) / sizeof(set[0]);
    
    printf("The set: ");
    display(set, size);
    
    int given_sum = 7;
    printf("Given sum: %d\n", given_sum);
    
    printf("The subsets:\n");
    generateSubsets(set, size, given_sum);
    
    return 0;
}

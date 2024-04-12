#include<stdio.h>

#define MAX_VERTICES 10

int main() {
	int adj[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
	int n; // number of vertices
	int max_edges, origin, destin, i, j;

	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	
	max_edges = n * (n - 1) / 2;
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			adj[i][j] = 0;
	
	for(i = 1; i <= max_edges; i++) {
		printf("Enter edge [ %d ] ( -1 -1 to quit ): ", i);
		scanf("%d %d", &origin, &destin);
		if((origin == -1) && (destin == -1))
			break;
		if(origin >= n || destin >= n || origin < 0 || destin < 0 ) {
			printf("Invalid Vertex!\n");
			i--;
		} else
			adj[destin][origin] = 1;
	}

	printf("\nAdjacency matrix: \n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			printf("%4d", adj[i][j]);
		printf("\n");
	}
	
	return 0;
}

#include <stdio.h>

int V;

void print(int reach[][V]);

void transitiveClosure(int graph[][V]) {
    int reach[V][V];
    int i, j, k;


    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            reach[i][j] = graph[i][j];
        }
    }


    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (reach[i][j]||reach[i][k] && reach[k][j])
                    reach[i][j] = 1;
            }
        }
    }

    print(reach);
}

void print(int reach[][V]) {
    printf("Transitive closure matrix is:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

void main() {
   printf("Enter the number of vertices:");
   scanf("%d",&V);
   int graph[V][V];
   printf("Enter the adjacency matrix\n");
   for(int i=0;i<V;i++)
   {
       for(int j=0;j<V;j++)
       {
           scanf("%d",&graph[i][j]);
       }
   }

    transitiveClosure(graph);
}

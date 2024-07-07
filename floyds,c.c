#include <stdio.h>
#define INF 999

int V;

void print(int reach[][V]);
int min(int a,int b)
{
    return (a<b)?a:b;
}

void shortP(int graph[][V]) {
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
                reach[i][j]=min(reach[i][j],reach[i][k]+reach[k][j]);
            }
        }
    }

    print(reach);
}

void print(int reach[][V]) {
    printf("Shortest path matrix is:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
                if(reach[i][j]==INF)
                {
                    printf("oo");
                }

                else
                {printf("%d ", reach[i][j]);}
        }
        printf("\n");
    }
}

void main() {
   printf("Enter the number of vertices:");
   scanf("%d",&V);
   int graph[V][V];
   printf("Enter the weight matrix\n");
   for(int i=0;i<V;i++)
   {
       for(int j=0;j<V;j++)
       {
           scanf("%d",&graph[i][j]);
       }
   }

    shortP(graph);
}

#include<stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
void calc(int it,int wt,int w[it],int v[it])
{
    int mat[it+1][wt+1];
    for(int i=0;i<it+1;i++)
    {
        for(int j=0;j<wt+1;j++)
        {
            if(i==0||j==0)
            {
                mat[i][j]=0;
            }
            else
            {
                if(j-w[i-1]>=0)
                {
                    mat[i][j]=max(mat[i-1][j],(v[i-1]+mat[i-1][j-w[i-1]]));
                }
                else
                {
                    mat[i][j]=mat[i-1][j];
                }
            }
        }
    }
    for(int i=0;i<it+1;i++)
    {
        for(int j=0;j<wt+1;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    printf("Maximum value in knapsack: %d\n", mat[it][wt]);
    int res = mat[it][wt];
    int W = wt;
    printf("Items included in the knapsack:\n");
    for (int i = it; i > 0 && res > 0; i--)
        { if (res == mat[i-1][W])
        continue;
        else {
            printf("Item %d (weight: %d, value: %d)\n", i, w[i-1], v[i-1]);
            res = res - v[i-1];
            W = W- w[i-1];
        }
    }

}
void main()
{
    int it,wt;
    printf("Enter the number of items:");
    scanf("%d",&it);
    printf("Enter the weight capacity:");
    scanf("%d",&wt);
    int w[it],v[it];
    printf("Enter the weight and value of each item:\n");
    for(int i=0;i<it;i++)
    {
        printf("%d.",i+1);
        scanf("%d%d",&w[i],&v[i]);
    }
    calc(it,wt,w,v);
}

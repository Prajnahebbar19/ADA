#include<stdio.h>
void main()
{
    int n,f=1,c=0;
    int m[n];
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    int mat[n][n];
    printf("Enter the elements row-wise:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        m[i]=0;
    }
    while(c<n)
    {
        for(int i=0;i<n;i++)
        {
            f=1;
            if(m[i]==1)
                {
                    continue;
                }
            for(int j=0;j<n;j++)
            {

                if(mat[j][i]!=0)
                {
                    f=0;continue;
                }
            }
            if(f)
            {
                m[i]=1;
                printf("%d->",i+1);
                for(int k=0;k<n;k++)
                {
                    mat[i][k]=0;
                }
                 c++;

            }

        }
    }
}

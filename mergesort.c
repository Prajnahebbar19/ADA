#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int arr[],int low,int mid,int high)
{
    int i,j,h,b[high-low+1];
    i=h=low;
    j=mid+1;
    while(h<=mid&&j<=high)
    {
        if(arr[h]<=arr[j])
        {
            b[i]=arr[h];
            h++;
        }
        else
        {
            b[i]=arr[j];
            j++;
        }
        i++;
    }
    if(h<=mid)
    {
        for(int k=h;k<mid;k++)
        {
            b[i]=arr[k];
            i++;
        }
    }
   if(j<=high)
    {
       for(int k=j;k<high;k++)
       {
           b[i]=arr[k];
           i++;
       }
    }
    for(int k=0,j=low;k<=high;k++,j++)
    {
        arr[k]=b[k];
    }
}
void mergeSort(int arr[],int low,int high)
{   int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void main()
{
    clock_t start,end;
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int arr[n];
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    start=clock();
    mergeSort(arr,0,n-1);
    end=clock();
    printf("Time taken:%f",(double)(end - start) / CLOCKS_PER_SEC);
}

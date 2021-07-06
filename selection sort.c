#include<stdio.h>
int main()
{
    int min,n,i,j,temp;
    printf("entre the range of array");
    scanf("%d",&n);
    int arr[20];
    for (i=0;i<n;i++)
    {
        printf("entre the value");
        scanf("%d",&arr[i]);
    }
    for (i=0;i<n;i++)
    {
        min=arr[i];
        for(j=i;j<n;j++)
        {
            if (arr[j]<min)
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
                min=arr[i];
            }
        }
    }
    for (i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

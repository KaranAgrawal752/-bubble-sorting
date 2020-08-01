#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j,temp;
    printf("enter size of array");
    scanf("%d",&n);
    int a[n];
    printf("enter elements of array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("sorted arry\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
}

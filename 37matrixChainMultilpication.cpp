#include<bits/stdc++.h>
using namespace std;
int MCM(int * a, int n)
{
    int m[n+1][n+1]={0},j,min, s[n+1][n+1]={0};
    for(int d=1;d<=n-1;d++)
    for(int i=1;i<=n-d;i++)
    {
        j=i+d;
        min=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int q=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
            if(q<min) min=q, s[i][j]=k;
        }
        m[i][j]=min;
    }
    for(int i=1;i<=n;i++) 
    {
        for(j=1;j<=n;j++) cout<<m[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=1;i<=n;i++) 
    {
        for(j=1;j<=n;j++) cout<<s[i][j]<<" ";
        cout<<"\n";
    }
    return m[1][n];
}
int main()
{
    int n, cost;
    cout<<"Enter no. of Matrix ";
    cin>>n;
    cout<<"Enter dimension in multiplication order :\n";
    int a[n+1];
    for(int i=0;i<=n;i++) cin>>a[i];
    cost=MCM(a, n);
    cout<<"Minimum cost of multiplication is "<<cost;
    return 0;
}
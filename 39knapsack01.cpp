/*#include<bits/stdc++.h>
using namespace std;
int t[4][6]={0};
int knapsack(int *p,int *w,int n,int m)
{
    if(n==0 or m==0) return 0;
    if(t[n][m]!=0) return t[n][m];
    if(w[n-1]>m) return t[n][m]=knapsack(p,w,n-1,m);
    int a,b;
    a=knapsack(p,w,n-1,m-w[n-1])+p[n-1];
    b=knapsack(p,w,n-1,m);
    return t[n][m]=max(a,b);
}
main()
{
    int p[]={3,4,1};
    int w[]={1,2,3}, m=5;
    int n=sizeof(p)/sizeof(p[0]);
    int ans=knapsack(p,w,n,m);
    cout<<ans<<"\n";
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<6;j++)
            cout<<t[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int knapsack(int *p,int *w,int n,int m)
{
    int t[n+1][m+1]={0};
    for(int i=0;i<=n;i++) t[i][0]=0;
    for(int i=0;i<=m;i++) t[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(w[i-1]<=j)
                t[i][j]=max(p[i-1]+t[i-1][j-w[i-1]],t[i-1][j]);
            else t[i][j]=t[i-1][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<t[i][j]<<" ";
        cout<<"\n";
    }
    return t[n][m];
}
main()
{
    int p[]={3,4,1};
    int w[]={1,2,3}, m=5;
    int n=sizeof(p)/sizeof(p[0]);
    int ans=knapsack(p,w,n,m);
    cout<<ans<<"\n";
    return 0;
}
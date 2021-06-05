/*#include<bits/stdc++.h>
using namespace std;
int wght(int *a, int i,int j)
{
    int s=0;
    for(int k=i;k<=j;k++)
        s+=a[k];
    return s;
}
int t[10][10]={0};
int  obst(int * a,int i, int j)
{
    int s=j-i,u=i;
    if(i==j) return t[s][u]=a[i];
    if(t[s][u] !=0) return t[s][u];
    int min=INT_MAX;
    for(int k=i;k<=j;k++)
    {
        int q;
        if(k==i)
            q=obst(a,k+1,j)+wght(a,i,j) ;
        else if(k==j)
            q=obst(a,i,k-1)+wght(a,i,j);
        else
            q=obst(a,k+1,j)+obst(a,i,k-1)+wght(a,i,j);
        if(q<min) min=q;
    }
    return t[s][u]=min;
}
int main()
{
    int n;
    cout<<"Enter no. of nodes: ";
    cin>>n;
    int  a[n];
    vector<vector<int>> b;
    cout<<"node weight\tfrequency\n";
    for(int i=0;i<n;i++) 
    {
        int c, d;
        vector<int> v;
        cin>>c>>d;
        v.push_back(c);
        v.push_back(d);
        b.push_back(v);
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++) a[i]=b[i][1];
    int ans=obst(a,0,n-1);
    for(int i=0;i<10;i++) 
    {
        for(int j=0;j<10;j++) cout<<t[i][j]<<"\t";
        cout<<"\n\n";
    }
    cout<<ans;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int wght(int *a, int i,int j)
{
    int s=0;
    for(int k=i;k<=j;k++)
        s+=a[k];
    return s;
}
int  obst(int * a,int n)
{
    int t[n][n]={0}, r[n][n]={0};
    for(int j=0;j<n;j++) t[0][j]=a[j], r[0][j]=j;
    for(int i=1;i<n;i++)
    {
        for(int j=n-i-1;j>=0;j--)
        {
            int min=INT_MAX;
            for(int k=j;k<=j+i;k++)
            {
                int q;
                if(k==j)
                    q=t[i-1][j+1]+wght(a,j,j+i) ;
                else if(k==j+i)
                    q=t[i-1][j]+wght(a,j,j+i);
                else
                    q=t[j+i-k-1][k+1]+t[k-1-j][j]+wght(a,j,j+i);
               if(q<min) min=q;
            }
            t[i][j]=min;
        }
    }
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<n;j++) cout<<t[i][j]<<"\t";
        cout<<"\n\n";
    }
    return t[n-1][0];
}
int main()
{
    int n;
    cout<<"Enter no. of nodes: ";
    cin>>n;
    int  a[n];
    vector<vector<int>> b;
    cout<<"node weight\tfrequency\n";
    for(int i=0;i<n;i++) 
    {
        int c, d;
        vector<int> v;
        cin>>c>>d;
        v.push_back(c);
        v.push_back(d);
        b.push_back(v);
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++) a[i]=b[i][1];
    int ans=obst(a,n);
    cout<<ans;
    return 0;
}
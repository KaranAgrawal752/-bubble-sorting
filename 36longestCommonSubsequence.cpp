#include<bits/stdc++.h>
using namespace std;
void LCS(string  x, string y,int m,int n)
{
    int t[m+1][n+1], flag=0;
    char d[m+1][n+1];
    string s="";
    for(int i=0;i<=m;i++) t[i][0]=0, d[i][0]=0;
    for(int j=0;j<=n;j++) t[0][j]=0, d[0][j]=0;
    for(int i=1;i<m+1;i++) 
    for(int j=1;j<n+1;j++)
    {
        if(x[i-1]==y[j-1]) 
        {
            flag=1;
            t[i][j]=1+t[i-1][j-1];
            d[i][j]=char(68);
        }
        else
        {
            flag=0;
            if(t[i][j-1]>t[i-1][j])
            {
                t[i][j]=t[i][j-1];
                d[i][j]=char(76);
            }
            else
            {
                t[i][j]=t[i-1][j];
                d[i][j]=char(85);
            }
        }
    }
    int i=m, j=n;
    while(i>0 and j>0)
    {
        if(x[i-1]==y[j-1])
        {
            s.push_back(x[i-1]);
            i--, j--;
        }
        else
        {
            if(t[i][j-1]>t[i-1][j]) j--;
            else i--;
        }
    }
    reverse(s.begin(),s.end());
    cout<<"Longest Common Subsequense is : "<<s<<"\n";
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<t[i][j]<<" ";
        cout<<"\n";
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<d[i][j]<<" ";
        cout<<"\n";
    }
}
int main()
{
    int m,n,len;
    cout<<"enter  strings:";
    string x, y;
    cin>>x>>y;
    m=x.length(); n=y.length();
    LCS(x,y,m,n);
    return 0;
}
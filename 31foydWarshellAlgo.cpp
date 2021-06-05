#include<bits/stdc++.h>
using namespace std;
 int main()
{
    int v, e;
    cout<<"Enter no.of vertex  and edges\n";
    cin>>v>>e;
    cout<<"Vertex asigned as 0 to n-1 \n";
    int graph[v][v]={1};
    graph[0][0]=0;
    for(int i=0;i<v;i++) for(int j=0;j<v;j++) if((i !=j)) graph[i][j]=INT_MAX;
    cout<<"EdgeWeigt vertex1 vertex2\n";
    for(int i=0;i<e;i++)
    {
        int w,x,y;
        cin>>w>>x>>y;
        graph[x][y]=w;
    }
    for(int i=0;i<v;i++)
    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if( graph[i][k] != INT_MAX && graph[k][j]!=INT_MAX  && graph[i][j]>(graph[i][k]+graph[k][j]))
                    graph[i][j]=graph[i][k]+graph[k][j];
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}
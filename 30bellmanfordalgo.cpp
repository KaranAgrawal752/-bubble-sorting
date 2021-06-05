#include<bits/stdc++.h>
using namespace std;
 int main()
{
    int v, e;
    cout<<"Enter no.of vertex  and edges\n";
    cin>>v>>e;
    cout<<"Vertex asigned as 0 to n-1 \n";
    int  dis[v],k;
    vector<vector<int>> edge;
    cout<<"EdgeWeigt vertex1 vertex2\n";
    for(int i=0;i<e;i++)
    {
        int w,x,y;
        cin>>w>>x>>y;
        vector<int> v1;
        v1.push_back(w);
        v1.push_back(x);
        v1.push_back(y);
        edge.push_back(v1);
    }
    for(int i=0;i<v;i++) dis[i]=INT_MAX;
    cout<<"Enter source vertex no.: ";
    cin>>k;
    dis[k]=0;
    for(int l=0;l<v-1;l++)
    {
        for(int i=0;i<e;i++)
        {
            int u,j,w;
            u=edge[i][1], j=edge[i][2], w=edge[i][0];
            if( (dis[u]+w)<dis[j] )
                 dis[j]=dis[u]+w;
        }
        
    }
    for(int i=0;i<v;i++)
    cout<<dis[i]<<" ";
}
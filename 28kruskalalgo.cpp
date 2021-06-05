#include<bits/stdc++.h>
using namespace std;
int find(int x, int parent[])
{
    if(x == parent[x])
        return x;
    else{
        return find(parent[x], parent);
    }
}
 int main()
{
    int v, e;
    cout<<"Enter no.of vertex  and edges\n";
    cin>>v>>e;
    cout<<"Vertex asigned as 0 to n-1 \n";
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
        v1.push_back(0);
        edge.push_back(v1);
    }
    sort(edge.begin(), edge.end());
    bool mstset[v]={false};
    int cnt=0, parent[v];
    for(int i=0;i< v;i++) parent[i]=i;
    for(int i=0;i<e;i++)
    {
        int j=edge[i][1], k=edge[i][2];
        if(mstset[j] ==false || mstset[k]==false )
        {
            cnt++;
            if(mstset[k] == false && mstset[j]==false)  parent[k]=j;
            else if(mstset[k]==false) 
            {
                parent[k]=j;
            }
            else{
                parent[j]=k;
            }
            mstset[j]=true;
            mstset[k]=true;
            edge[i][3]=1;
        }
        else
        {
            int h=find(j,parent), l=find(k,parent);
            if(h!= l)
            {
                cnt++;
                parent[l]=h;
                edge[i][3]=1;
            }
        }
        if(cnt==v-1) break;

    }
    cout<<"Edge\tWeight\n";
    for(int i=0;i<e;i++)
    {
        if(edge[i][3]==1)
            cout<<edge[i][1]<<"-"<<edge[i][2]<<"\t"<<edge[i][0]<<"\n";
    }
}
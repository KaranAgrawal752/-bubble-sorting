/*#include<bits/stdc++.h>
using namespace std;
 int main()
{
    int v, e;
    cout<<"Enter no.of vertex  and edges\n";
    cin>>v>>e;
    cout<<"Vertex asigned as 0 to n-1 \n";
    int graph[v][v], dis[v],k;
    for(int i=0;i<v;i++) for(int j=0;j<v;j++) graph[i][j]=-1;
    cout<<"EdgeWeigt vertex1 vertex2\n";
    for(int i=0;i<e;i++)
    {
        int w,x,y;
        cin>>w>>x>>y;
        graph[x][y]=w;
    }
    for(int i=0;i<v;i++) dis[i]=INT_MAX;
    cout<<"Enter source vertex no.: ";
    cin>>k;
    dis[k]=0;
    int u=k;
    int mstset[v]={false};
    mstset[u]=true;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(graph[u][j]!=-1 && (dis[u]+graph[u][j])<dis[j] )
                dis[j]=dis[u]+graph[u][j];
        }
        int min=INT_MAX;
        for(int j=0;j<v;j++)
        {
            if(mstset[j]==false && dis[j]<min)
            {
                u=j, min=dis[j];
            }
        }
        mstset[u]=true;
    }
    for(int i=0;i<v;i++)
    cout<<dis[i]<<" ";
}*/
#include<bits/stdc++.h>
using namespace std;
 struct data
 {
     int parent, key,vertex;
 };
 struct node
 {
     int vertex, weight, f;
     struct node *next;
 };
  void swap(struct data  heap[],int k, int m,int n)
 {
     struct data abc;
     abc.parent=(heap[m]).parent;
     abc.key=(heap[m]).key;
     abc.vertex=(heap[m]).vertex;
     heap[m].parent=(heap[n]).parent;
     (heap[m]).key=(heap[n]).key;
     (heap[m]).vertex=(heap[n]).vertex;
     (heap[n]).parent=abc.parent;
     (heap[n]).key=abc.key;
     (*(heap+n)).vertex=abc.vertex;
 }
 void pheapify(struct data heap[],int n,int i,int * position,int v)
 {
     int l=2*i+1, r=2*i+2, large=i;
    if((heap[l]).key<(heap[large]).key && l<n) large=l;
    if((heap[r]).key<(heap[large]).key && r<n) large=r;
    if(large !=i) 
    {
        swap(heap, n, large, i );
        position[(heap[large]).vertex]=large;
        position[(heap[i]).vertex]=i;
        pheapify(heap,n,large,position,v);
    }
 }
  void cheapify(struct data heap[],int n,int i,int * position,int v)
 {
     int p, large=i;
     if(i==0) return;
     if(i%2==0) p=i/2-1;
     else p=i/2;
    if((heap[p]).key>(heap[large]).key && p<n) large=p;
    if(large !=i) 
    {
        swap(heap, n, large, i );
        position[(heap[large]).vertex]=large;
        position[(heap[i]).vertex]=i;
        cheapify(heap,n,large,position,v);
    }
 }
 int main()
{
    int v, e;
    cout<<"Enter no.of vertex  and edges\n";
    cin>>v>>e;
    cout<<"Vertex asigned as 0 to n-1 \n";
    cout<<"vertex1 vertex2 edgeWeight\n";
    struct node * adj[v];
    for(int i=0;i<v;i++) adj[i]=NULL;
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        struct node * new1, * ptr, *new2;
        new1=new node();
        new1->vertex=y; new1->weight=w,new1->f=0;
        ptr=adj[x];
        if(ptr==NULL) adj[x]=new1;
        else {while(ptr->next) ptr=ptr->next;
        ptr->next=new1;}
        /*new2=new node();
        new2->vertex=x, new2->weight=w,new2->f=0;
        ptr=adj[y];
        if(ptr==NULL) adj[y]=new2;
        else {while(ptr->next) ptr=ptr->next;
        ptr->next=new2;}*/
    }
    struct data heap[v];
    int position[v];
    for(int i=0;i<v;i++)
    {
        (heap[i]).parent=-1;
        (heap[i]).key=INT_MAX;
        (heap[i]).vertex=i;
        position[i]=i;
    }
    (heap[0]).key=0;
    int n=v, mstset[v]={0};
    for(int l=0;l<v;l++)
    {
        int m=(heap[0]).vertex;
        if(n>0) 
        {
            swap(heap, n,0,n-1);
            position[(heap[0]).vertex]=0;
            position[(heap[n-1]).vertex]=n-1;
        }
        n--;
        if(n>0) pheapify(heap,n,0,position, v);
        struct node  * ptr;
        mstset[m]=1;
        ptr=adj[m];
        while(ptr)
        {
            int s=ptr->vertex,w=ptr->weight;
            if( mstset[s]==0 && (heap[position[s]]).key>w+heap[position[m]].key)
            {
                (heap[position[s]]).key=w+heap[position[m]].key;
                (heap[position[s]]).parent=m;
                if(n>0) cheapify(heap,n,position[s],position,v);
            }
            ptr=ptr->next;
        }
    }
    cout<<"edges are in sequecing order\nEdge\tweight\n";
    for(int i=v-1;i>=0;i--)
    {
       if(heap[i].parent !=-1) cout<<heap[i].vertex<<"-"<<heap[i].parent<<"\t"<<heap[i].key<<"\n";
    }

}
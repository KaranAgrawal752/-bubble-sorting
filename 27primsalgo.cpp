#include<bits/stdc++.h>
using namespace std;
 int minKey(int key[], int mstset[],int v)
 {
     int min=INT_MAX, min_index;
     for(int i=0;i<v;i++)
     {
         if(mstset[i]==false && key[i]<min)
            min=key[i], min_index=i;
     }
     return min_index;
 }
 int main()
{
    int v;
    cout<<"Enter no.of vertex \n";
    cin>>v;
    cout<<"Vertex asigned as 0 to n-1 \n";
    int graph[v][v];
    for(int i=0;i<v;i++)
    {
        graph[i][i]=0;
        for(int j=i+1;j<v;j++)
        {
            cout<<"weight for edge "<<i<<"-"<<j<<" ";
            cin>>graph[i][j];
            graph[j][i]=graph[i][j];
        }
    }
    int key[v], mstset[v]={false}, parent[v];
    for(int i=1;i<v;i++) key[i]=INT_MAX;
    key[0]=0;
    parent[0]=-1;
    for(int count=0; count<v-1;count++)
    {
        int u=minKey(key, mstset,v );
        mstset[u]=true;
        for(int i=0;i<v;i++)
        {
            if(graph[u][i] != -1 && mstset[i]==false && graph[u][i]<key[i])
            parent[i]=u, key[i]=graph[u][i];
        }
    }
    //printmst(parent, (int *)graph,v);
    cout<<"\n";
    cout<<"Edge \t weight \n";
    for(int i=1; i<v;i++)
    {
        int k=parent[i];
        cout<<parent[i]<<"-"<<i<<" \t"<<graph[i][k]<<"\n";
    }

}
//
//
//
/*#include<bits/stdc++.h>
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
        new2=new node();
        new2->vertex=x, new2->weight=w,new2->f=0;
        ptr=adj[y];
        if(ptr==NULL) adj[y]=new2;
        else {while(ptr->next) ptr=ptr->next;
        ptr->next=new2;}
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
            if( mstset[s]==0 && (heap[position[s]]).key>w)
            {
                (heap[position[s]]).key=w;
                (heap[position[s]]).parent=m;
                if(n>0) cheapify(heap,n,position[s],position,v);
            }
            ptr=ptr->next;
        }
    }
    cout<<"edges are in sequecing order\nvertex-parent\tweight\n";
    for(int i=v-1;i>=0;i--)
    {
       if(heap[i].parent !=-1) cout<<heap[i].vertex<<"-"<<heap[i].parent<<"\t"<<heap[i].key<<"\n";
    }

}*/
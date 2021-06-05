#include <bits/stdc++.h>
using namespace std;
struct Item {
    int price, weight;
};
int fractionalKnapsack(int w, struct Item arr[], int n)
{
    float b[n], profit=0;
    vector<vector<float>> c;
    for(int i=0;i<n;i++)
    {
        b[i]=0;
        float r=arr[i].price/arr[i].weight;
        vector<float> v;
        v.push_back(r);
        v.push_back(i);
        c.push_back(v);
    }
    sort(c.begin(),c.end());
    for(int i=n-1;i>=0;i--)
    {
        int index=c[i][1];
        if(w>=arr[index].weight)
        {
            cout<<"a";
            profit+=arr[index].price;
            w-=arr[index].weight;
            b[index]=1;
        }
        else{
            cout<<"b";
            float f=(float)w/(arr[index].weight);
            w=0;
            profit+=f*arr[index].price;
            b[index]=f;
            break;
        }
    }
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
    cout<<"\n";
    return profit;
}
int main()
{
    int w,n; 
    cout<<"Enter size of array ";
    cin>>n;
    cout<<"Enter bag size ";
    cin>>w;
    Item arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"item["<<i<<"] weight and price ";
        cin>>arr[i].weight>>arr[i].price;
    }
    float f=fractionalKnapsack(w, arr, n);
   cout << "Maximum value we can obtain = "
         << f;
    return 0;
}
//source: https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/


#include<bits/stdc++.h>
using namespace std;
pair<int,pair<int,int>>graph[100009];
int par[10009];
void initialize()
{
    for(int i=0;i<10009;i++)
    {
        par[i]=i;
    }
}
int root(int x)
{
    while(par[x]!=x)
    {
        par[x]=par[par[x]];
        x=par[x];
    }
    return x;
}
void Union(int x,int y)
{
    int p=root(x);
    int q=root(y);
    par[p]=par[q];
}
long long kruskal(int nodes,int edges)
{
    long long minCost=0;
    for(int i=0;i<edges;i++)
    {
        int x=graph[i].second.first;
        int y=graph[i].second.second;
        int cost=graph[i].first;
        if(root(x)!=root(y))
        {
            minCost+=cost;
            Union(x,y);
        }
    }
    return minCost;
}
int main()
{
    initialize();
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        graph[i]={cost,{u,v}};
    }
    sort(graph,graph+edges);
    long long ans=kruskal(nodes,edges);
    cout<<ans<<endl;
    return 0;
}

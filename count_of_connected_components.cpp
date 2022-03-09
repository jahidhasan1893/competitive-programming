#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100];
bool vis[100];
void dfs(int node)
{
    vis[node]=1;
    for(int i=0;i<graph[node].size();i++)
    {
        int x=graph[node][i];
        if(!vis[x])dfs(x);
    }
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cc_count=0;
    for(int i=1;i<=nodes;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cc_count++;
        }
    }
    cout<<cc_count<<endl;
    return 0;
}

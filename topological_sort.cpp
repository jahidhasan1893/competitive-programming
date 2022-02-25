#include<bits/stdc++.h>
using namespace std;
vector<int>graph[500];
int indeg[500];
vector<int>topological_sort(int nodes)
{
    queue<int>q;
    vector<int>res;
    for(int i=0;i<nodes;i++)
    {
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        res.push_back(x);
        for(int i=0;i<graph[x].size();i++)
        {
            if(--indeg[graph[x][i]]==0) q.push(graph[x][i]);
        }
    }
    return res;
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=1;i<=edges;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        indeg[v]++;
    }
    vector<int>sorted_graph=topological_sort(nodes);
    for(int i:sorted_graph)
    {
        cout<<i<<" ";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
vector<int>graph[500];
bool flag;
void dfs(int u,int visited[])
{
    if(visited[u]==-1)
    {
        flag=1;
        return ;
    }
    visited[u]=-1;
    for(int v:graph[u])
    {
        if(visited[v]!=1)
        {
            dfs(v,visited);
        }
    }
    visited[u]=1;
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
    }
    int visited[nodes+1]={0};
    for(int i=1;i<=nodes;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited);
        }
        if(flag)
        {
            break;
        }
    }
    if(flag) cout<<"Cycle Detected"<<endl;
    else cout<<"Cycle Not Found"<<endl;
    return 0;
}

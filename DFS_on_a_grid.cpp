//problem : https://lightoj.com/problem/guilty-prince



#include<bits/stdc++.h>
using namespace std;
int dirX[]={1,-1,0,0};
int dirY[]={0,0,-1,1};
int w,h;
bool vis[25][25];
char a[25][25];
long long ans;
bool isValid(int i,int j)
{
    if(i>=0 && i<h && j>=0 && j<w && !vis[i][j] && a[i][j]!='#') return 1;
    return 0;
}
void dfs(int i,int j)
{
    vis[i][j]=1;
    ans++;
    for(int k=0;k<4;k++)
    {
        if(isValid(i+dirX[k],j+dirY[k]))
        {
            dfs(i+dirX[k],j+dirY[k]);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int m=1;m<=t;m++)
    {
        cin>>w>>h;
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        for(int j=0;j<h;j++)
        {
            cin>>a[j];
        }
        ans=0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(a[i][j]=='@')
                {
                    dfs(i,j);
                    break;
                }
            }
        }
        cout<<"Case "<<m<<": "<<ans<<endl;
    }
}

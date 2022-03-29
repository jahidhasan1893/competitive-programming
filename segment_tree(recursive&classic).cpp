#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int s[4*MAX];
void build(int a[],int node,int st,int e)
{
    if(st==e)
    {
        s[node]=a[st];
        return ;
    }
    int mid=(st+e)/2;
    build(a,node*2,st,mid);
    build(a,node*2+1,mid+1,e);
    s[node]=s[2*node]+s[(2*node)+1];
}
int query(int a[],int node,int st,int e,int l,int r)
{
    if(st>r || l>e || st>e) return 0;
    if(l<=st && r>=e) return s[node];
    int mid=(st+e)/2;
    int s1=query(a,2*node,st,mid,l,r);
    int s2=query(a,2*node+1,mid+1,e,l,r);
    return s1+s2;
}
int main()
{
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build(a,1,0,n-1);
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(a,1,0,n-1,l-1,r-1)<<endl;;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int tree[4*MAX];
int lazy[4*MAX];
void build(int a[],int node,int st,int e)
{
    if(st==e)
    {
        tree[node]=a[st];
        return ;
    }
    int mid=(st+e)/2;
    build(a,node*2,st,mid);
    build(a,node*2+1,mid+1,e);
    tree[node]=tree[2*node]+tree[(2*node)+1];
}
void update_range(int a[],int node,int st,int e,int l,int r,int val)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(e-st+1)*lazy[node];
        if(st!=e)
        {
            lazy[2*node]+=lazy[node];
            lazy[(2*node)+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(e<l || st>r || st>e) return ;
    if(st>=l && e<=r)
    {
        tree[node]+=(e-st+1)*val;
        if(st!=e)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    int mid=(st+e)/2;
    update_range(a,2*node,st,mid,l,r,val);
    update_range(a,2*node+1,mid+1,e,l,r,val);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int a[],int node,int st,int e,int l,int r)
{
    if(st>e || l>e || r<st) return 0;
    if(lazy[node]!=0)
    {
        tree[node]+=(e-st+1)*lazy[node];
        if(st!=e)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(st>=l && e<=r) return tree[node];
    int mid=(st+e)/2;
    int x=query(a,2*node,st,mid,l,r);
    int y=query(a,2*node+1,mid+1,e,l,r);
    return x+y;
}
int main()
{
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    build(a,1,0,n-1);
    for(int i=0; i<q; i++)
    {
        char qt;
        cin>>qt;
        if(qt=='q')
        {
            int l,r;
            cin>>l>>r;
            cout<<query(a,1,0,n-1,l-1,r-1)<<endl;
        }
        else if(qt=='u')
        {
            int l,r,val;
            cin>>l>>r>>val;
            update_range(a,1,0,n-1,l-1,r-1,val); //add value
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int ncr(int n,int r)
{
    int res=1;
    if(r>n-r) r=n-r;
    for(int i=0;i<r;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}

int main()
{
    int n,r;
    cin>>n>>r;
    cout<<ncr(n,r)<<endl;
    return 0;
}

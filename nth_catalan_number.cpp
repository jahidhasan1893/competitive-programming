//sources:
//https://cp-algorithms.com/combinatorics/catalan-numbers.html
//https://www.topcoder.com/thrive/articles/catalan-number-and-its-application
//https://www.youtube.com/watch?v=J0heuWnOKcw&ab_channel=NPTEL-NOCIITM

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll ncr(ll n,ll r)
{
    ll res=1;
    if(r>n-r) r=n-r;
    for(ll i=0;i<r;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
ll cat(ll n)
{
    ll nCr=ncr(2*n,n);
    return nCr/(n+1);
}
int main()
{
    ll n;
    cin>>n;
    cout<<cat(n)<<endl;
    return 0;
}

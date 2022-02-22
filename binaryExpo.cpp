#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll binPow(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b%2) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<binPow(a,b);
    return 0;
}

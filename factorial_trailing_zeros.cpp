//problem link : https://codeforces.com/problemset/problem/633/B
//we can also use binary search here

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define file freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fa(i,b) for(int i=0;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define N 1000000007
#define MX 1000000000
#define INF 1<<30
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define ceil(a,b) (a+b-1)/b
#define floor(a,b) a/b
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
int main()
{
    fast;
    ll n;
    cin>>n;
    vector<int>res;
    for(ll i=1; i<=1000000; i++)
    {
        ll j=5;
        int ans=0;
        while(j<=i)
        {
            ans+=(i/j);
            j*=5;
        }
        if(ans==n) res.push_back(i);
    }
    cout<<res.size()<<endl;
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    return 0;
}

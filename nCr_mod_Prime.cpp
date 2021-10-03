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
int factMod(int n,int m)
{
    int f=1;
    for(int i=2;i<=n;i++)
    {
        f*=i;
        f%=m;
    }
    return f;
}

int powMod(int a,int b,int m)
{
    int p=a;
    for(int i=2;i<=b;i++)
    {
        p*=a;
        p%=m;
    }
    return p;
}

int nCrmod(int n,int r,int m)
{
    int a=factMod(n,m);
    int b=(factMod(r,m)*factMod(n-r,m))%m;
    return (a*powMod(b,m-2,m))%m;
}

int main()
{
    fast;
    int n,r,m;
    cin>>n>>r>>m;
    cout<<nCrmod(n,r,m);
    return 0;
}

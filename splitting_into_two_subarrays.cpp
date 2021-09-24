//split the array into two subarrays
//such that sum of their absolute
//difference is minimum


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
    int n;
    cin>>n;
    int a[n],suf[n+1],pre[n+1];
    pre[0]=0;
    suf[n]=0;
    fa(i,n) cin>>a[i];
    for(int i=1;i<=n;i++) pre[i]=(pre[i-1]+a[i-1]);
    for(int i=n-1;i>=0;i--) suf[i]=suf[i+1]+a[i];
    int ans=INT_MAX;
    for(int i=0;i<=n;i++)
    {
        int dif=abs(pre[i]-suf[i]);
        ans=min(ans,dif);
    }
    cout<<ans<<endl;
    return 0;
}

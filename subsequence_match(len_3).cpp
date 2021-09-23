//Given a string S and another string T of length 3.
// We want to find the number of sub-sequences of length 3
//from S which match the string T.

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
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int pre[n],suf[n];
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[0]) c++;
        pre[i]=c;
    }
    c=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==t[2]) c++;
        suf[i]=c;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[1])
        {
           ans+=suf[i]*pre[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}

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
    int m=t.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string x="";
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
        {
            x+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else j--;
    }
    reverse(x.begin(),x.end());
    cout<<x<<endl;
    return 0;
}

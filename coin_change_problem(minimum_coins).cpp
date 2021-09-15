#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum,n;
    cin>>sum>>n;
    int coins[n];
    long long dp[sum+1];
    dp[0]=0;
    for(int j=1;j<=sum;j++) dp[j]=INT_MAX;
    for(int i=0;i<n;i++) cin>>coins[i];
    //sum must be in outer loop for this problem
    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=coins[j])
            {
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    cout<<dp[sum];
    return 0;
}

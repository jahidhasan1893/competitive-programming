//finding phi function of n

#include<bits/stdc++.h>
using namespace std;
int phi(int n)
{
    int res=n;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            res-=res/i;
        }
    }
    if(n>1) res-=res/n;
    return res;
}


int main()
{
    int n;
    cin>>n;
    cout<<phi(n)<<endl;
    return 0;
}

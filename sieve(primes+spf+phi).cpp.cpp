//printing all primes upto n +
//printing shortest prime factor(spf) of all number upto n+
//printing all phi functions upto n

#include<bits/stdc++.h>
using namespace std;
void sieve(bool is_prime[],int spf[],vector<int>&primes,int phi[],int n)
{
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]==true)
        {
            primes.push_back(i);
            spf[i]=i;
            for(int j=i;j<=n;j+=i)
            {
                is_prime[j]=false;
                if(spf[j]==0) spf[j]=i;
                phi[j]-=phi[j]/i;
            }
        }
    }
}


int main()
{
    int n;
    cin>>n;
    bool is_prime[n+1];
    int spf[n+1];
    vector<int>primes;
    int phi[n+1];
    memset(is_prime,true,sizeof(is_prime));
    memset(spf,0,sizeof(spf));
    for(int i=0;i<=n;i++)
    {
        phi[i]=i;
    }
    is_prime[0]=is_prime[1]=false;
    sieve(is_prime,spf,primes,phi,n);
    cout<<"primes upto n ->"<<endl;
    for(int i=0;i<primes.size();i++)
    {
        cout<<primes[i]<<" ";
    }
    cout<<endl;
    cout<<"smallest primes factors(spf) upto n ->"<<endl;
    for(int i=1;i<=n;i++)
    {
        if(spf[i]==0) cout<<i<<" -> No prime factors"<<endl;
        else cout<<i<<" -> "<<spf[i]<<endl;
    }
    cout<<"phi functions upto n ->"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> "<<phi[i]<<endl;
    }
    return 0;
}


/*
Related Problems:
1)https://codeforces.com/contest/1366/problem/D

*/

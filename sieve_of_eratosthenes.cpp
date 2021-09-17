//printing all primes upto n

#include<bits/stdc++.h>
using namespace std;
void sieve_of_eratosthenes(bool primes[],int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(primes[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                primes[j]=false;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    bool primes[n+1];
    memset(primes,true,sizeof(primes));
    primes[0]=primes[1]=false;
    sieve_of_eratosthenes(primes,n);
    for(int i=2;i<=n;i++)
    {
        if(primes[i]==true) cout<<i<<endl;
    }
    return 0;
}

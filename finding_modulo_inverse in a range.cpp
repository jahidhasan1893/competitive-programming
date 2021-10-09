#include<bits/stdc++.h>
using namespace std;
int inv[100000];
void modulo_inverse(int m)
{
    inv[1]=1;
    for(int i=2;i<m;i++)
    {
        if(__gcd(i,m)==1) inv[i]=m-(m/i)*inv[m%i]%m;
        else inv[i]=-1; //modulo inverse don't exist
    }
}
int main()
{
    int m;
    cin>>m;
    modulo_inverse(m); //finding modulo inverse for every number in range [1,m)
    return 0;
}

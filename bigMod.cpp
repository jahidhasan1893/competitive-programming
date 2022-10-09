#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string a;
    cin>>a;
    ll b;
    cin>>b;
    ll mod=0;
    for(int i=0; i<a.size(); i++)
    {
        mod=(mod*10+(int)a[i]-'0')%b;
    }
    cout<<mod<<endl;
    return 0;
}

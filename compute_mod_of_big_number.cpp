//source::https://www.geeksforgeeks.org/how-to-compute-mod-of-a-big-number/

#include<bits/stdc++.h>
using namespace std;

int mod(string num,int m)
{
    int res=0;
    for(int i=0;i<num.size();i++)
    {
        res=(res*10+(int)num[i]-'0')%m;
    }
    return res;
}

int main()
{
    string num;
    cin>>num;
    int m;
    cin>>m;
    cout<<mod(num,m);
    return 0;
}

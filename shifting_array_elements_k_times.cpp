#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a1[]={1,2,3,4,5};
    int n=5;
    int l_rot=2;
    int r_rot=2;
    rotate(a1,a1+l_rot,a1+n); //left rotate
    cout<<"after rotating left"<<endl;
    for(int i=0;i<n;i++) cout<<a1[i]<<endl;
    int a2[]={1,2,3,4,5};
    rotate(a2,a2+n-r_rot,a2+n);//right rotate
    cout<<"after roating right"<<endl;
    for(int i=0;i<5;i++) cout<<a2[i]<<endl;
    return 0;
}

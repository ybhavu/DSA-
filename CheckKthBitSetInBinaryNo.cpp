#include <bits/stdc++.h>
using namespace std;

void check(int n,int k)     //Using left Shift
{
    if((n&(1<<k-1))!=0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

void check1(int n,int k){       //Right Shift
    if(((n>>(k-1))&1)==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
int main()
{
    check(5,3);
    check1(5,3);
    return 0;
}
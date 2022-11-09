#include <bits/stdc++.h>
using namespace std;
int gcd(long a,long b)
{
    int res=min(a,b);
    while(res>0)
    {
        if(a%res==0 && b%res==0)
        {
            break;
        }
        res--;

    }
    return res;
}
int main()
{
    cout<<gcd(4,6)<<endl;

    return 0;
}
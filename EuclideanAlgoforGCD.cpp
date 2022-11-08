//Basic idea is gcd(a,b) = gcd(a-b,b) if a>b
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b) // Iterative 
{
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    return a;
}

int gcd1(int a,int b)  //Recurssive and optimised
{
    if(b==0)
    {
        return a;
    }
    else{
        return gcd(b,a%b);
    }
    

}
int main()
{
    cout<<gcd(12,15)<<endl;
    cout<<gcd1(12,15)<<endl;
    return 0;
}
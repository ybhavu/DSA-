/*
return no. which occurs odd no. of time 
here we use xor property of x^x=0 and x^0=x
so even ones will cancel out each other and one of odd will remain
*/
/*
if given a question where array given of n element where element can be 
no. bet 1 and n+1 and one no.is missing use same technique of xor
*/
#include <bits/stdc++.h>
using namespace std;

int findOdd(int arr[],int n)
{
    int res=0;
    for(int i=0;i<n;i++){
        res=res^arr[i];
    }
    return res;
}

int main(){
    int arr[]={4,3,3,3,4,4,4,5,5};
    auto n=9;
    cout<<findOdd(arr,n);
    return 0;
}

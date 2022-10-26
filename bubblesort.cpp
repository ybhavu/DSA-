#include <bits/stdc++.h>
using namespace std;



int main(){
    vector<int> v = {2,10,8,7,2,9,18,3,8,16};
    int n = v.size();
    for(int i=0;i<n-1;i++){
        bool swapped = false;
        for(int j=0;j<n-1-i;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
    for(auto x:v){
        cout<<x<<" ";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct MyStack{
    int *arr;
    int cap;
    int top;
    MyStack(int c){
        cap = c;
        arr = new int[cap];
        top = -1;
    }
    void push(int x){
        if(top == cap-1){
            cout<<"STACK OVERFLOW"<<endl;
        }
        top++;
        arr[top] = x;
    }
    int pop(){
        if(top == -1){
            cout<<"STACK UNDERFLOW"<<endl;
        }
        int res = arr[top];
        top--;
        return res;
    }
    int peek(){
        if(top == -1){
            cout<<"STACK UNDERFLOW"<<endl;
        }
        return arr[top];
    }
    int size(){
        return (top+1);
    }
    bool isEmpty(){
        return (top == -1);
    }
};


int main(){
    MyStack s(5);
    // s.push(10);
    // s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct  Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    else{
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

Node *insert(Node *root,int val){
    if(root->data < val){
        if(root->right == NULL ){
            root->right = new Node(val);
        }else{
            insert(root->right,val);
        }   
    }
    else if(root->data > val){
        if(root->left == NULL ){
            root->left = new Node(val);
        }else{
            insert(root->left,val);
        }   
    }
    return root;
}
int main(){
    vector<int> v ={20,15,30,40,50,12,18,35,80,7};
    Node *root = new Node(v[0]);
    for(auto x:v){
        root = insert(root,x);
    }
    inorder(root);


    return 0;
}
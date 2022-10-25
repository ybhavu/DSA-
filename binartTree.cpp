#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};
// struct DL{
//     int data;
//     Node *prev;
//     Node *next;
//     DL(int x){
//         data = x;
//         prev = NULL;
//         next = NULL;

//     }
// }

void inorder(Node *root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root != NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

int height(Node *root){
    if(root == NULL){
        return 0;
    }
    else{
        return (max(height(root->left),height(root->right)+1));
    }
}

void printKDist(Node *root,int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->key<<" ";
    }
    else{
        printKDist(root->left,k-1);
        printKDist(root->right,k-1);
    }
}

void BFS(Node *root){
    if(root == NULL){
        return;
    }
    else{
        cout<<root->key<<" ";
        BFS(root->left);
        BFS(root->right);
    }
}

void BFSite(Node *root){
    if(root == NULL){
        return;
    }
    queue <Node *> q;
    q.push(root);
    while(q.empty() != true){
        Node *curr = q.front();
        q.pop();
        cout<<(curr->key)<<" ";
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    } 
}

void linebfs(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node *curr = q.front();
        q.pop();
        if(curr == NULL){
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<curr->key<<" ";
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }

}
void linebfs1(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false){
        int cnt = q.size();
        for(int i=0;i<cnt;i++){
            Node *curr = q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
           
        }
        cout<<endl;
    }
}

int size(Node *root){
    if(root == NULL){
        return 0;
    }
    else{
        return (size(root->left)+size(root->right)+1);
    }
}

int maxi(Node *root){
    if(root == NULL){
        return INT_MIN;
    }
    else{
        return max(root->key,max(maxi(root->left),maxi(root->right)));
    }
}

void leftview(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false){
        int cnt = q.size();
        for(int i=0;i<cnt;i++){
            Node * curr = q.front();
            q.pop();
            if(i==0){
                cout<<curr->key<<" ";
            }
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}

bool childrensum(Node *root){
   if(root == NULL){
    return true;
   }
   if(root->left == NULL && root->right == NULL){
    return true;
   }
   int sum = 0;
   if(root->left != NULL){sum += root->left->key;}
   if(root->right != NULL){ sum += root->right->key;}
   return (root->key == sum && childrensum(root->left) && childrensum(root->right));
}

int balanced(Node *root){
    if(root == NULL){
        return 0;
    }
    int lh = balanced(root->left);
    if(lh == -1){
        return -1;
    }
    int rh = balanced(root->right);
    if(rh == -1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }
    else{
        return max(lh,rh)+1;
    }
    
}

void width(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    int w = INT_MIN;
    while(q.empty() == false){
        int cnt = q.size();
        w = max(w,cnt);
        for(int i=0;i<cnt;i++){
            Node *curr = q.front();
            q.pop();
            if(curr->left != NULL){q.push(curr->left);}
            if(curr->right != NULL){q.push(curr->right);}
        }
    }
    cout<<w<<endl;
}
// Node *prev = NULL;
// Node *bttdl(Node *root){
//     if(root == NULL){
//         return;
//     }

//         Node *head = bttdl(root->left);
//         if(prev == NULL){
//             head = root;
//         }
//         else{
//             root->left = prev;
//             prev->right = root;
//         }
//         prev = root;
//         bttdl(root->rigth);
//         return head;
// }




int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    // postorder(root);
    // cout<<height(root);
    // printKDist(root,2);
    // linebfs1(root);
    // cout<<maxi(root);
    // leftview(root);
    cout<<balanced(root);
    // width(root);
    return 0;
}
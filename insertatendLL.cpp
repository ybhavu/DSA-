#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

Node *insertend(Node *head,int x){
    Node *temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return (head);

}

Node *deletehead(Node *head){
    if(head == NULL){
        return NULL;
    }
    Node *temp = head->next;
    delete head;
    return temp;
}

Node *delTail(Node *head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;

}

void printL(Node *head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    printL(head->next);
}


int main(){
    Node *head = NULL;
    head = insertend(head,10);
    head = insertend(head,20);
    head = insertend(head,30);
    head = insertend(head,40);
    head = deletehead(head);
    head = delTail(head);
    printL(head);
    return 0;
}
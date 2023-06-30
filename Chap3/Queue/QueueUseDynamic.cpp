#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int value;
    Node* next;
} Node;
typedef struct Queue{
    Node* head,* tail;
} Queue;
Node* makenode(int n){
    Node* p= new Node;
    p->value=n;
    p->next= NULL;
    return p;
}
void add_last(Node*tail, int value){
    Node* p= makenode(value);
    tail->next=p;
    tail= p;
}
int pop_first(Node* head){
    int val= head->value;
    Node* cur= head;
    head=cur->next;
    delete(cur);

}

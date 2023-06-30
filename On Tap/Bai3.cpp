#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
char id[256];
struct Node* leftMostChild;
struct Node* rightSibling;
} Node;
int coutNode(Node* root){
    int cout= 0;
    if (root== NULL) return 0;
    cout++;
    root= root->leftMostChild;
    while(root!= NULL){
        cout+= coutNode(root);
        root= root->rightSibling;
    }
    return cout;
}
Node* find(Node* root, char* idF){
    if (root== NULL) return NULL;
    if (strcmp(root->id, idf)==0) return root;
    Node* p= root->leftMostChild;
    while(p!= NULL){
        Node*q= find(p, name);
        if (q!= NULL) return q;
        p= p->rightSibling;
    }
}
void addNode( char* idC, char* idK){
    Node* new_node= (Node*) malloc(sizeof(Node));
    strcpy(new_node->id, idC);
    Node* parent= find(root, idK);
    if(parent!= NULL){
        Node* rightmost= parent->leftMostChild;
        while(rightmost->rightSibling!=NULL){
            rightmost= rightmost->rightSibling;
        }
        rightmost->rightSibling= new_node;
    }
}
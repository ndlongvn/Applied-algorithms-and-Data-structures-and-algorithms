#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long;
#define M 100000;
typedef struct Node{
    ULL key;
    Node* next;
} Node;
Node* makeNode(ULL k){
    Node* t= (Node*)malloc(sizeof(Node));
    t->ULL= k;
    t->next= NULL;
    return t;
}
bool find(ULL k, *ptr);
void insert(ULL k);
int main(){
    Node* s[100];
    for(int i=0; i<100; i++){
        s[i]->key= i;
    }
}

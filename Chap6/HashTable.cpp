#include <iostream>
using namespace std;
#define M 100
typedef struct Node{
    int key;
    Node* next;
} Node;
typedef Node* HashTable[M];
Node* taoNode(int k){
    Node* t= new Node;
    t->key= k;
    t->next= NULL;
    return t;
}
HashTable tab;
void taoHashTable(){
    for(int i=0; i<M; i++){
        tab[i]= taoNode(i);
    }
}
int Hash(int k){
    return k%M;
} 
bool find(int k){
    int h= Hash(k);
    if(tab[h]->next==NULL) return false;
    Node* p= tab[h];
    while(p!=NULL){
        if(p->key==k) return true;
        p= p->next;
    }
    return false;
}
void insert(int k){
    int h= Hash(k);
    Node* p= taoNode(k);
    
    if(tab[h]->next==NULL){
        tab[h]->next= p;
    }
    else{
        // Node* m= tab[h]->next;
        if(!find(k)){
            p->next= tab[h]->next;
            tab[h]->next =p;
        }
        else{
            cout<<"da ton tai\n";
        }
        
    }
}

void deleter(int k){
    int h= Hash(k);
    Node* p= tab[h];
    if(p==NULL) cout<< "ko ton tai";
    else{
        Node* j= p->next;
        while(j!=NULL){
            if(j->key==k) break;
            j= j->next;
            p= p->next;
        }
        if(j!=NULL){
            p->next= j->next;
            free(j);
        }
    }
}
int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    taoHashTable();
    for(int i=1; i<200; i*=2){
        insert(i);
    }
    insert(202);
    deleter(2);
    for(int i=1; i<200; i*=2){
        if(find(i)) cout<<"co thay\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int val;
    Node* next;
} Node;
typedef struct Stack{
    Node* top;
}Stack;
Node* make_node(int val){
    Node* v= new Node;
    if(v==NULL) cout<< "loi";
    v->val= val;
    v->next= NULL;
    return v;
} 
Stack* make_stack(){
    Stack* s= new Stack;
    if(s==NULL) cout<< "thieu bo nho";
    else{
        s->top= NULL;
    }
    return s;
}

void push(int val, struct Stack* s){
    Node* k= make_node(val);
    Node* p= new Node;
    p= s->top;
    if(p==NULL) s->top= k;
    else{
        while(p!= NULL){
            p= p->next;
        }
        p->next= k;
    }

    // return root;
}
Node* pop(struct Stack* s){
    Node* n= new Node;
    n= s->top;
    while(n->next!= NULL){
        n= n->next;
    }
    Node*k= n-> next;
    n->next= NULL;
    // delete(k);
    return k;
}
int main(){
    string k;
    Stack* s= make_stack();
    push(3, s);
    Node* n= pop(s);
    cout<<n->val;
    // while(1){
    //     cin>> k;
    //     if(k=="PUSH"){
    //         int m;
    //         cin>> m;
    //         cout<<m<<endl;
    //         push(m, s);
    //     }
    //     if(k=="POP"){
    //         Node* m= pop(s);
    //         cout<< m->val<<endl;
    //         delete m;
    //     }
    //     if(k=="#") break;
    // }
    return 0;
}
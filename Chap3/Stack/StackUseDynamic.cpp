#include<bits/stdc++.h>
using namespace std;
typedef struct NodeStack{
    int value;
    NodeStack* next;
} NodeStack;
typedef struct Stack{
    NodeStack* top;
} Stack;
Stack* taoStack(){
    Stack* s= new Stack;
    if(s==NULL){
        cout<<"thieu bo nho";
        return NULL;
    }
    s->top= NULL;
    return s;
}
bool StackEmpty(Stack* s){
    return (s->top==NULL);
}
void StackPop(Stack* s){
    if(s->top==NULL) cout<<"loi";
    NodeStack* cur= s->top;
    s->top= cur->next;
    delete(cur);
}
void xoastack(Stack* s){
    while(!StackEmpty(s)){
        StackPop(s);
    }
    delete(s);
}


bool StackPush(Stack*s, int m){
    NodeStack* a= new NodeStack;
    if(a==NULL) return false;
    a->value=m;
    a->next=s->top;
    s->top= a;
    return true;
}
void Stackdisplay(Stack*s){
    if(StackEmpty(s)) cout<<"rong";
    else{
        NodeStack* to= s->top;
        while(to!=NULL){
            cout<<to->value<<endl;
            to= to->next;
        }

    }
}
#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int value;
    node* next;
} node;
typedef struct Singlely{
    node* head= new node;
} LinkedList;
node *makenode(int p){
    node* p1= new node;
    p1->value= p;
    p1->next= NULL;
    return p1;
}
node* add_first(int n, node* head){
    node* p= makenode(n);
    p->next= head;
    head=p;
    return head;
}
void add_last(int n,node* head){
    node* p= makenode(n);
    node* cur= head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=p;
    p->next= NULL;
    //return head;
}
node* insert_before(int n, node* head, node* insert){
    node* p= makenode(n);
    if(head==NULL){
        head=p;
        return p;
    }
    else if(head==insert){
        p->next= head;
        head=p;
        return p;
    }
    else{
        node* cur= head;
        while(cur->next!=insert){
            cur=cur->next;
        }
        p->next= cur->next;
        cur->next=p;
        return p;
    }


}
node* deleteone(node* head, node* p){
    if(p==head){
        head= p->next;
        delete(head);
    }
    else{
        node*cur=head;
        while(cur->next!=p){
            cur=cur->next;
        }
        cur->next=p->next;
        delete(p);
    }
    return head;
}
node* deleteall(node* head){
    node* del=head;
    while(del!=NULL){
        del= del->next;
        delete(del);
    }
    return del->next;
}
bool is_empty(node* head){
    if(head==NULL){
        return true;
    }
    return false;
}
int count_node(int n, node* head){
    node* cur= head;
    int k=0;
    while(cur!=NULL){
        if(cur->value==n) k++;
        cur= cur->next;
    }
    return k;
}
int main(){
    node *a1,*a2,*a3, *head;
    head= new node;//a1= new node;a2= new node;a3= new node;
    a1= makenode(1);
    /*a1->value=1;
    a2->value=2;
    a3->value=3;*/
    a2= makenode(2);
    a3= makenode(3);
    head->next=a1;
    a1->next= a2;
    a2->next= a3;
    a3->next= NULL;
    head= add_first(4,head);
    add_last(5,head);
    node* a4= insert_before(2.5, head, a2);
    //node* cur= head;
    //cur=cur->next;
    //cout<<cur<<" "<<head<<endl;
    while(head!=NULL){
        cout<<head->value<<" "<<head<<endl;
        head= head->next;
    }
    node* z;
    z= makenode(1);
    //z->value=2;
    cout<<z->next<<" "<<z->value<<" 1 0";
}
#include<bits/stdc++.h>
using namespace std;
typedef struct danhba{
    string ten;
    string email;
    string sdt;
    string chucvu;
    int namsinh;
} danhba;
typedef struct node{
    int value;
    node* prev;
    node* next;
} node;
typedef struct node1{
    danhba db;
    node1* prev;
    node1* next;
} node1;
node1* makenode1(string ten, string email ,string sdt, string  chucvu, int namsinh){
    node1* p= new node1;
    p->db.ten= ten;
    p->db.email= email;
    p->db.sdt= sdt;
    p->db.chucvu= chucvu;
    p->db.namsinh= namsinh;
    p->next= NULL;
    p->prev= NULL;
    return p;
}
node* makenode(int p){
    node* p1= new node;
    p1->value= p;
    p1->next= NULL;
    p1->prev= NULL;
    return p1;
}
node* delete(node* p, node* head){
    if(head==NULL) cout<<"ds rong";
    else{
        if(p==head){
            head= head->next;
            head->prev=NULL;
            delete p;
        }
        else{
            p->prev->next=p->next;
        }
        if(p.next!=NULL){
                p->next->prev= p->prev;
            }
            delete p;
        
    }
    return head;
}
void insert(node*p, node*head, int n){
    node* k= makenode(n);
    if(head==NULL) {
        cout<<"rong";
        head= k;
        
    }

    if (p->next!=NULL)(
        p->next->prev= k;
        k->next= p->next;
        p->next=k;
        k->prev=p;
    )
    else{
        p->next=k;
        k->prev=p;
    }
}
void add_last(int n, node *tail){
    node* p= makenode(n);
    if(tail==NULL) {
        cout<<"rong";
        tail= p;
    }
    else{
        tail->next=p;
        p->prev=tail;
        tail=p;
    }
    
}
void add_first(int n, node* head){
    node* p= makenode(n);
    if(head==NULL){
        head=p;
    }
    else{
        p->next=head;
        head->prev=p;
        head=p;
    }
}

int main(){
    node* head= makenode(1);
    node* a1= makenode(2);
    node* a2= makenode(3);
    node* a3= makenode(4);
    head->next=a1;
    a1->next= a2;
    a2->next= a3;
    node* cur= head;
    while(cur!=NULL){
        cout<<cur->value<<endl;
        cur= cur->next;
    }
    node1* head1= makenode1("Long","vctb","0346402689", "sinhvien",2002);
    node1* a11= makenode1("XT","gcxt", "0129997425", "sinhvien",2002);
    head1->next= a11;
    node1* cur1= head1;
    while(cur1!=NULL){
        cout<<cur1->db.ten<<endl;
        cur1= cur1->next;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int coef;
    int exp;
    node* next;
} node;
node* makenode(int coef, int exp ){
    node* p= new node;
    p->coef= coef;
    p->exp= exp;
    p->next=NULL;
    return p;
}
void add_last(node* p, int coef, int exp){
    node* k= makenode(coef,exp);
    node* cur=p;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=k;
}
void congdathuc(node* x, node* y, node*p){
    while(x!=NULL && y!=NULL){
        if((x->exp)>(y->exp)){
            add_last(p, x->coef,x->exp );
            x=x->next;
        }
        else if((x->exp)<(y->exp)){
            add_last(p, y->coef, y->exp);
            y= y->next;
        }
        else{
            add_last(p, x->coef+y->coef, x->exp);
            x=x->next;
            y=y->next;
        }
    }
    if(x!=NULL &&y==NULL){
        while(x!=NULL){
            add_last(p,x->coef,x->exp);
            x=x->next;
            
        }
    }
    if(y!=NULL &&x==NULL){
        while(y!=NULL){
            add_last(p, y->coef, y->exp);
            y=y->next;
            
        }
    }
}
int main(){
    node* x= makenode(1,10);
    node* x1= makenode(2,9);
    node* y= makenode(3,8);
    node* y1= makenode(2,7);
    node* y2= makenode(6,3);
    x->next=x1;
    y->next= y1;
    y1->next= y2;
    node* z= makenode(0,0);
    congdathuc(x,y,z);
    while(z!=NULL){
        cout<<z->coef<<" "<<z->exp<<endl;
        z= z->next;
    }
    cout<<(z==NULL);
    return 0;
}
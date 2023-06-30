#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    string str;
    node* right;
    node* left;
} node;
node* root;
node* make_node(string str){
    node* v= new node;
    v->str= str;
    v->right= NULL;
    v->left= NULL;
    return v;
}
node* insert_node(node* p, string str){
    node* v= make_node(str);
    if(p==NULL) return v;
    int k= (p->str).compare(str);
    if(k==0) return p;
    else if(k>0) {
       p->left= insert_node(p->left, str);
    }
    else{
       p->right= insert_node(p->right, str);
    }
    return p;
}
node* find_node(node* p, string str){
    if(p==NULL) return NULL;
    int k= (p->str).compare(str);
    if(k==0) return p;
    else if(k< 0){
        return find_node(p->right, str);
    } 
    else {
        return find_node(p->left, str);
    } 
}
int main(){  
    root= NULL;   
    while(true){
        string k;
        cin>>k;
        if(k=="*") break;
        root= insert_node(root, k);
    }
    while(true){
        string h, k;
        cin>> k;
        if(k=="***") break;
        cin>>h;
        if(k=="insert"){
            node* m=  find_node(root, h);
            if(m!=NULL) cout<<0<<endl;
            else{
                root= insert_node(root, h);
                cout<<1<<endl;
            } 
            
        }
        else if(k=="find"){
            node* m=  find_node(root, h);
            if(m==NULL) cout<<0<<endl;
            else cout<<1<<endl;
        }
        
    }
    return 0;
}
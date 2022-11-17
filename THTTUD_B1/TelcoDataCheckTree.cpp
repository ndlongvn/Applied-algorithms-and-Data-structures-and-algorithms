#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    char from_node[20];
    int num_call;
    int time;
    Node* left_child;
    Node* right_child;
} Node;
Node* root;
Node* make_node(char* num, int num_call, int time){
    Node* p= new Node;
    strcpy(p->from_node, num);
    p->num_call= num_call;
    p->time= time;
    p->left_child= NULL;
    p->right_child= NULL;
    return p;
}
Node* insert_BST(char* num, int num_call, int time, Node* p){
    if(p==NULL){
        return make_node(num, num_call, time);
    }
    int k= strcmp(p->from_node,num);
    if(k==0){
        p->num_call+= num_call;
        p->time+= time;
    }
    else if(k>0){
        p->left_child= insert_BST(num, num_call, time, p->left_child);
    }
    else{
        p->right_child= insert_BST(num, num_call, time, p->right_child);
    }
    return p;
}
Node* find_node(char* num, Node* p){
    if(p==NULL) return NULL;
    int k= strcmp(p->from_node, num);
    if(k==0) return p;
    else if(k<0) return find_node(num, p->right_child);
    else{
        return find_node(num, p->left_child);
    }
}
bool check(char* num){
    if(strlen(num)!= 10) return false;
    for(int i=0; i<10; i++){
        if(!isdigit(num[i])) return false;
    }
    return true;
}

int cal_time(char* t){
    int h, m, s;
    sscanf(t, "%d:%d:%d", &h, &m, &s);
    int secs = h *3600 + m*60 + s;
    return secs;
}
void run(){
    char fromNumber[20];
    char toNumber[20];
    char date[20];
    char fromTime[10];
    char toTime[10];
    char cmd[20];
    bool che= true;
    int nu= 0;
    while(1){
        cin>> cmd;
        if (strcmp(cmd,"#") == 0)
            break;
        else if (strcmp(cmd, "call") == 0){
            cin>>fromNumber>>toNumber>>date>>fromTime>>toTime;
            int time = cal_time(toTime) - cal_time(fromTime);
            Node *p = find_node(fromNumber,root);
            if (p == NULL)
            {
                root = insert_BST(fromNumber,1,time,root);
            }
            else{
                p->num_call+=1;
                p->time +=time;
            }
            nu+=1;
            if (che)
                che = check(fromNumber);
            if (che)
                che = check(toNumber);
        }
    }
    char number[20];
    while (1){
        cin>> cmd;
        if (strcmp(cmd,"#") == 0)
            break;
        else if (strcmp(cmd,"?check_phone_number")==0)
            printf("%d\n", che);
        else if (strcmp(cmd,"?number_calls_from")==0){
            cin>> number;
            Node* p =find_node(number,root);
            if(p ==NULL) printf("0\n");
            else printf("%d\n",p->num_call);
        }
        else if (strcmp(cmd,"?number_total_calls")==0)
            printf("%d\n", nu);
        else if(strcmp(cmd,"?count_time_calls_from")==0){
            cin>> number;
            Node*p=find_node(number, root);
            if(p == NULL) printf("0\n");
            else printf("%d\n",p->time);
        }
    }
}
int main(){
    root= NULL;
    run();
    return 0;
}
               
#include<bits/stdc++.h>
using namespace std;
stack<int> s1;stack<char> s2;
map<char,int> map1{{'^',3},{'*',2},{'/',2},{'+',1},{'-',1}};
char a1[]={'+','-','*','/','^'};
char a2[]={'+','-','*','/','^','(',')'};
void do_process(){
    int a= s1.top();
    s1.pop();
    int b= s1.top();
    s1.pop();
    char c= s2.top();
    s2.pop();
    int d;
    if (c=='+'){
        d=a+b;
    }
    else if(c=='-'){
        d=b-a;
    }
    else if(c=='*'){
        d=a*b;
    }
    else if (c=='/'){
        d=b/a;
    }
    else if(c=='^'){
        d=pow(b,a);
    }
    s1.push(d);
    //cout<<"pop "<<a<<" "<<b<<"push s1 "<<d<<" "<<endl;
    
}
bool check(char j){
    for (int i= 0; i<5; i++){
        if(j==a1[i]){
            return true;
        }
    }
    return false;
}
int duyet(char s[],int n){
    int curnum=0;
    for (int i=0; i<n; i++){
        if (s[i] == ' ') continue; 
        if (isdigit(s[i])) {
            curnum = curnum * 10 + s[i] -'0';
            if (i+1<n && isdigit(s[i+1])) continue;    //This number is not finished
            s1.push(curnum);
            //cout<<"s1 push "<<curnum<<" "<<i<<endl;      // Otherwise, this number is ready and must be pushed to stack
            curnum = 0; 
        } 
        else if(check(s[i])){
            if(s2.empty()/*||s2.top()=='('||s2.top()==')'*/){
                s2.push(s[i]);
                //cout<<"s2 push "<<i<<endl;
            }
            else if(map1.find(s2.top())->second<map1.find(s[i])->second){
                s2.push(s[i]);
                //cout<<"s2 push "<<s[i]<<" "<<i<<endl;
            }
            else if(map1.find(s2.top())->second>=map1.find(s[i])->second){
                while(1){
                    if(s2.empty()||(s1.empty())||(map1.find(s2.top())->second<map1.find(s[i])->second)){
                      break;
                    }
                    if((s1.size()>=2)&&(s2.size()>=1)&&(!s1.empty())&&!(s2.empty())){
                        do_process();
                    }
                    
                }
                s2.push(s[i]);
                //cout<<"s2 push "<<s[i]<<endl;
            }

        }
        else if(s[i]=='('){
            s2.push(s[i]);
            //cout<<"s2 push "<<s[i]<<endl;
        }
        else if(s[i]==')'){
            while(s2.top()!='('){
                do_process();

            }
            s2.pop();
            //cout<<"s2 pop ( ";
        }

    }
   
    
    while (!s2.empty()){
        do_process();
    }
    return s1.top();
}
int main(){
    char kc[]="2*(5*(3+6))/15-2";
    char kc1[]= "2*(5*(3+6))/5-2";
    cout<<duyet(kc,16);
    return 0;
}
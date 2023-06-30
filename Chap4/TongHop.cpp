#include<bits/stdc++.h>
using namespace std;
int tinhtoan(int a, int b, char c){
    if(c=='+') return a+ b;
    if(c=='-') return a-b;
    if(c=='*') return a*b;
    if(c=='/') return a/b;
    if(c=='^') return a^b;
    return 0;
}

int tinhkyphap(string s, int n){
    stack<int> a;
    for(int i=0; i<n; i++){
        if(isdigit(s[i])){
            a.push(s[i]-'0');
            //printf("push %d\n",s[i]-'0');
        }
        else{
            int a1= a.top();
            a.pop();
            int a2= a.top();
            a.pop();
            int k= tinhtoan(a2, a1, s[i]); 
            a.push(k);
            //printf("pop %d pop %d push %d\n",a1, a2, k);
        }
    }
    return a.top();
}
int douutien(char s){
    if(s=='+') return 1;
    if(s=='-') return 1;
    if(s=='*') return 2;
    if(s=='/') return 2;
    if(s=='^') return 3;
    return 0;
}
bool pheptoan(char s){
    if(s=='+') return true;
    if(s=='-') return true;
    if(s=='*') return true;
    if(s=='/') return true;
    if(s=='^') return true;
    return false;
}
string chuyendoi(string s, int n){
    vector<char> a;
    stack<char> b;
    for(int i=0; i<n; i++){
        if(isdigit(s[i])){
            a.push_back(s[i]);
        }
        else if(s[i]=='('){
            b.push(s[i]);
        }
        else if(pheptoan(s[i])){
            bool k= true;
            while(k){
                if(b.empty()||(b.top()=='(')){
                    b.push(s[i]);
                    k= false;

                }
                else if(douutien(b.top())<douutien(s[i])){
                    b.push(s[i]);
                    k= false;
                }
                else if(douutien(b.top())>=douutien(s[i])){
                    char y= b.top();
                    b.pop();
                    a.push_back(y);
                }
            }
        }
        else if(s[i]==')'){
            
            while(!b.empty()&&b.top()!='('){
                char y= b.top();
                if(pheptoan(y)){
                    a.push_back(y);
                    b.pop();
                }
                else if(y=='('){
                    b.pop();
                }
            }
            if(b.top()=='(') b.pop();
        }
    }
    while(!b.empty()){
        char y= b.top();
        b.pop();
        a.push_back(y);
    }
    string s1="";
    for(int i=0; i<a.size(); i++){
        s1+=a.at(i);
    }
    return s1;
}
int main(){
    char s[]="3*5+(4-3)*6+7/7";
    string s1= chuyendoi(s, sizeof(s)/sizeof(s[0]));
    cout<<tinhkyphap(s1, s1.length());
}
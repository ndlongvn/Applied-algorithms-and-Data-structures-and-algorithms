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

int tinhkyphap(char s[], int n){
    stack<int> a;
    for(int i=0; i<n; i++){
        if(isdigit(s[i])){
            a.push(s[i]-'0');
            printf("push %d\n",s[i]-'0');
        }
        else{
            int a1= a.top();
            a.pop();
            int a2= a.top();
            a.pop();
            int k= tinhtoan(a2, a1, s[i]); 
            a.push(k);
            printf("pop %d pop %d push %d\n",a1, a2, k);
        }
    }
    return a.top();
}
int main(){
    char s[]= "512+4*+3+";
    cout<<tinhkyphap(s, 9);
}
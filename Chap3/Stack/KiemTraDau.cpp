#include<bits/stdc++.h>
using namespace std;
bool check(char x, char y){
    if((x=='('&&y==')')||(x=='['&&y==']')||(x=='{'&&y=='}')) return true;
    return false;
}
bool kiemtradau(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if((s[i]=='(')||(s[i]=='[')||(s[i]=='{')){
            st.push(s[i]);
        }
        else{
            if(check(st.top(),s[i])){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
    
    string m="{(()}";
    cout<<kiemtradau(m);
    
}
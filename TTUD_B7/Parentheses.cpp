#include<bits/stdc++.h>
using namespace std;
int check_pair(char x, char y){
    if((x=='('&&y==')')||(x=='['&&y==']')||(x=='{'&&y=='}')) return 1;
    return 0;
}
int check(char x){
    if((x==']')||(x=='}')||(x==')')) return 0;
    return 1;
}
int parentheles(string s){
    stack<char> st;
    if(s.size()%2==1) return 0;
    for(int i=0; i<s.size(); i++){
        if(st.empty()&&(!check(s[i]))) return 0;
        if(check(s[i])) st.push(s[i]);
        if(!st.empty()&&(check_pair(st.top(), s[i]))){
            st.pop();
        }
    }
    if(!st.empty()) return 0;
    return 1;
}
int main(){
    
    string s;
    cin>>s;
    cout<< parentheles(s);
    return 0;
    

}
#include<bits/stdc++.h>
using namespace std;
bool Palindrome(string m){
    stack<char> st; deque<char> dq;
    for(int i=0; i<m.length(); i++){
        st.push(m[i]);
        dq.push_back(m[i]);
    }
    for(int i=0; i<m.length(); i++){
        if(st.top()!=*dq.begin()){
            return false;
        }
        st.pop();
        dq.pop_front();
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<Palindrome("madam");
    return 0;
}
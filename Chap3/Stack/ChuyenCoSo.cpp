#include<bits/stdc++.h>
using namespace std;
void inkq(stack<int> s1){
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
}
void chuyencoso(int x, int y){
    stack<int> st;
    while(x!=0){
        int a= x%y;
        st.push(a);
        x= x/y;
    }
    inkq(st);
}
int main(){
    int x= 13;
    chuyencoso(15,2);
    return 0;
}
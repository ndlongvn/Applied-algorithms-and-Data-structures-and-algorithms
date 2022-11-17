#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s;
    string k;
    while(1){
        cin>> k;
        if(k=="PUSH"){
            int m;
            cin>> m;
            s.push(m);
        }
        if(k=="POP"){
            if(!s.empty()){
                cout<< s.top()<<endl;
                s.pop();
            }
            else{
                cout<<"NULL"<< endl;
            }
        }
        if(k=="#") break;
    }
}
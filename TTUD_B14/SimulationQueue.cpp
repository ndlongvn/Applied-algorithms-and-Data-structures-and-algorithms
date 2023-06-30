#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    queue<int> Q;
    while(1){
        getline(cin, str);
        if(str=="#") break;
        if(str=="POP"){
            if(Q.empty()) cout<<"NULL"<<endl;
            else{
                cout<<Q.front()<<endl;
                Q.pop();
            } 
        }
        else{
            Q.push(stoi(str.substr(5, str.size()-1)));
        }
    }
}
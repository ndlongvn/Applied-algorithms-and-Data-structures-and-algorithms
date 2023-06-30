#include<bits/stdc++.h>
using namespace std;
string p1, p2, T, new_str;
void solution(){
    getline(cin, p1); 
    getline(cin, p2); 
    getline(cin, T); 
    for(int i=0; i<=T.size(); i++){
        if(T.substr(i,p1.size())==p1){
            new_str+=p2;
            i+=p1.size()-1;
        }
        else{
            new_str+=T[i];
        }
    }

}

int main(){
    new_str="";
    solution();
    cout<< new_str;
    return 0;
}
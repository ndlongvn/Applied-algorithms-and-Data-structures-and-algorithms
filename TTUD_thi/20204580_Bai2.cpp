#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int, vector<int>> a;
void solution(){
    cin>> n;
    for(int i=1; i<=n; i++){
        int u;
        cin>> u;
        a.push(u);
    } 
    string m;
    getline(cin, m); fflush(stdin);
    while(1){
        string str;
        getline(cin, str);
        // cout<< str<<endl;
        if(str=="*" ) break;
        else{
            if(str== "delete-max"){
                cout<< a.top()<<endl;
                a.pop();
            }
            else{
                int u= stoi(str.substr(7, str.size()-7));
                a.push(u);
                // sort(a.begin(), a.end());
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solution();
}
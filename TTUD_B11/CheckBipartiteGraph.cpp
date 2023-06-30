#include<bits/stdc++.h>
using namespace std;
// d[v] la khoang cach tu s den v tinh theo BFS
// 
#define N 100001
int n, m;
vector<int> A[N];
int d[N];
void input(){
    cin>> n>>m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    
}
bool BFS(int s){
    queue<int> Q;
    d[s]= 0; Q.push(s);
    while(!Q.empty()){
        int v= Q.front(); Q.pop();
        for(auto x: A[v]){
            if(d[x]!=-1){
                if((d[v]+ d[x])%2==0){
                    return false;
                }
            }
            else {
                d[x]= d[v]+ 1;
                Q.push(x);
            }
            
        }
    }
    return true;
}
int main(){
    int ans= 1;
    input();
    for(int v=1; v<=n; v++){
        if(d[v]==-1){
            int ok= BFS(v);
                if(!ok) {
                    ans= 0;
                    break;
                }           
        }
    }
    cout<<ans;
}
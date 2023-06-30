#include<bits/stdc++.h>
using namespace std;
#define N 100001
bool visited[N];
vector<deque<int>> adj;
int n, m;
void input(){
    cin>> n>> m;
    adj.resize(n+1);
    for(int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void DFS() {
    stack<int> S;
    S.push(1); 
    while(!S.empty()){
        int u= S.top();
        if(!visited[u]){
            visited[u]= true; 
            cout<<u<<" ";
        }
        if (!adj[u].empty()){
            int v= adj[u].front(); adj[u].pop_front(); 
            if(!visited[v]){
                S.push(v);
            }
        }
        else { 
            S.pop(); 
        }     
    }   
}
int main(){
    input();
    DFS();
    return 0;
}
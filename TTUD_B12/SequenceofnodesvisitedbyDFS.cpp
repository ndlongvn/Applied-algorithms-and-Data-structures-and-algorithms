#include<bits/stdc++.h>
using namespace std;
#define N 10000
int n, m;
vector<int> A[N];
bool visited[N];
vector<int> re;
void input(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        sort(A[i].begin(), A[i].end());
    }
}
void DFS(int u){
    if(!visited[u]){
        re.push_back(u);
        visited[u]= true;
    } 
    for(int i: A[u]){
        if(!visited[i]){
            // visited[i]= true;           
            DFS(i);
        }
    }
}
void DFS(){
    for(int v=1; v<= n; v++) visited[v]= false;
    for(int u=1; u<= n; u++){
        if(!visited[u]){ // visited
            DFS(u); // start to building next connected component
        }
    }

}
int main(){
    input();
    DFS();
    // sort(re.begin(), re.end());
    for(int i: re ) cout<<i<<" ";
    return 0;
}
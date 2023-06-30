#include<bits/stdc++.h>
using namespace std;
#define N 100001
int n;
vector<pair<int, int>> A[N];
int d[N], p[N];
int f[N]; 
map<pair<int, int>, int> mp; 
void input(){
    cin>> n;
    for(int i=1; i<=n; i++){
        int u, v, w;
        cin>> u>> v>> w;
        A[u].push_back(pair<int, int>(v, w));
        A[v].push_back(pair<int, int>(u, w));
    }
}
void DFS(int v){
    d[v]= 0;
    for(auto i: A[v]){
        
    }
}
void BFS(){
    for(int i=1; i<=n; i++) d[i]= 0;
    for(int u=1; u<= n; u++){
        if(d[u]==0){ // visited
            DFS(u);
        }
    }
}
int main(){

}
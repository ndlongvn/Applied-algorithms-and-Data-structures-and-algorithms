#include<bits/stdc++.h>
using namespace std;
#define N 100001
int n;
vector<pair<int, int>> A[N];
int d[N];
void input(){
    cin>> n;
    for(int i=1; i<=n-1; i++){
        int u, v, k;
        cin>>u >>v >>k;
        A[u].push_back(pair<int, int>{v, k});
        A[v].push_back(pair<int, int>{u, k});
    }
    
}
void BFS(int s){
    for(int i=1; i<=n; i++) d[i]= -1;
    queue<int> Q;
    d[s]= 0; Q.push(s);
    while(!Q.empty()){
        int v= Q.front(); Q.pop();
        for(auto x: A[v]){
            if(d[x.first]==-1){
                d[x.first]= d[v]+ x.second;
                Q.push(x.first);
            }            
        }
    }
}
int main(){
    int best= 0;
    int m= 0;
    input();
    BFS(1);
    for(int i=1; i<=n; i++){
        if(m< d[i]){
            best= i;
            m= d[i];
        }
    }
    BFS(best);
    best= 0;
    for(int i=1; i<=n; i++){
        best= max(best, d[i]);
    }
    cout<< best;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define N 1001
int n;
vector<int> A[N];
int d[N];
int distanced[N][N];
void input(){
    cin>> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            distanced[i][j]= 0;
        }
    }
    for(int i=1; i<=n-1; i++){
        int u, v, k;
        cin>>u>>v>>k;
        distanced[u][v]= k; distanced[v][u]= k; 
        A[u].push_back(v);
        A[v].push_back(u);
    }
    for(int i=1; i<=n; i++) d[i]= -1;
}
void BFS(int s){
    queue<int> Q;
    d[s]= 0; Q.push(s);
    while(!Q.empty()){
        int v= Q.front(); Q.pop();
        for(auto x: A[v]){
            if(d[x]==-1){
                d[x]= d[v]+ distanced[v][x];
                Q.push(x);
            }            
        }
    }
}
int main(){
    int best= 0;
    int m= 0;
    input();
    BFS(0);
    for(int i=1; i<=n; i++){
        if(m< d[i]){
            best= i;
            m= d[i];
        }
    }
    for(int i=1; i<=n; i++) d[i]= -1;
    BFS(best);
    best= 0;
    for(int i=1; i<=n; i++){
        best= max(best, d[i]);
    }
    cout<< best;
    return 0;
}
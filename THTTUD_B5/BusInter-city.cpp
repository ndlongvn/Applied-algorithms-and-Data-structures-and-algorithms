#include<bits/stdc++.h>
using namespace std;
#define N 5001
#define MAX 100000
int n, m, C[N], D[N];
int w[N][N]; // w[u][v] is the weight of arc(u, v)
vector<int> A[N];

void BFS(int u){
    int dis[N]; // so luong canh di qua tu u-> k
    for(int i=1; i<=n; i++) dis[i]= -1; dis[u]= 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int v= q.front(); q.pop();
        w[u][v]= C[u]; 
        for(int k: A[v]){
            if(dis[k]==-1){
                dis[k]= dis[v]+1;
                if(dis[k]> D[u]) continue;
                else q.push(k);
            }
        }
    }
}
void Dijkstra(int s, int t){
    int d[N];
    bool found[N];
    for(int i=1; i<=n; i++){
        d[i]= w[s][i]; 
        found[i]= 0;
    } 
    d[s]= 0; found[s]= 1;
    
    for(int j=1; j<n; j++){
        int k= MAX;
        int ind= 0;
        for(int i=1; i<=n; i++){
            if(!found[i]){
                if(k> d[i]){
                    ind= i;
                    k= d[i];
                }
            }
        }
        
        if(ind==t) break;
        found[ind]= 1;
        for(int i=1; i<=n; i++){
            if(w[ind][i]!=MAX && found[i]==0){
                if(d[i]> d[ind]+ w[ind][i]){
                   d[i]= d[ind]+ w[ind][i];
                }
            }     
        }
    }
    cout<< d[t]; 
}
void input(){
    cin>> n>> m;
    for(int i=1; i<=n; i++){
        cin>> C[i] >>D[i];
    }
    for(int i=1; i<=m; i++){
        int u, v;
        cin>>u >> v;
        A[v].push_back(u);
        A[u].push_back(v);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            w[i][j]= MAX;
        }
    }
    for(int i=1; i<=n; i++) BFS(i);
    Dijkstra(1, n);

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    return 0;
}
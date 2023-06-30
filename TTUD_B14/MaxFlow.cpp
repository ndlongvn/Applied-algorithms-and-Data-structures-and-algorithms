#include<bits/stdc++.h>
using namespace std;
#define N 100
int f[N][N];
int c[N][N];
int p[N];
int s, t;
int n, m;
vector<int> A[N];
void input(){
    cin>>n>>m;
    cin>>s>>t;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            c[i][j]= 0;
        }
    }
    for(int i=1; i<=m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        A[u].push_back(v);
        c[u][v]= w;
    }
}
bool findAugmentingPath(){
    queue<int> Q;
    for(int v=1; v<=n; v++) p[v]= 0; // not visited
    Q.push(s);
    while(!Q.empty()){
        int u= Q.front(); Q.pop();
        for(int i=0; i<A[u].size(); i++){
            int v= A[u][i];
            bool ok= false; // check if there is an arc (u, v)
            if(p[v]==0){ // not visited
                if(c[u][v]>0){
                    if(f[u][v]< c[u][v]) ok= true; //has arc(u, v) with weight = c[u][v]- f[u][v]

                }
                else{
                    if(f[v][u]>0) ok= true; // has arc(u, v) with weight = f[u][v]
                }
            }
            if(ok){// has an arc(u,v) in Gf
                Q.push(v); p[v]= u;
                if(v==t) return true;
            }
        }
    }
    return false;
}
int augmentFlow(){
    int ans= 1e9;
    int k= t;
    while(k!=s){
        if(c[p[k]][k]>0){
            ans= min(ans, c[p[k]][k]- f[p[k]][k]); // 
        }
        else{
            ans= min(ans, f[k][p[k]]); //
        }
        k= p[k];
    }
    k= t;
    while(k!=s){
        if(c[p[k]][k]>0){
            f[p[k]][k]= f[p[k]][k]+ ans; // (p[k], k) is an arc in G
        }
        else{
            f[k][p[k]]-= ans; // (p[k], [k]) is an arc in Gf, (k, p[k]) is an arc in G
        }
        k= p[k];
    }
    return ans;
}
void maxFlowEdmondsKarp(){
    // init with flow= 0
    for(int u=1; u<=n; u++){
        for(int v=1; v<=n; v++){
            f[u][v]= 0;
        }
    }
    int val= 0;
    while(1){
        bool ok= findAugmentingPath();
        if(!ok) break; // augmenting path is not found get max- flow -> STOP
        int delta = augmentFlow();
        val+= delta;
    }
    cout<<val;
}

int main(){
    input();
    maxFlowEdmondsKarp();
    return 0;
}
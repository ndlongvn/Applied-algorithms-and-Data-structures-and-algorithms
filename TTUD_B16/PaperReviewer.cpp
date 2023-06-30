#include<bits/stdc++.h>
using namespace std;
#define N 100
int n, m, b;
vector<int> adj[N];
bool visited[N][N]; //

int x[N]; // load for all reviewers
int y[N]; // load for all papers
int maxx;
void input(){
    cin>> n>>m>>b;
    for(int i=1; i<=n; i++){
        int k, h;
        cin>> k;
        for(int j=1; j<=k; j++){
            cin>> h;
            adj[i].push_back(h);
        }
    }
    for(int i=1; i<=m; i++) x[i] =0 ;
    for(int i=1; i<=n; i++) y[i] =0 ;
}
void solution(){   
    int maxx1= x[1];
    for(int i=2; i<=m; i++) maxx1= max(maxx1, x[i]);
    maxx= min(maxx1, maxx);
}
bool check(int i, int j){
    if (visited[i][j]) return false;
    return true;
}
void Try(int k){
    for(int i=1; i<= n; i++){
        if(y[i]<b){
            for(int j: adj[i]){
                if(check(i, j)){
                    y[i]++;
                    visited[i][j]= true;
                    x[j]++;
                    if(k==n*b) solution();
                    else Try(k+1);
                    y[i]--;
                    visited[i][j]= false;
                    x[j]--;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    maxx= 100;
    input();
    Try(1);
    if(maxx) cout<<maxx;
    else cout<<-1;
    return 0;
}
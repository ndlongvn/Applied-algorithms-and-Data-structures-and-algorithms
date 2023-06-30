#include<bits/stdc++.h>
using namespace std;
#define N 1002
int n, A[N], C[N][N], m;
vector<int> adj[N];
bool visited[N];
void input(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>A[i];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>> C[i][j];
        }
    }
    cin>>m;
    for(int i=1; i<=m; i++){
        int j, k;
        cin>>j>>k;
        adj[k].push_back(j);
    }
    for(int i=1; i<=n; i++) visited[i]= false;
}
bool check(int j){
    for(int m: adj[j]){
        if(!visited[m]) return false;
    }
    return true;

}
void check(){
    int dis= 0; A[n+1]= A[1] ;
    for(int i=1; i<=n; i++){
        if(check(A[i])){
            visited[A[i]]= true;
            if(i!=1){
                dis+= C[A[i-1]][A[i]];
            } 
        }
        else{
            cout<<-1<<endl;
            return ;
        }
    }
    cout<<dis+ C[A[n]][A[1]];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input();
    check();
    return 0;
}
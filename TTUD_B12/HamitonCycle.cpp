#include<bits/stdc++.h>
using namespace std;
#define N 100
int T, n, m;
vector<int> A[N];
bool visited[N];
int x[N];
int pai;
bool check(int x){
    if (visited[x]) return false;
    return true;
}
void Try(int k){
    for(int i: A[x[k-1]]){
        if(check(i)){
            // cout<<" with k = "<<k<<" select "<<i<<endl;
            x[k]= i;
            visited[i]= true;
            if(k==n) {
                for(int j: A[1]){
                    if(x[n]==j) pai= 1;
                }
            }
            else Try(k+1);
            visited[i]= false;
        }
    }
}
void input(){
    cin>>T;
    for(int i=1; i<= T; i++){
        cin>>n>>m;
        for(int j=1; j<=m; j++){
            int u, v;
            cin>>u>>v;
            A[u].push_back(v);
            A[v].push_back(u);
        }
        for(int j=1; j<=n; j++) visited[j]= false;
        visited[1]= true;x[1]=1;
        pai= 0;
        Try(2);
        if(pai==1) cout<<1<<endl;
        else cout<<0<<endl; 
        A[N].clear();
    }

}
int main(){
    input();
    return 0;
}
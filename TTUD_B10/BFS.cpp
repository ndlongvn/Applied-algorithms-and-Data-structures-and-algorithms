#include<bits/stdc++.h>
using namespace std;
#define N 100001
vector<int> A[N]; // A[v] is the list of adjacent nodes of v
int n, m; // number of nodes and edge
int d[N]; // d[v] is the min distance from i=the starting node to v during BFS
void input(){
    cin>> n>> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void BFS(int u){
    d[u]= 0; // u is starting point
    queue<int> Q;
    Q.push(u);
    while(!Q.empty()){
        int v= Q.front(); Q.pop();
        for(int i=0; i< A[v].size(); i++){
            int x= A[v][i];
            if(d[x]==-1){
                d[x]= d[v]+1;
                Q.push(x);
            }
        }
    }

}
int main(){
    input();
    int u= 3;
    for(int v= 1; v<= n; v++){
        d[v]= -1;
    }
    BFS(u);
    for(int v= 1; v<= n; v++) cout<<"d["<<v<<"]"<<d[v]<<endl;
    return 0;
}
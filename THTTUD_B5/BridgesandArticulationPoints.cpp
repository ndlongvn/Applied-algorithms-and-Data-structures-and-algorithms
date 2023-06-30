#include<bits/stdc++.h>
using namespace std;
#define N 100001
int n, m;
// low[v] luu tru thoi diem som nhat ta di tham dinh to tien ma con chau v co canh nguoc lai
// low[u]= min(d[u], d[y]: voi (x, y) la canh nguoc x la u hoac con chau cua u, y la to tien cua u)

// u la cut vertex neu: u la goc va co nhieu hon 1 con, u khong la goc va khong ton tai con v 
// cua u ko co canh nguoc noi len to tien cua u 
vector<int> A[N];
int vertex, time_, numB;
int d[N], low[N];
int parent[N], visited[N], cutVertex[N];

void DFS(int u){
    d[u]= low[u]=++time_;
    int numChild= 0;
    for(int v: A[u]){
        if(d[v]==0){
            numChild++;
            parent[v]= u;
            DFS(v);
            low[u]= min(low[u], low[v]);
            if(low[v]> d[u]) numB++;
            // case 1: u la goc va co nhieu hon 1 con
            if(parent[u]==u && numChild>1) cutVertex[u]= 1;
            // case2: u khong la goc cua cay DFS va gia tri low dinh con chau > = d[u]:
            if(parent[u]!=u && low[v]>= d[u]) cutVertex[u]= 1;           
        }
        else if(parent[u]!= v) low[u]= min(low[u], d[v]);
    }
}
void input(){
    cin>> n>> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        parent[i]= i;
        cutVertex[i]= 0;
    }
    int time_= 0; numB= 0;
    for(int i=1; i<=n; i++){
        if(d[i]==0) DFS(i);
    }
    vertex= 0;
    for(int i= 1; i<=n; i++){
        if(cutVertex[i]) vertex++;
    }
    cout<<vertex<<" "<<numB;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input();
    return 0;
}
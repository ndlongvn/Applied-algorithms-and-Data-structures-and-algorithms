#include<bits/stdc++.h>
using namespace std;
#define N 100001
struct Edge{
    int u, v, w;
};
vector<Edge> T;
vector<Edge> E;
int n, m;
int p[N], r[N];
int sum;
void make_set(int x){
    p[x]= x;
    r[x]= 0;
}
int find_set(int x){
    if(x==p[x]) return x;
    p[x]= find_set(p[x]);
    return p[x];
}
void unify_set(int x, int y){
    if(r[x]> r[y]) p[y]= x;
    else p[x]= y;
    if(r[x]==r[y]) r[y]++;
}
int Kruskal(){
    sum= 0;
    sort(E.begin(), E.end(), [](Edge x, Edge y){
        return x.w< y.w;
    });
    for(int i= 1; i<=n; i++) make_set(i);
    for(int i= 0; i< E.size(); i++){
        int u= E[i].u, v= E[i].v;
        int ru= find_set(u), rv= find_set(v);
        if(ru!= rv){
            T.push_back(E[i]);
            unify_set(ru, rv);
            sum+= E[i].w;
            if(T.size()==n-1) break;          
        }
    }
    return sum;
}
void input(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int u, v, w;
        cin>> u>>v >>w;
        E.push_back(Edge{u, v, w});
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    cout<< Kruskal();
    return 0;
}
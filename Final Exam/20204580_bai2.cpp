#include<bits/stdc++.h>
using namespace std;
#define N 100001
struct Edge{
    int u, v, w;
};
vector<Edge> T;
vector<Edge> edg;
vector<Edge> E;
vector<int> ver;
int n, m, k;
int p[N], r[N];
int sum;
set<Edge> Q;
void input(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int u, v, w;
        cin>>u>>v>> w;
        edg.push_back(Edge{u, v, w});
        // E.push_back(Edge{u, v, w});
    }
    cin>>k;
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        ver.push_back(x);
    }
    for(Edge j: edg){
        bool check= false;
        bool check2= false;
        for(int i: ver){
            if((j.u==i)){
                check= true;
                break;
            }

        }
        for(int i: ver){
            if((j.v==i)){
                check2= true;
                break;
            }
            
        }
        if(check&&check2) E.push_back(j);
    }
}
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
    // for(int i= 1; i<=n; i++) make_set(i);
    for(int i: ver) make_set(i);
    for(int i= 0; i< E.size(); i++){
        int u= E[i].u, v= E[i].v;
        int ru= find_set(u), rv= find_set(v);
        if(ru!= rv){
            T.push_back(E[i]);
            unify_set(ru, rv);
            sum+= E[i].w;
            if(T.size()==ver.size()-1) break;          
        }
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    cout<< Kruskal();
    return 0;
}
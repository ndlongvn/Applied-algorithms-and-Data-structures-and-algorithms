#include<bits/stdc++.h>
using namespace std;
#define N 100001
#define INF 1e9
#define pii pair<int, int> // first is weight, second is key
int n, m, s, t;
struct Arc{
    int nod;
    int w;
    Arc(int _nod, int _w){
        nod= _nod;
        w= _w;
    }
};

vector<Arc> A[N];

set<int> nonfixed; // set of node we dont have shortest path from s to  
int d[N], p[N]; // d is weight from s; p is node first
void input(){
    cin>> n>> m;
    for(int i=1; i<=m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        A[u].push_back(Arc(v, w));
    }
    cin>>s>>t;
}
int selectMin(){
    int minD= INF; int self= -1;
    for(int v: nonfixed){
        if(d[v]< minD){
            minD= d[v];
            self= v;
        }
    }
    return self;
}
void dijkstra(){
    for(int v=1; v<= n; v++){
        d[v]= INF;
    }
    for(int i=0; i< A[s].size(); i++){
        Arc a= A[s][i];
        d[a.nod]= a.w; p[a.nod]= s;
    }
    d[s]= 0;
    for(int v=1; v<=n; v++){
        if(v!=s) nonfixed.insert(v);
    }
    while(!nonfixed.empty()){
        int u= selectMin();
        if(u==t) break;
        nonfixed.erase(u);
        for(int i=0; i<A[u].size(); i++){
            Arc a= A[u][i];
            int v= a.nod;         
            if(d[v]>d[u]+ a.w){
                d[v]= d[u]+ a.w;
                p[v]= u;
            }
        }
    }
    cout<< d[t];
}
void dijkstraPriorityQueue(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i=0; i< A[s].size(); i++){
        Arc a= A[s][i];
        pq.push(make_pair(a.w, a.nod));
    }
    for(int v=1; v<= n; v++){
        d[v]= INF;
    }
    for(int i=0; i< A[s].size(); i++){
        Arc a= A[s][i];
        d[a.nod]= a.w;
    }
    d[s]= 0;
    while(!pq.empty()){
        int u= pq.top().second; pq.pop();
        if(u==t) break;
        for(int i=0; i<A[u].size(); i++){
            Arc a= A[u][i];
            int v= a.nod;         
            if(d[v]>d[u]+ a.w){
                d[v]= d[u]+ a.w;   
                pq.push(make_pair(d[v], v));            
            }
            
        }
    }
    cout<< d[t];
}
int main(){
    input();
    dijkstraPriorityQueue();    
    return 0;
}
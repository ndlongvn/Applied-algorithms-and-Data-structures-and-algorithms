#include<bits/stdc++.h>
using namespace std;
#define N 100001
vector<int> A[N]; // A[v] is the list of adjacent nodes of v
int n, m; // number of nodes and edge
int nbCC; // number of connected components
int cc[N];
void input(){
    cin>> n>> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void DFS(int u){
    cc[u]= nbCC;
    for(int i=0; i< A[u].size(); i++){
        int v= A[u][i]; // v is the i-th adjacent nodes of u
        if(cc[v]==0){ // v is not visited
            DFS(v);
        }
    }
}
void DFS(){
    for(int v=1; v<= n; v++) cc[v]= 0; // all ofs are not visited at the beginning
    nbCC= 0;
    for(int u=1; u<= n; u++){
        if(cc[u]==0){ // visited
            nbCC++; // start to building next connected component
            DFS(u);
        }
    }

}
// void printResult(){
//     for(int c=1; c<= nbCC; c++){
//         cout<< "connected components "<<i<<":";
//         for(int v=1; )
//     }
// }
int main(){
    input();
    DFS();
    cout<< nbCC;
    return 0;
}
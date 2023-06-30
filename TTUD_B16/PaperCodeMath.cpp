#include<bits/stdc++.h>
using namespace std;
#define N 100
int n, m, b;
vector<int> adj[N];
bool visited[N][N]; //
/*
    The chair of a conference must assign scientific
    papers to reviewers in a balance way. There are N
    papers 1, 2, …, N and M reviewers 1, 2, …, M. Each
    paper i has a list L(i) of reviewers who are willing
    to review that paper. A review plan is an assignment
    reviewers to papers. The load of a reviewer is the number
    of papers he/she have to review. Given a constant b,
    compute the assignment such that
    Each paper is reviewed by exactly b reviewers.
    The maximum load of all reviewers is minimal 
        Input
    Line 1 contains N, M and b
    Line i+1 (i = 1,…,N) contains a positive integer k
    followed by k positive integers representing the list L(i)
        Output
    Unique line contains the maximum load for all reviewers of the
    solution found or contains -1 if no solution found
*/
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    maxx= 100;
    input();
    bool che= false;
    for(int i=1; i<=n; i++){
        if(adj[i].size()< b){
            che= true;
            break;
        }
    }
    if(che) cout<<-1;
    else{
        cout << ceil(n * b / m)+1;
    }
    
}
#include<bits/stdc++.h>
using namespace std;
#define N 100
int n, c[N][N]; // n, distance
int visited[N]; // visited
int best; // solution
int curr; // current
int p[N]; // trace
int minC;
bool pas;
void input(){
    minC= 1e9;
    cin>> n;
    for(int i= 0; i<= 2*n; i++){
        for(int j= 0; j<= 2*n; j++){
            cin>> c[i][j];
            if(i!=j) minC= min(minC, c[i][j]);
        }
    }
}
bool check(int u, int k){
    if(visited[u]) return false;
    if(k==1) return u<= n;
    if(p[k-1]>n) return u<= n;
    if(p[k-1]<= n) return u==p[k-1]+ n;
    return true;
}
void solution(){
    best= min(best, curr+ c[p[2*n]][0]);
}
void Try(int k){
    if(pas){
        int i= p[k-1]+ n;
        p[k]= i;
        curr+= c[p[k-1]][i];
        visited[i]= true;
        pas= false;
        if(k==2*n) solution();
        else{
            if(best> curr+ (2*n-k+1)*minC){
                Try(k+1);
            }
        } 
        curr-= c[p[k-1]][i];
        visited[i]= false;
        pas= true;
    }
    else{
        for(int i=1; i<=n; i++){
            if(check(i, k)){
                p[k]= i;
                curr+= c[p[k-1]][i];
                visited[i]= true;
                pas= true;
                if(k==2*n) solution();
                else{
                    if(best> curr+ (2*n-k+1)*minC){
                        Try(k+1);
                    }
                } 
                curr-= c[p[k-1]][i];
                visited[i]= false;
                pas= false;
            }
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=1; i<=2*n; i++) visited[i]= false;
    best= 1e9;
    curr= 0;
    pas= false;
    p[0]= 0;
    visited[0]= true;
    input();
    Try(1);
    cout<< best ;
    return 0;
}
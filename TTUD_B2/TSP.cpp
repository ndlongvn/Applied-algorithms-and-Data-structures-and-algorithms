#include<bits/stdc++.h>
using namespace std;
# define N 20
int x[N];
int n;
int c[N][N];
bool mark[N];
int f;
int f_min;
int Cm;
bool check(int v, int k){
    return mark[v]==false;
}
void solution(){
    if(f+c[x[n]][x[1]]< f_min){
        f_min= f+ c[x[n]][x[1]];
    }
}
void Try(int k){
    for(int v= 1; v<= n; v++){
        if(check(v, k)){
            x[k]= v;
            f= f+ c[x[k-1]][x[k]];
            mark[v]= true;
            if(k==n) solution();
            else{
                if(f+ Cm*(n-k+1)<f_min) Try(k+1);
            }
            mark[v]= false;
            f= f- c[x[k-1]][x[k]];
        }
    }
}
void input(){
    cin>> n;
    Cm= 1e9;
    for(int i= 1; i<=n; i++){
        for (int j= 1; j<=n; j++){
            cin>>c[i][j];
            if(c[i][j]< Cm && i!=j) Cm= c[i][j];
        }
    }
}
int main(){
    input();
    for(int i=1; i<=n; i++) mark[i]= false;
    f= 0;
    x[1]= 1; mark[1]= true;
    f_min= 1e9;
    Try(2);
    cout<< f_min;
    return 0;
}
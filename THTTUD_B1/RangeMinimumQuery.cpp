#include<bits/stdc++.h>
using namespace std;
#define N 1000001
#define LOGMAX 20
int ma[N];
int matrix[N][LOGMAX];
void preprocess(int n){
    for(int i=0; i<n; i++){
        matrix[i][0]= ma[i];
    }
    for(int j=1; (1<<j)<= n; j++){
        for(int i=0; i+ (1<<j)<= n; i++ ){
            matrix[i][j]= min(matrix[i][j-1], matrix[i+ (1<<j-1)][j-1]);
        }
    }
}
int select_min(int i, int j){
    int k= floor(log2(j-i+1));
    return min(matrix[i][k], matrix[j- (1<<k)+ 1][k]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout.tie(0);
    int m, n;
    long long re= 0;
    cin>> n;   
    for(int v=0; v< n; v++){
        cin>> ma[v];
    }
    preprocess(n);
    cin>> m;
    int i, j;
    for(int v=0; v< m; v++){
        cin>> i>> j;
        long long mint= select_min(i, j);
        re+= mint;
    }
    cout<< re;
}
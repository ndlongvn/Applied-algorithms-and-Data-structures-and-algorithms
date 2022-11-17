#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
int a[MAX];
int M[MAX][25];
int n;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>> a[i];
        M[i][0]= a[i];
    }
    for(int j=1; j<=log2(n); j++){
        for(int i=1; i<=n-(1<<j)+1; i++){
            M[i][j]= min(M[i][j-1], M[i+(1<<j)-1][j-1]);
        }
    }
    cin>> m;
    long long re= 0;
    for(int v=1; v<=m; v++){
        int i, j;
        cin>>i>>j;
        int k= log2(j-i+1);
        int ans= min(M[i][k], M[j-(1<<k)+1][k]);
        re+= ans;
    }
    cout<< re;
}
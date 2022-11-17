#include<bits/stdc++.h>
using namespace std;
# define m 1000000007
int C[1000][1000];
int Cal(int k, int n){
    if (C[k][n]!=0) return C[k][n];
    else{
        // int h= C[k][n-1]+ C[k-1][n-1];
        int h= ((Cal(k-1, n-1)%m)+ (Cal(k, n-1)%m))%m;
        C[k][n]= h;
        return h;
    }
    return 0;    
}
int main(){
    int k, n;
    cin>> k>>n;
    for(int i=0; i<n; i++){
        for(int j= 0; j<n; j++){
            if(i==0) C[i][j]= 1;
            if (i==j) C[i][j]= 1;
            if (i==1) C[i][j]= j;
        } 
    }
    cout<< Cal(k, n);
}
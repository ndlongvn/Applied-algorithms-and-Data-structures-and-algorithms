#include<bits/stdc++.h>
using namespace std;
int D[1000][1000]={};
int dequyconho(int n, int k){
    if (k>n) return -1;
    if (k==0||k==n) return 1;
    if (D[n][k]!=0) return D[n][k];
    else{
        D[n][k]= dequyconho(n-1, k-1)+ dequyconho(n-1, k);
        return D[n][k];
    }
}

int dequy(int n, int k){
    if (k==0||k==n) return 1;
    if (k>n) return -1;
    else {
        return dequy(n-1, k)+ dequy(n-1,k-1);
    }
    return 0;
}
int main(){
    //cout<< dequy(100,4);
    cout<<dequyconho(100,4)<<endl;
    cout<<D[0][0];
    return 0;
}
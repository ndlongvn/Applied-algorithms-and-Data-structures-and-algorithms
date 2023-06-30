#include<bits/stdc++.h>
using namespace std;
int n, M;
int a[1000];
int T;
int counted=0;
void solution(){

}
bool check(int i, int k){
    if(k==n) {
        if(T+i*a[k]>M) return false;
    }
    return true;
}
void Try(int k){
    for(int i=1; i<=M-T-(n-k); i++){
        if(check(i, k)){
            T+=a[k]*i;
            if(k==n){
                if(T==M) counted++;
            }
            else{
                Try(k+1);
            }
            T-=a[k]*i;
        }
    }
}
int main(){
    cin>>n>>M;
    a[0]= 0;
    T=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    Try(1);
    cout<<counted;
}
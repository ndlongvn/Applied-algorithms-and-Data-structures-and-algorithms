#include<bits/stdc++.h>
using namespace std;
#define N 1000
int n, k1, k2; // khoi tao bien
int S0[N]; // voi s0[i] la cach lap lich den ngay thu i va ngay thu i nghi
int S1[N]; // voi s0[i] la cach lap lich den ngay thu i va ngay thu i lam
// S0[i]= S1[i-1]
// S1[i]= sigma(S[i- j]) voi j= k1, k2
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k1>>k2;
}
void proc(){
    for(int i=1; i<= n; i++){
        S0[i]= 0; S1[i]= 0;
    } 
    S0[1]= 1; S1[k1]= 1; S0[0]= 1;

    for(int i= k1+1; i<= n; i++){
        S0[i]= S1[i-1]; S1[i]= 0;

        for(int j= k1; j<= k2; j++){
            if(i-j>=0){
                S1[i]= S1[i]+ S0[i-j];
            }
        }
    }
    int rs= S0[n]+ S1[n];
    cout<<rs;
}
int main(){
    input();
    proc();
    return 0;
}

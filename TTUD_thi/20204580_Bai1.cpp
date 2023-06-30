#include<bits/stdc++.h>
using namespace std;
#define N 100001
int a[N];
int b[N];
int n, k, m;
void input(){
    cin>> n>> k>> m;
    for(int i=1; i<=n; i++) cin>> a[i];
    b[0]= 0;
    for(int i=1; i<=n; i++){
        b[i]= b[i-1]+ a[i];
        // cout<< b[i]<<endl;
    }
}
void solution(){
    int ans= 0;
    for(int i=0; i<= n- k; i++){
        if((b[i+k]- b[i])==m) ans++;
    }
    cout<< ans;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    return 0;
}
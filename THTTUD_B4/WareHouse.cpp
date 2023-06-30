#include<bits/stdc++.h>
using namespace std;
#define nMax 1001 
int a[nMax], t[nMax], f[nMax][nMax]; // f[i][k] la di qua tat ca cac kho tu 1 den i va phai di qua i va di het thoi gian t < T
int n, T, D, res;
void input(){
    cin >> n >> T>> D;
    for(int i=1; i<=n; i++) cin>> a[i];
    for(int i=1; i<=n; i++) cin>> t[i];
}
void proc(){
    for(int i= 1; i<= n; i++){
        for(int k= t[i]; k<= T; k++){
            for(int j= max(0, i-D); j<= i-1; j++){
                f[i][k] = max(f[i][k], f[j][k- t[i]]+ a[i]);
            }
            res= max(res, f[i][k]);
        }
    }
    cout<< res<< endl;
}
int main(){
    input();
    proc();
    return 0;
}
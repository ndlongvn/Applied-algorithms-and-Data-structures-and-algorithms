#include <bits/stdc++.h>
using namespace std;

#define N 100001
int a[N];
int n;
int cnt1[N], cnt2[N];
void input(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
}
int main() {
    input(); 
    cnt1[1]= 0;
    cnt2[1]= a[1];
    for (int i= 2; i<= n; i++) {
        cnt2[i]= cnt1[i- 1] + a[i];
        cnt1[i]= max(cnt1[i-1], cnt2[i-1]); 
    }
    cout<<max(cnt1[n], cnt2[n]);
    return 0;
}
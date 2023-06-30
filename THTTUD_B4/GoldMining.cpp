#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int n, L1, L2, ans;
int a[N];
int S[N];
void solve(){
    deque<int> d; // luu tru chi so cac ung cu vien j tham gia vao xac dinh bai toan con S[j]
    ans= 0;
    for(int i=1; i<= n; i++){
        while(!d.empty()&&(d.front() < i-L2)) d.pop_front();
        int j= i- L1;
        if(j>= 1){
            while(!d.empty()&&(S[d.back()]< S[j])) d.pop_back();
            d.push_back(j);
        }
        S[i]= a[i]+ (d.empty() ? 0 : S[d.front()]);
        ans= max(ans, S[i]);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>> n >> L1>> L2;
    for(int i=1; i<=n; i++) cin>> a[i];
    solve();
    cout<< ans;
    return 0;
}
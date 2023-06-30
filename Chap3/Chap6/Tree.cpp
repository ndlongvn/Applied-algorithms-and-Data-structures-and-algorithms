#include<bits/stdc++.h>
using namespace std;
bool dk(int k, int key){
    return k>= key;
}
int tinh(int k, int *a, int n){
    int tong= 0;
    for(int i=0; i<n; i++){
        if(a[i]>=k) tong+= a[i]-k;
    }
    return tong;
}
int binary_search(int *a, int lo, int hi, int key, int n){
    while(lo+1< hi){
        int mid= lo+ (hi- lo)/2;
        if(dk(tinh(mid, a, n), key)) lo= mid;
        else hi= mid- 1;
        cout<<lo<<" "<<hi<<"\n";
    }
    return lo;
}
int main(){
    int n, m;
    int a[n];
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>> a[i];
    // for(int i=0; i<n; i++) cout<<a[i];
    // cout<<m;
    cout<<binary_search(a, 10, 20, m, n);
}
#include<iostream.h>
using namespace std;
bool check(int cur, int key){
    if(cur<= key) return true;
    return false;
}
int tim_kiem(int *sum,int *a,int lo, int hi, int key ){
    int k= lo;
    while(lo <hi){
        int mid= lo+ (hi-lo)/2;
        if(check(key+ sum[k]-a[k],sum[mid])){
            hi= mid;
        }
        else{
            lo= mid+ 1 ;
        }
    }
    if(check(sum[lo], key+ sum[k]-a[k])) return lo;
    return -1;
}
int main(){
    int n, key;
    int a[n];
    cin>>n>>key;
    for(int i=0; i<n; i++) cin>>a[i];
    int sum[n];
    sum[0]= a[0];
    for(int i=1; i<n; i++) sum[i]= sum[i-1]+ a[i];
    int maxt= 0;
    for(int i=0; i<n; i++){
        int j= tim_kiem(sum, a, i, n-1, key);
        maxt= max(maxt, j-i+1);
    }
    cout<<maxt;
}
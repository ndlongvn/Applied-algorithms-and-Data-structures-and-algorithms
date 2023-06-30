#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int n, a[N];
int main(){
    cin>> n;
    for(int i=0; i<n; i++) cin>> a[i];
    int counted= 0;
    for(int i=1; i<n-1; i++ ){
        if((a[i]> a[i-1])&&(a[i]>a[i+1])) counted++;
    }
    cout<<counted;
    return 0;
}
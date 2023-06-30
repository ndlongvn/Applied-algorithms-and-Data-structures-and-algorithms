#include<bits/stdc++.h>
using namespace std;
#define N 100
int a[N];
int n;
void solution(){
    for(int i=1; i<=n; i++){
        cout<<a[i];
    }
    cout<<endl;
}
void Try(int k){
    for(int i=0; i<=1; i++){
        a[k]= i;
        if(k==n) solution();
        else Try(k+1);
    }
}
int main(){
    cin>>n;
    Try(1);
    return 0;
}
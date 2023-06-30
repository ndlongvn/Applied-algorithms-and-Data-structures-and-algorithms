#include<bits/stdc++.h>
using namespace std;
int a[1000];
int k=1;
void in(int n){
    cout<<"Lan thu "<<k++<<" ";
    for(int i=1; i<=n; i++){
        cout<<a[i];
    }
    cout<<endl;
}
bool check(int k, int j){
    for(int i=1; i<k; i++){
        if(j==a[i]||abs(k-i)==abs(a[i]-j)){
            return false;
        }
    }
    return true;
}
void Try(int j, int n){
    for(int i=1; i<=n; i++){
        if(check(j,i)){
            a[j]=i;
            if(j==n) in(n);
            else Try(j+1,n);
        }
    }
}
int main(){
    Try(1,5) ;
    if(k==1) cout<<"khong co ";
    return 0;
}
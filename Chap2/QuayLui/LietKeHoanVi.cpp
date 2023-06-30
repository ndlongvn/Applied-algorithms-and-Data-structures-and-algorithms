#include<bits/stdc++.h>
using namespace std;
int a[1000];
int k=1;
void in(int n){
    cout<<"Hoan vi "<<k++<<" ";
    for( int i=1; i<n+1; i++ ){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
bool check(int k, int j){
    for( int i=1; i<k; i++){
        if (a[i]==j){
            return false;
        }
    }
    return true;
}
void HoanVi( int j, int n){
    for(int i=1; i<=n; i++){
        if(check(j,i)){
            a[j]=i;
            if(j==n) in(n);
            else HoanVi(j+1, n);
            //a[j]=0;
        }
        
    }
}
int main(){
    HoanVi(1,5);
    return 0;
}
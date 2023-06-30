#include<bits/stdc++.h>
using namespace std;
int a[100];
int k=1;
void in(int n){
    cout<<"lan "<<k++<<" ";
    for( int i=1; i<=n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
bool check(int k, int j){
    for(int i=1; i< k; i++ ){
        if(a[i]==j) return false;
    }
    return true;
}
void Try(int j, int n, int m){
    for(int i=1; i<=n; i++){
        if(check(j,i)){
            a[j]=i;
            if (j==m) in(m);
            else{
                Try(j+1, n, m);
            } 
        }
    }
}
int main(){
    Try(1,3,2);
    return 0;
}
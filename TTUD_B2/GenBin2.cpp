#include<bits/stdc++.h>
using namespace std;
int a[100];
int n;
void in(){
    for(int i=1; i<=n; i++){
        cout<< a[i];
    }
    cout<< endl;
}
bool check(int j, int k){
    if (k==1) return true;
    if (a[k-1]+ j<= 1){
        return true;
    }
    return false;
}
void Try(int k){
    for (int i= 0; i< 2; i++){
        if(check(i, k)){
            a[k]= i;
            if (k==n) in();
            else{
                Try(k+1);
            }
        }
    }
}
int main(){
    cin>> n;
    Try(1);
}
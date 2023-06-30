#include<bits/stdc++.h>
using namespace std;
int a[1000];
int ct= 1;
void inTT(int n){
    cout<<"lan "<<ct++<<" ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void Try(int k, int n){
    for(int y=0; y<=1; y++){
        a[k]=y;
        if(k==n) inTT(n);
        else Try(k+1, n);
    }
}
int main(){
    Try(1, 3);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int check(int n){
    int k=0;
    if(n==1) return 5;
    if(n==2) return 10;
    for(int i=2; i<n; i++){
        //int j= pow(5,i);
        for(int h=1; h<=(pow(5,i)-pow(5,i-1))/5; h++){
            k+=i-1;
            if(k>=n) return 5*(h-1)+pow(5,i-1);
        }
    }
    return 0;
}
int main(){
    cout<<check(10);
}
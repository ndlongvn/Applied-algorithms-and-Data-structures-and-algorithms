#include<bits/stdc++.h>
using namespace std;
int luythua(int j, int n){
    if(n==0) return 1;
    if(n%2!=0) return j*luythua(j, n-1);
    else{
        int tmp= luythua(j, n/2);
        return tmp*tmp;
    }
    return 0;
}
int main(){
    cout<<luythua(2,3);
    return 0;
}
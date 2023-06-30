#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    if (n>=2) return fibonacci(n-1)+fibonacci(n-2);
    return 0;
}
int dynamic(int n){
    int i=0;
    int j=1;
    for(int k=0; k<n-1; k++){
        j=j+i;
        i=j-i;
    }
    return j;
}
int main(){
    cout<< fibonacci(5);
    cout<< dynamic(5);
    return 0;
}
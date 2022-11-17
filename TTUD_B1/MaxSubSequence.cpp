#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    long long a[t];
    for(long long i=0; i<t; i++){
        cin >>a[i];
    }
    long long a1= a[0];
    long long b1= a[0];
    for(long long i=1; i<t; i++){
        a1= max(a[i], a1+ a[i]);
        b1= max(b1, a1);
    }
    cout<< b1;
    return 0;
}
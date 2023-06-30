#include<bits/stdc++.h>
using namespace std;
int dequy(int n){
    if (n<0) return -1;
    if (n==0) return 1;
    if (n>=1) return dequy(n-1)*n;
    return 0;
}
int dynamic(int n){
    int ans=1;
    if (n<0) return -1;
    if (n==0) return 1;
    if (n==1) return 1;
    if(n>=2){
        for(int i=2; i<n+1; i++){
            ans*=i;
        }
        return ans;
    }
    return 0;
}
int main(){
    cout<< dequy(5)<<endl;
    cout<<dynamic(5);
    return 0;
}
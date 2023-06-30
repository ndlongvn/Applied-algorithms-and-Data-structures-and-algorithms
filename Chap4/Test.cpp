#include<bits/stdc++.h>
using namespace std;
int check(int n){
    int i=0;
    int h=5;
    while(1){
        int k=0;
        int j=h;
        while(j%5==0&&j>0){
            k+=1;
            j=j/5;
        }
        cout<<i<<" +"<<k<<" "<<"vs "<<h<<endl;
        i+=k;
        if(i>=n) break;
        h+=5;
    }
    return h;
}
int main(){
    cout<<check(6);
}
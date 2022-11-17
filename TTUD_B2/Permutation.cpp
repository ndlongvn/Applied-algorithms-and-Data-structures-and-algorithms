#include<bits/stdc++.h>
using namespace std;
int a[100];
bool mark[100];
int n;
void in(){
    for (int i=1; i<=n; i++){
        cout<<a[i]<< " ";
    }
    cout<<endl;
}
bool check(int i, int k){
    // for(int i=1; i<k; i++){
    //     if (mark[a[i]]){
    //         return false;
    //     }
    // }
    return mark[i]==false;
}
void Try(int k){
    for(int i=1; i<= n; i++){
        if(check(i, k)){
            a[k]= i;
            mark[i]= true;
            if(k==n) in();
            else Try(k+1);
            mark[i]= false;
        }
    }
}
int main(){
    cin>>n;
    Try(1);
}
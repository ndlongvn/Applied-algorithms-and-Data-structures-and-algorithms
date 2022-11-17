#include<bits/stdc++.h>
using namespace std;
int k, n;
bool used[1000];
int a[1000];
void input(){
    cin>> k>> n;
    for(int i=1; i<=n; i++){
        used[i]= false;
    }
    for(int i=1; i<=k; i++){
        a[i]= 0;
    }
}
void solution(){
    for(int i=1; i<=k; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
bool check(int v){
    if(used[v]) return false;
    return true;
}
void Try(int v){
    for(int i=a[v-1]+1; i<= n; i++){
        if(check(i)){
            a[v]= i;
            used[i]= true;
            // cout<<v<<" has "<<i<<endl;
            if(v==k) solution();
            else{
                Try(v+1);
            }
            used[i]= false;
        }
    }
}
int main(){
    input();
    Try(1);
    return 0;
}
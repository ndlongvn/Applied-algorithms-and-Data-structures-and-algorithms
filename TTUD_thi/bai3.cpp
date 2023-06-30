#include<bits/stdc++.h>
using namespace std;
#define N 30
int n, a, b;
int arr[N];
int cur;
int sum;
int p[N];
bool visited[N];
void input(){
    cin>> n>> a>> b;
    for(int i=1; i<=n; i++) cin>> arr[i];
}
bool check(int u, int k){
    if(visited[u]) return false;
    // if(cur+ arr[u] > b) return false;
    if(u< p[k-1]) return false;
    return true;
}
void Try(int k){
    for(int i=1; i<=n; i++){
        if(check(i, k)){
            cur+= arr[i];
            p[k]= i;
            visited[i]= true;
            if((a <=cur) && (cur<= b)){
                sum++;
                // for(int m=1; m<=k; m++) cout<< arr[p[m]]<<" ";
                // cout<<endl;
            } 
            Try(k+1);
            cur-= arr[i];
            visited[i]= false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    input();
    sum= 0; cur= 0;
    Try(1);
    cout<<sum;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define N 100001
int n;
int w[N];
vector<int> A[N];
bool visited[N];
list<int> pre;
int sum;
int best;
void input(){
    cin>> n ;
    for(int i=1; i<=n; i++){
        cin>>w[i];
    } 
    for(int i=1; i<=n-1; i++){
        int u, v;
        cin>>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }   
}
void solution(){
    // cout<<"sequence ";
    best= max(best, sum);
    cout<<best<<endl;
}
void Try(int k){
    for(int i: pre){
        if((!visited[i])){
            sum+= w[i];
            visited[i]= true;
            list<int> j;
            cout<<endl;
            pre.remove(i);
            for(int k: A[i]){
                pre.remove(k);
            }
            if(pre.empty()) solution();
            else Try(k+ 1);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    for(int i=1; i<=n; i++){
        visited[i]= false;
        pre.push_back(i);
    }
    best= 0; sum = 0;
    
    // for(int i=1; i<= n; i++){
    //     sum= w[i]; 
    //     Try(2); 
    //     best= max(best, sum);
    // }
    Try(1); 
    cout<< best;
    return 0;
}
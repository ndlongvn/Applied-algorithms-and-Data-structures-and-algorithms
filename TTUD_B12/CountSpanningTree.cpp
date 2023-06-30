#include<bits/stdc++.h>
using namespace std;
#define N 100
int n, m;
vector<int> A[N];
bool visited[N];
int x[N];
int cnt;
vector<int> node;
void input(){
    cin>> n>> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        A[v].push_back(u);
        A[u].push_back(v);
    }
}
void solution(){
    for(int i: node) cout<<i<<" ";
    cout<<endl;
    cnt++;
    // cout<< cnt<< endl;
}
void Try(int k, int h){
    for(int j: node){
        for(int i: A[j]){
            if(!visited[i]){
                visited[i]= true;
                node.push_back(i);
                if(k==h) solution();
                else Try(k+1, h);
                visited[i]= false;
                node.erase(node.end()-1);
            }
        }
    }
    
}
int main(){
    cnt= 0;
    input();
    for(int i=1; i<=n; i++){
        for(int k=2; k<=n; k++){
            node.clear();
            for(int j=1; j<= n; j++) visited[j]= false;
            visited[i]= true;
            node.push_back(i);
            Try(2, k);
        }        
    }
    cout<< cnt;
    return 0;

}
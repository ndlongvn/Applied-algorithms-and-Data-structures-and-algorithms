#include<bits/stdc++.h>
using namespace std;
#define N 10001
int n, m;
int d[N];
vector<int> A[N];
bool finish[N];
bool compare(int a, int b){
    bool x= true;
    bool y= true;
    for(int u: A[a]){
        if(!finish[u]){
            x= false;
            break;
        }
    } 
    for(int u: A[b]){
        if(!finish[u]){
            y= false;
            break;
        }
    } 
    if(x== true &&y== false) return true;
    else if(x==false && y==true) return false;
    else if(x==true && y==true) return d[a]< d[b];
    return true;
}
// struct CompareHeight {
//     bool operator()(int const& p1, int const& p2)
//     {
//         // return "true" if "p1" is ordered
//         // before "p2", for example:
//         return p1.height < p2.height;
//     }
// };
void input(){
    cin>>n >> m;
    for(int i=1; i<= n; i++) cin>>d[i];
    for(int i=1; i<= m; i++){
        int u, v;
        cin>>u >>v;
        A[v].push_back(u);
    }
}
void solution(){
    deque<int> k;
    for(int i=1; i<=n; i++) k.push_back(i);
    int ans= 0;
    while(n--){
        sort(k.begin(), k.end(), compare);
        ans+= d[k[0]];
        k.pop_front();
    }
    cout<<ans;
}
int main(){
    input();
    solution();
    return 0;
}
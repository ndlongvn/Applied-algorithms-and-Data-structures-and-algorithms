#include<bits/stdc++.h>
using namespace std;
# define N 100001
typedef struct ele{
    int x;
    int y;
} ele;
int n;
vector<ele> inp;
bool check(int u, ele v){
    if(u>=v.x) return false;
    return true;
}
void input(){
    cin>> n;
    for(int i=1; i<=n; i++){
        int u, v;
        cin>> u>>v;
        inp.push_back(ele{u, v});
    }
}
int cal(vector<ele> u){
    int counted= 0;
    int v= -1;
    for(int i=0; i< u.size(); i++){
        if(check(v, u[i])){
            v= u[i].y;
            counted++;
        }
    }
    return counted;
}
int main(){
    input();
    sort(inp.begin(), inp.end(), [](ele u, ele v){
        if(u.y!= v.y) return u.y< v.y;
        else{
            return u.x> v.x;
        }
    });
    cout<<cal(inp)<< endl;
    // for(int i=0; i< inp.size(); i++){
    //     cout<< inp[i].x<<" "<< inp[i].y<<endl;
    // }
    return 0;
}
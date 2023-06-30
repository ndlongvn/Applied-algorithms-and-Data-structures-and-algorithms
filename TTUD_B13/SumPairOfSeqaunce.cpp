#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
int n, M, a[N];
int sum;
vector<pair<int, int>> pai;
int binary_search(int begin, int finish, int search){
    int mid= (begin+ finish)/2;
    if (begin> finish) return -1;
    if(pai[mid].second == search){
        return mid;
    }
    else if(search< pai[mid].second){
        return binary_search(begin, mid-1, search);
    }
    else{
        return binary_search(mid+1, finish, search);
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>M; sum= 0;
    for(int i=1; i<= n; i++){
        cin>>a[i];
        pai.push_back(pair<int, int>(i, a[i]));
    } 
    
    for(auto i: pai){
        int m= i.first, n= i.second;
        int h= binary_search(0, pai.size()-1, M- n);
        if(h!= -1){
            if(h> m&& pai[h].second==M- n) sum++;
        }
    }
    cout<<sum;
    return 0;
}
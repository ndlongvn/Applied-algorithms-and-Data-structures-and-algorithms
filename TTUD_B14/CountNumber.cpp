#include<bits/stdc++.h>
using namespace std;
int n, q;
vector<pair<int, int>> a;
int binary_search(int start, int end, int find){
    if(start<= end){
        int mid= (start+ end)/2;
        if(a[mid].second==find) return mid;
        else if(a[mid].second< find) return binary_search(mid+ 1, end, find);
        else return binary_search(start, mid-1, find);
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>> n>> q;
    for(int i=0; i<n; i++){
        int m;
        cin>> m;
        a.push_back(pair<int, int>(i, m));
    };
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second< b.second;
    });

    int cnt= 0;
    for(auto i: a){
        int u= i.first, v= i.second;
        int k= binary_search(0, n-1, q- v);
        if(k!=-1){
            if(a[k].first> u) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
// 5 8
// 4 6 5 3 2
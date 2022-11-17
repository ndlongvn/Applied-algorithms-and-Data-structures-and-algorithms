#include<bits/stdc++.h>
using namespace std;
int a[300][10001];
int cal_val(string s, int m){
    return 0;
}
int main(){
    int n, m;
    cin>> n>>m;
    for(int i='a'; i<= 'z'; i++){
        a[i][0]= i%m;
    }
    for(int i='a'; i<= 'z'; i++){
        for(int j=1; j<=10000; j++){
            a[i][j]= (a[i][j-1]*256)%m;
        }
    }
    string k;
    for(int i=0; i<n; i++){
        int s= 0;
        cin>> k;
        for(int j= 0; j< k.size(); j++){
            s+= a[k[j]][k.size()- 1- j];
            s= s%m;
        }
        
        cout<< s<<endl;
    }
    // cout<< a['a'][1]<<" "<<a['b'][0];
}
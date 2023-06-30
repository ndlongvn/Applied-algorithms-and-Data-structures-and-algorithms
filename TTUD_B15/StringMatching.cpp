// sdung thuat toan morp
#include<bits/stdc++.h>
using namespace std;
int arr[1000];
int main(){
    string t, p;
    for(int i=0; i<1000; i++) arr[i]= 0;
    getline(cin, p); getline(cin, t);
    int n= t.size(), m= p.size();
    for(int i=0; i<m; i++) arr[p[i]]= i+1;
    int ans= 0;
    int s= 0;
    for(int i= 0; i<= n-m; i++){
        bool ok= true;
        int j;
        for(j= m-1; j>= 0; j--){
            if(t[j+ i]!=p[j]){                
                ok= false;
                break;
            }
        }
        if(ok){
            ans++;
        } 
        else{
            int k= arr[t[j+i]];
            i= i+ max(j-k, 1) -1;
        } 
    }
    cout<< ans;
    return 0;
}
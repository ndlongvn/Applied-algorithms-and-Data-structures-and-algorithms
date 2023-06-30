#include<bits/stdc++.h>
using namespace std;
string a, b;
void solution(){
    int n= a.size();
    int m= b.size();
    vector<int> res (n+ m, 0);
 
    int h= 0; 
    for(int i= n-1; i>=0; i--){
        int u= a[i]- '0';
        int k= 0;
        for(int j= m-1; j>=0; j--){
            int v= b[j]- '0';
            int ans= u*v+ res[h+k];
            res[h+k]= ans%10;
            res[h+k+1]+= ans/10;
            k++;
        }
        h++;
    }
    int i= n+m- 1;
    while(res[i]==0) i--;
    for(int j= i; j>=0; j--) cout<<res[j];
}
int main(){
    cin>> a>> b;
    solution();
    return 0;
}
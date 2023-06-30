#include<bits/stdc++.h>
using namespace std;
#define N 10001
int n, L, m;
int a[2*N];
void input(){
    cin>>n>>L>>m;
    string s;
    a[0]= 0;
    for(int i=1; i<=n; i++){
        cin>> a[i];
    }
    sort(a, a+n+1);
}
void solution(){
    int i= 0;
    for(int i= 0; i<n; i++){
        for(int j= a[i]+1; j<a[i+1]; j++){
            string u= to_string(j);
            string v(L-u.size(), '0');
            cout<< v<<u<<endl;
            m--;
            if(m==0) break;
        }
        string u= to_string(a[i+1]);
        string v(L-u.size(), '0');
        cout<< v<<u<<endl;
        if(m==0){
            for(int j= i+2; j<= n; j++) {
                string u= to_string(a[j]);
                string v(L-u.size(), '0');
                cout<< v<<u<<endl;
            }
            break;
        }
    }
    if(m>0){
        for(int j= a[n]+1; j<=a[n]+m; j++){
            string u= to_string(j);
            string v(L-u.size(), '0');
            cout<< v<<u<<endl;
        }
    }
    // while(1){
    //     if(i<n){
    //         for(int j= a[i]+1; j<a[i+1]; j++){
    //             string u= to_string(j);
    //             string v(L-u.size(), '0');
    //             cout<< v<<u<<endl;
    //             m--;
    //             if(m==0) break;
    //         }
    //         if(m==0) break;
    //         cout<<b[i+1]<<endl;
    //         i++;
    //     }
    //     else if(i>=n){
    //         for(int j= a[i]+1; j<a[i]+m; j++){
    //             string u= to_string(j);
    //             string v(L-u.size(), '0');
    //             cout<< v<<u<<endl;
    //             m--;
    //             if(m==0) break;
    //         }
    //         if(m==0) break;
    //     }
    // }
    // for(int j= i; j<=n; j++) cout<<b[j]<<endl;
}
int main(){
    input();
    solution();
    return 0;
}
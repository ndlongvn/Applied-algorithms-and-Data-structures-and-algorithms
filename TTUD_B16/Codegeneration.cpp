#include<bits/stdc++.h>
using namespace std;
#define N 51
string str(N, '0');
int n, L;
int main(){
    cin>>n>>L;
    string m;
    for(int i=1; i<=n; i++){
        cin>>m;
        cout<< str.substr(0, L-m.length())<< m<<endl;
    }
    return 0;
}
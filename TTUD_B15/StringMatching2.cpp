// su dung thuat toan rabin- karp
#include<bits/stdc++.h>
using namespace std;
#define N INT_MAX
int main(){
    string t, p;
    getline(cin, p); getline(cin, t);
    int n= t.size(), m= p.size();
    int code= 0;
    int h= 1;
    for(int i=0; i<m; i++){
        h= (h*256)%N;
        code= (code*256+ p[i])%N;  
    }   
    int i= 0;
    int code2= 0;
    for(int i=0; i<m; i++) code2= (code2*256+ t[i])%N; 
    int ans= 0;
    while(i<=n- m){
        // if(i==13) cout<<code<<" "<<code2<<endl;
        if(code2== code){
            bool ok= true;
            for(int j=0; j<=m-1; j++){
                if(t[i+j]!= p[j]){
                    ok= false; break;
                } 
            }
            if(ok) ans++;
        }
        code2= ((code2- t[i]* h)*256+ t[i+m])%N;
        if(code2< 0) code2 = (code2 + N);
        i++;
    }
    cout<< ans;
    return 0;
}
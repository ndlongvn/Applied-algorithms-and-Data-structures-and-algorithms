#include<bits/stdc++.h>
using namespace std;
#define Nmax 100001
int N, a[Nmax], T, C;
bool check(int d){
    int sl= 1; int i=1, j=2;
    while(i<N){
        while(j<=N&&a[j]-a[i]< d){            
            j++;
        }
        if(j<=N) sl++;
        if(sl>=C) return true;
        i= j; j++;
    }
    return false;
}
// void input(){
//     cin>>T;
//     for(int i=0; i<T; i++) {
//         cin>>N>>C;
//         for(int j=1; j<=N;j++){
//             cin>>a[j];
//         }
//         sort(a+1, a+N+1);
//         int temp= 0;
//         for(int d= a[N]-a[1]; d>=0; d--){
//             if(check(d)) {
//                 cout<< d<<endl;
//                 temp= 1;
//                 break;
//             }
//         }+
//         if(temp==0) cout<<0<<endl;
//     };
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int i=0; i<T; i++) {
        cin>>N>>C;
        for(int j=1; j<=N;j++){
            cin>>a[j];
        }
        sort(a+1, a+N+1);
        int temp= 0;
        int low= 0, high= (a[N]- a[1])/(C-1);
        while(low< high){
            int mid= (low+ high)/2;
            if(check(mid)) {
                low=  mid+ 1;
            }
            else high= mid;
        }
        cout<< low-1<< endl;
        // if(temp==0) cout<<0<<endl;
    };
    return 0;
}
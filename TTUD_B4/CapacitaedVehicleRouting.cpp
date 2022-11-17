#include<bits/stdc++.h>
using namespace std;
#define nMax 50
#define kMax 9
int n, K1, Q;
int a[nMax+ 1][nMax+ 1];
int d[nMax+ 1];

int x[100]; // x[k] la diem tiep theo cua diem k: 0,1,2,..,k
int y[100]; // y[k] la diem khach hang dau tien cua xe thu k: 0,1,2, ..k
int Load[kMax+1]; // tong luong hang tren xe k
int nbSegment; // so chang hay doan tren k( phai bang n+ k)
bool visited[nMax+ 1];
// Duyet tat ca gia tri cua y roi duyet den x, 
int f;
int f_min;
int sum;
void input(){
    cin>> n>> K1>> Q;
    d[0]= 0;
    for(int i=1; i<= n; i++) {
        cin>>d[i];
        sum+= d[i];
    }
    for(int i=0; i<= n; i++){
        for(int j=0; j<= n; j++){
            cin>> a[i][j];
        }
    }
}
int j= 0;
void Solution(){
    if(f<f_min) f_min= f;
    // cout<<j++<<endl;
}
bool checkX(int v, int i, int k){
    if(v==0) return true;
    if(visited[v]&&v!=0) return false;
    if(Load[k]+ d[v]> Q) return false;
    return true;
}
bool checkY(int v, int k){
    if(Load[k]+ d[v]> Q) return false;
    return true;
}
// bool check(){
//     // if((k==K)&&(nbSegment==n+K)) return true;
//     for(int i=1; i<=n; i++){
//         if(!visited[i]) return false;
//     }
//     return true;
// }
void TryX(int i, int k, int K){ // Try value for x[i] on route k, next point of i on route k
    for(int v= 0; v<=n; v++ ){
        if(checkX(v, i, k)){
            x[i]= v;
            // update accumulated structure
            Load[k]+= d[v];
            nbSegment+=1;
            visited[v]= true; //if(v!=0)
            f+= a[i][v];
            if(v==0) { // come back to the depot, finish route[k]
                if(k==K){
                    if(nbSegment==n+K) Solution();
                }
                // if(check()){
                //     Solution();
                // }
                else{
                    TryX(y[k+1], k+1, K);
                }
            }
            else{
                TryX(v, k, K); // find subsequent point of v on route[k]
            }
            Load[k]-=d[v];
            nbSegment-=1;
            visited[v]= false;
            f-= a[i][v];
        }
    }
}
void TryY(int k, int K){ // Try value for y[k]
    for(int v= y[k-1]+1; v<=n; v++){ // - K+k
        if(checkY(v, k)){
            y[k]= v;
            visited[v]= true;
            Load[k]+= d[v];
            nbSegment+=1;
            f+=a[0][v];
            if(k==K){ // 
                TryX(y[1], 1, K); //start to build the route[1], find subsequent point of y[1]
            }
            else{
                TryY(k+1, K);
            }
            visited[v]= false;
            Load[k]-= d[v];
            nbSegment-=1;
            f-=a[0][v];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sum=0;
    input();
    f=0;
    f_min= 1e9;
    nbSegment=0;
    for(int k=1; k<= K1; k++) Load[k]= 0;
    for(int i=0; i<= n; i++) visited[i]= false;
    for(int K=1; K<=K1; K++) if(sum<=K*Q) TryY(1, K);
    cout<< f_min;
    return 0;
}
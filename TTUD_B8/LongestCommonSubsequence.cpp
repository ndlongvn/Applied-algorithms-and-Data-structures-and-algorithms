#include<bits/stdc++.h>
using namespace std;
#define N 10001
int n, m, a[N], b[N];
int S[N][N]; // mang luu cac day con
char trace[N][N];
void input(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>> a[i];
    }
    for(int i=1; i<=m; i++){
        cin>> b[i];
    }
}
// S[i, j] la day con chung dai nhat cua day x1- xi, y1- yj
// S[1, j]= 1 neu x1 thuoc tu y1- yn; =0 neu ko thuoc
// S[i, 1]= 1 neu y1 thuoc tu x1- xn; =0 neu khong thuoc
void solveBottomUp(){
    for(int i=0; i<=n; i++) S[i][0] =0;
    for(int i=0; i<=m; i++) S[0][i] =0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i]==b[j]){
                S[i][j]= S[i-1][j-1]+ 1;
                trace[i][j]= 'D';
            }
            else if(S[i-1][j]> S[i][j-1]) {
                S[i][j]= S[i-1][j];
                trace[i][j]= 'U';
            }
            else{
                S[i][j]= S[i][j-1];
                trace[i][j]= 'L';
            }
        }
    }
    // cout<< S[n][m]<< endl;

}
void getSolution(){
    int i= n, j= m;
    stack<int> P;
    while(i>= 1&& j>= 1){
        if(trace[i][j]=='D'){
            // cout<<a[i]<<" ";
            P.push(a[i]);
            i= i-1; j = j-1;
            
        }
        else if(trace[i][j]=='U'){
            i= i- 1;
        }
        else{
            j= j- 1;
        }
    }
    while(!P.empty()){
        int x= P.top(); P.pop();
        cout<<x<< " ";
    }
}
int F(int i, int j){
    if(i==0||j==0){S[i][j]=0; return 0;};
    if(S[i][j]< 0){
        if(a[i]==b[j]){
            S[i][j]= F(i-1, j-1) +1;
            
        }
        else{
            int A= F(i-1, j);
            int B= F(i, j-1);
            S[i][j]= max(A, B);
        }
    } 
    return S[i][j];
}
void solveTopDown(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            S[i][j]= -1;
        }
    }
    int res= F(n, m);
    cout<< res;
}
int main(){
    input();
    solveBottomUp();
    // cout<< S[n][m];
    // solveTopDown();
    getSolution();
    return 0;


}
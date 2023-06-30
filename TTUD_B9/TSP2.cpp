#include<bits/stdc++.h>
using namespace std;
const int N = 20;
const int INF = 100000000;
int C[N][N], n;
int iMem[N][1<<N];
// memset(iMem, -1, sizeof(iMem));
void input(){
    cin>> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        cin>> C[i][j];
    }
    for(int i=0; i <N; i++){
        for(int j=0; j< (1<<N); j++){
            iMem[i][j]= -1;
        }
    }
}
int TSP(int i, int S) {
    if (S == ((1<<N) - 1)) return C[i][0];
    if (iMem[i][S] != -1) return iMem[i][S];

    int res = INF;
    for (int j = 0; j < n; j++){
        if (S & (1 << j)) continue ;
        res = min(res , C[i][j] + TSP(j, S|(1 << j)));
    }
    iMem[i][S] = res ;
    return res;
}
int main(){
    input();
    cout<<TSP(0, 1);
    return 0;
}

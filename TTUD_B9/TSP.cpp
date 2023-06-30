#include<bits/stdc++.h>
using namespace std;
// TSP using dynamic program
// F[i, S] loi giai cua TSP(i, S)
// Khoi tao: F[i, S]= -1 (Bt con chua dc giai)
// TSP(i, S)
//  if(S.empty()) then F[i, S]= C[i, 0]; return F[i, S]
//  ifF[i, S]= -1 then F[i, S]= inf;
        // for j=0 -> n-1 do
        //     if(j in S) then T[j]= TSP(j, S\{j})+ C[i, j];
        //     F[i, S]= min(F[i, S], T[j])
        // return F[i, S]
#define N 21
int distanced[N][1<<N], road, matrix[N][N];
void input(){
    cin>> road;
    for(int i=0; i<road; i++){
        for(int j=0; j<road; j++)
        cin>> matrix[i][j];
    }
    for(int i= 0; i<N; i++){
        for(int j=0; j<(1<<N); j++){
            distanced[i][j]= -1;
        }
    }
}
bool contains(int S,  int i){
    return (S&(1<< i)) ;
}
int addElement(int S, int i){
    return S|(1<<i);
}
int removeElement(int S, int i){
    return S&(~(1<<i));
}
int TSP(int i, int S){
    if(S==0){
        distanced[i][S]= matrix[i][0];
        return matrix[i][0];
    } 
    if(distanced[i][S]!=-1) return distanced[i][S];
    int re= 1e9;
    for(int j= 1; j< road; j++){
        if(contains(S, j)){
            re= min(re, matrix[i][j] + TSP(j, removeElement(S, j)));
        }
    }
    distanced[i][S]= re;
    return re;
}
int main(){
    input();
    int S= (1<<road)- 1;
    cout << TSP(0, removeElement(S, 0));
    return 0;
}
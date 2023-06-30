#include<bits/stdc++.h>
using namespace std;
int Duongdi(int i, int j, int D, int C){
    if(i==D||j==C) return 1;
    if ((i==D-1)&&(j==C-1)) return 3;
    else{
        if(i<=D-1&&j<=C-1){
            return Duongdi(i+1, j, D, C)+ Duongdi(i, j+1, D, C)+ Duongdi(i+1,j+1, D,C);
        }
        else{
            return Duongdi(i+1, j, D, C)+ Duongdi(i, j+1, D, C);
        }
        
    }
    return 0;
}
int main(){
    cout<<Duongdi(2,2,3,4);
    return 0;
}
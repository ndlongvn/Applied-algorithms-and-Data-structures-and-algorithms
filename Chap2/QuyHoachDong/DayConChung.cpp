#include<bits/stdc++.h>
using namespace std;
int D[100][100]={{}};
int check(string x, string y, int i, int j){
    if(i==-1||j==-1) return 0;
    if(D[i][j]!=0) return D[i][j];
    int res;
    if(x[i]==y[j]) res=1+ check(x,y,i-1,j-1);
    else{
        res= max(check(x,y,i-1,j),check(x,y,i,j-1));
    }
    D[i][j]= res;
    return res;
}
int main(){
    string x= "madam";
    string y= "mama";
    cout<<check(x,y,4,3);
    return 0;

}
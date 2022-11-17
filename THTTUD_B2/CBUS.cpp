#include<bits/stdc++.h>
using namespace std;
int n, K;
int matrix[30][30];
bool visited[30];
bool removed[30];
int f;
int f_min;
int numP;
int x[30];
int Cm;
void input(){
    Cm= 1e9;
    cin>> n>> K;
    for(int i=0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin>>matrix[i][j];
            if(matrix[i][j]< Cm && i!=j) Cm= matrix[i][j];
        }
    }
}
bool check(int k){
    if (visited[k]) return false;
    if ((k<= n)&&(numP+1>K)) return false;
    if ((k> n)&&(visited[k-n]==false)) return false;
    return true;
}
void solution(){
    if(f+matrix[x[2*n]][0]< f_min){
        f_min= f+ matrix[x[2*n]][0];
    }
}
void Try(int k){
    for(int v= 1; v<= 2*n; v++){
        if(check(v)){
            if((v<=n)) numP++;
            else if((v>n)){ // &(!removed[v-n])&(visited[v-n])
                numP--;
            }
            x[k]= v;
            f= f+ matrix[x[k-1]][x[k]];
            visited[v]= true;
            if((k==2*n)) {
                if(numP==0) solution();
            }
            else{
                if(f+ Cm*(2*n-k+1)<f_min) Try(k+1);
            }
            visited[v]= false;
            f= f- matrix[x[k-1]][x[k]];
            if((v<=n)) numP--;
            else if((v>n)){ // &(removed[v-n])&(visited[v-n])
                numP++;
            }
        }
    }
}
int main(){
    input();
    for(int i=0; i<=2*n; i++) visited[i]= false;
    for(int i=0; i<=2*n; i++) removed[i]= false;
    f= 0;
    x[0]= 0; visited[0]= true;
    f_min= 1e9;
    numP=0;
    Try(1);
    cout<< f_min;
    return 0;
}
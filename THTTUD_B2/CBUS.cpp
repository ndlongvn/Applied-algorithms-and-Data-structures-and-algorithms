#include<bits/stdc++.h>
using namespace std;
int n, K;
int matrix[30][30]; // matrix input
bool visited[30]; // mark for visited point
int f; // sum of distance 
int f_min; // min sum of distance 
int numP; // num of passenger
int x[30]; //
int Cm; // min of distance
void input(){
    Cm= 1e9; // initialize Cm
    cin>> n>> K; // read n, K
    for(int i=0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin>>matrix[i][j]; // read matrix
            if(matrix[i][j]< Cm && i!=j) Cm= matrix[i][j];
        }
    }
}
bool check(int k){
    if (visited[k]) return false; // if visited return false
    if ((k<= n)&&(numP+1>K)) return false; // if take passenger and number of passenger > K
    if ((k> n)&&(visited[k-n]==false)) return false; // if remove passenger i when visit i+ n
    return true;
}
void solution(){
    if(f+matrix[x[2*n]][0]< f_min){
        f_min= f+ matrix[x[2*n]][0]; // select min of sum of distance of solution
    }
}
void Try(int k){
    for(int v= 1; v<= 2*n; v++){
        if(check(v)){
            if((v<=n)) numP++; // if take passenger numP ++
            else if((v>n)){ // if remove passenger numP --
                numP--;
            }
            x[k]= v;
            f= f+ matrix[x[k-1]][x[k]]; // increase f
            visited[v]= true; // set visited v
            if((k==2*n)) {
                if(numP==0) solution();
            }
            else{
                if(f+ Cm*(2*n-k+1)<f_min) Try(k+1); // branch and bound 
            }
            visited[v]= false; // return visited v
            f= f- matrix[x[k-1]][x[k]]; // return f
            if((v<=n)) numP--; // return numP
            else if((v>n)){ // return numP
                numP++;
            }
        }
    }
}
int main(){
    input();
    for(int i=0; i<=2*n; i++) visited[i]= false;
    f= 0;
    x[0]= 0; visited[0]= true;
    f_min= 1e9;
    numP=0;
    Try(1);
    cout<< f_min;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int m, n, K;
int course[50][50];
int paircourse[50][50];
int setcourse[50];
int countcourse[30];
int f_min;
int countc;
void input(){
    cin>> m>>n;
    for(int i=0; i<50; i++){
        for(int j=0; j<50; j++){
            course[i][j]= 0;
        }
    }
    for(int i=0; i<50; i++){
        for(int j=0; j<50; j++){
            paircourse[i][j]= 0;
        }
    }
    for(int i=1; i<=m; i++){
        int k, h;
        cin>> k;
        for(int j=0; j<k; j++){
            cin>>h;
            // cout<<h<<endl;
            course[i][h]= 1;
            // cout<<"Has "<<i<<" "<<h<<" "<< course[i][h]<< " "<< endl;
        }
        cout<< endl;
    }
    cin>> K;
    for(int i=0; i<K; i++){
        int k, h;
        cin>>k>>h;
        paircourse[k][h]= 1;
        paircourse[h][k]= 1;
    }
}
bool check(int v, int k){
    if(setcourse[v]) return false;
    if(!course[k][v]) return false;
    for(int i=1; i<=n; i++){
        if((setcourse[i]==k)&&(paircourse[i][v]==1)){
            return false;
        }
    }
    return true;
}
int checkmax(){
    int maxt= 0;
    for(int i=1; i<=m; i++){
        if(maxt<countcourse[i]) maxt= countcourse[i];
    }
    return maxt;
}
void solution(){
    int max= 0;
    for(int i=1; i<=m; i++){
        if(max< countcourse[i]) max= countcourse[i];
    }
    if(max< f_min) f_min= max;
}
void Try(int h){ // chon thay cho mon h
    for(int i=1; i<=m; i++){
        if(check(h, i)){ // neu thay i co the day mon h
            setcourse[h]= i;
            countcourse[i]+=1;
            if(h== n) solution();
            else{
                if(checkmax()<f_min){
                    Try(h+1); 
                }
                
            }          
            setcourse[h]= 0;
            countcourse[i]-=1;
        }
    }
}

int main(){
    input();
    countc=0;
    f_min= 1e5;
    for(int i=1; i<=n; i++) setcourse[i]= 0;
    for(int i=1; i<=m; i++) countcourse[i]= 0;
    Try(1);
    cout<< f_min<<endl;
    return 0;
}
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

int H, W, n;
int coun = 0;
int matrix[100][100];
int in[100];
void input(){
    cin>>H>>W;
    cin>>n;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            matrix[i][j]= 1;
        }
    }
    // for(int i=0; i<100; i++) in[i]= 0;
    for(int i=0; i<n; i++){
        int h,w;
        cin>>h>>w;
        in[2*i]= h;
        in[2*i+1]= w;
    }
}
bool check(int h, int w){
    bool a= true;
    for(int i=1; i<=H; i++){
        for(int j=1; j<= W; j++){
            a= true;
            for(int m= i; m<= h+i-1; m++){
                for(int n= j; n<= w+j-1; n++){
                    if(!matrix[m][n]) a= false;
                }
            }
            if(a) return true;
        }
    }
    return false;
}

void Try(int k) {
	if(check(in[2*k], in[2*k+1])){
        int m, n;
        for(int i=1; i<=H; i++){
            bool a= true;
            for(int j=1; j<= W; j++){
                a= true;
                for(int m= i; m<= in[2*k]+i-1; m++){
                    for(int n= j; n<= in[2*k+1]+j-1; n++){
                        if(!matrix[m][n]) a= false;
                    }
                }
            }
            if(a== true) break;
        }
        for(int i= m-in[2*k]+1; i<= m; i++){
            for(int j= n-in[2*k+1]+1; j<= n; j++){
                matrix[i][j]= 0;
            }
        }
        if(k==n-1) coun++;
        else{
            Try(k+1);
        }
        for(int i= m-in[2*k]+1; i<= m; i++){
            for(int j= n-in[2*k+1]+1; j<= n; j++){
                matrix[i][j]= 0;
            }
        }
    }
    else if(check(in[2*k+1], in[2*k])){
        int m, n;
        for(int i=1; i<=H; i++){
            bool a= true;
            for(int j=1; j<= W; j++){
                a= true;
                for(int m= i; m<= in[2*k+1]+i-1; m++){
                    for(int n= j; n<= in[2*k]+j-1; n++){
                        if(!matrix[m][n]) a= false;
                    }
                }
            }
            if(a== true) break;
        }
        for(int i= m-in[2*k+1]+1; i<= m; i++){
            for(int j= n-in[2*k]+1; j<= n; j++){
                matrix[i][j]= 0;
            }
        }
        if(k==n-1) coun++;
        else{
            Try(k+1);
        }
        for(int i= m-in[2*k+1]+1; i<= m; i++){
            for(int j= n-in[2*k+1]+1; j<= n; j++){
                matrix[i][j]= 0;
            }
        }
    }
}
int main(void) {
    input();
    Try(1);
    if(coun) cout<<1;
    else cout<<0;
    return 0;
}

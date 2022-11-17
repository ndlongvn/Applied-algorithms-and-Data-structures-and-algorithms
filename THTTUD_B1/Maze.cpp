#include<bits/stdc++.h>
using namespace std;
int matrix[1000][1000];
int des[1000][1000];
typedef struct vitri{
    int x;
    int y;
} vitri ;

int m, n, r, c;
queue<vitri> que;
vitri tao_vi(int x, int y){
    vitri i; //= new vitri;
    i.x= x;
    i.y= y;
    return i;
}

int dx[4]= {0, 0, -1, 1};
int dy[4]= {-1, 1, 0, 0};
void inputmatrix(){
    for(int i= 1; i<= n; i++){
        for(int j= 1; j<= m; j++){
            cin>> matrix[i][j];
        }
    }
}

int run(){
    vitri root= tao_vi(r, c);
    des[r][c]= 0;
    matrix[r][c]= 1;
    que.push(root);
    while(!que.empty()){
        vitri u= que.front(); que.pop();
        for(int i=0; i<4; i++){
            int dx_new= u.x+ dx[i];
            int dy_new= u.y+ dy[i];
            if((dx_new<1)||(dx_new> n)||(dy_new<1)||(dy_new>m)) return des[u.x][u.y]+ 1;
            if(matrix[dx_new][dy_new]!=1){
                vitri v= tao_vi(dx_new, dy_new);
                des[dx_new][dy_new]= des[u.x][u.y]+ 1;
                que.push(v);
                matrix[dx_new][dy_new]= 1;
            }
        }

    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>> n>> m>> r>> c;
    inputmatrix();
    int re= run();
    cout<< re;
}

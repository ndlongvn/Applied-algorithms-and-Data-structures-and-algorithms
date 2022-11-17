#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
int n, m;
int a[MAX][MAX];
int step[MAX][MAX];
int visited[MAX][MAX];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
typedef pair<int, int> ii;
queue<ii> que;


int BFS(int r, int c){
    que.push(ii(r,c)); step[r][c]= 0; visited[r][c]= 1;
    while(!que.empty()){
        ii u= que.front(); que.pop();
        for(int i=0; i<4; i++){
            int x_new= dx[i]+ u.first; 
            int y_new= dy[i]+ u.second;
            if((a[x_new][y_new]==0 )&& (visited[x_new][y_new]==0)){
                que.push(ii(x_new, y_new));
                visited[x_new][y_new]= 1;
                step[x_new][y_new]= step[u.first][u.second]+1;
                if((x_new==1)||(y_new==1)||(x_new==n)||(y_new==m)){
                    return step[x_new][y_new]+1;
                }
            }
        }
    }
    return -1;
}

int main(){
    int r, c;
    cin>>n>>m>>r>>c;
    for(int i=1; i<=n; i++){
        for(int j=1; j<= m; j++){
            cin>>a[i][j];
            visited[i][j]=0;
        }
    }
    int result= BFS(r, c);
    cout<< result;
    return 0;
}
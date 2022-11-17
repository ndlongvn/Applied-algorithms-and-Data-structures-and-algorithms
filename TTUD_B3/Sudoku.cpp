#include<bits/stdc++.h>
using namespace std;
bool markRow[9][10]={};
bool markCol[9][10]={};
bool markSquare[3][3][10]={};
int matrix[9][9];
int co;
vector<int> c;
bool check(int v, int r, int c){
    return markRow[r][v]==false && markCol[c][v]== false && markSquare[r/3][c/3][v]==false;
}
void Solution(){
    co++;
}
void Try(int r, int c){
    if(matrix[r][c]!=0){
        if(c==8) Try(r+1, 0);
        else Try(r, c+1);
    }
    else{
        for(int v= 1; v<=9; v++){
            if (check(v, r, c)){
                matrix[r][c]= v;
                markCol[c][v]= true;
                markRow[r][v]= true;
                markSquare[r/3] [c/3][v]= true;
                if (r==8 and c==8) Solution(); 
                else {
                    if(c==8){
                        Try(r+1, 0);
                    }
                    else{
                        Try(r, c+1);
                    }
                }
                matrix[r][c]= 0;
                markRow[r][v]= false;
                markCol[c][v]= false;
                markSquare[r/3][c/3][v]= false;
            }
        }
    }
    
}
void inputmatrix(int rows, int cols ){
    for(int i=0; i< rows; i++){
        for(int j=0; j< cols; j++){
            cin>> matrix[i][j];
        }
    }
    for(int i=0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            if(matrix[i][j]!=0){
                markRow[i][matrix[i][j]]= true;
                markCol[j][matrix[i][j]]= true;
                markSquare[i/3][j/3][matrix[i][j]]= true;
            }
        }
    }
}
int main(){
    co= 0;
    inputmatrix(9, 9);
    Try(0,0);
    cout<<co;
    return 0;
}
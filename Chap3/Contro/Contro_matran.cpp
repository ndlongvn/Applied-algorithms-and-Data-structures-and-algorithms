#include<bits/stdc++.h>
using namespace std;
typedef struct str
{
    /* data */
    int x;
    int y;
    int *matran;
} contro;

void dienmatran(contro * ct){
    for(int i=0; i<ct->x; i++){
        for(int j=0; j<ct->y; j++){
            if(j<=i){
                ct->matran[i*ct->y+j]=i*(i+1)/2+ j+1;
            }
            else{
                ct->matran[i*ct->y+j]=0;
            }
        }
    }
}
int main(){
    int x,y;
    cin>>x>>y;
    contro mt;
    mt.x= 8;
    mt.y= 8;
    mt.matran=(int*)malloc(sizeof(int)*mt.x*mt.y);
    dienmatran(&mt);
    for(int i=0; i<mt.x; i++){
        for(int j=0; j<mt.y; j++){
            if(j<mt.y-1){
                cout<<mt.matran[i*mt.y+j]<<" ";
            }
            else{
                cout<<mt.matran[i*mt.y+j]<<" "<<endl;
            }
        }
    }
    //mang 2 chieu
    int **p=(int**)malloc(sizeof(int*)*8);
    for(int i=0; i<8; i++){
        p[i]=(int*) malloc(sizeof(int)*(i+1));
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(j<=i+1){
                p[i][j]=i*(i+1)/2+ j+1;
            }
        }
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(j<=i+1){
                cout<<p[i][j]<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    
}
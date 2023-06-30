#include<bits/stdc++.h>
using namespace std;
int duyetoanbo(int *s, int n){
    int ans=s[0];
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int maxt=0;
            for(int k=i; k<=j ;k++){
                maxt=maxt+s[k];
            }
            if(ans<maxt){
                ans= maxt;
            }
            
        }
    }
    return ans;
}
int duyetcocaitien(int *s, int n){
    int ans=s[0];
    for(int i=0; i<n; i++){
        int maxt=0;
        for(int j=i; j<n; j++){
            maxt=maxt+s[j];
            if(ans<maxt){
                ans=maxt;
            }
        }
    }
    return ans;
}
int dynamicprogramming(int *s, int n){
    int num=s[0];
    int maxt=s[0];
    for(int i=1; i<n; i++){
        num= max(num+ s[i],s[i]);
        maxt= max(maxt, num);
    }
    return maxt;
}
int main(){
    int s[]={-2,11,-4,13,-5,2};
    int n= sizeof(s)/sizeof(s[0]);
    cout<<"duyet toan bo "<<duyetoanbo(s,n)<<endl;
    cout<<"duyet co cai tien "<<duyetcocaitien(s,n)<<endl;
    cout<<"dynamic programming "<<dynamicprogramming(s,n)<<endl;
}
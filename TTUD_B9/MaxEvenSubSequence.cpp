#include<bits/stdc++.h>
using namespace std;
#define N 10000001
long long int n, a[N], SL[N], SC[N], A[N], B[N] ;
// chia bai toan thanh tim day con le lon nhat va day con chan lon nhat
// bai toan con nho nhat: a[1] chan thi SC[1] = a[1], SL[1] ko ton tai
// a[1] le thi SL[1]= a[1], SC[1] khong ton tai
// CT QHD:
// a[i] chan: SC[i]= SC[i-1]+ a[i] neu SC[i-1] ton tai > 0
//                 a[i] neu nguoc lai
//             SL[i]= SL[i-1]+ a[i] neu SL[i-1] ton tai
//                     khong ton tai neu SL[i-1] khong ton tai
//  a[i] le: SC[i]= SL[i-1]+ a[i] neu SL[i-1] ton tai
//                  khong ton tai neu SL[i-1] khong ton tai
//           SL[i]= SC[i-1]+ a[i] neu SC[i-1] ton tai>0
                    // a[i] nguoc lai
int main(){
    cin>> n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=0; i<=n; i++) A[i]= 0;
    for(int i=0; i<=n; i++) B[i]= 0;
    if(a[1]%2==0) {
        SC[1]= a[1];
        B[1]= 1;
    }
    else{
        SL[1]= a[1];
        A[1]= 1;
    }
    for(int i=2; i<= n; i++){
        if(a[i]%2==0){
            if(B[i-1]==1&&SC[i-1]>0){
                SC[i]= SC[i-1]+ a[i];
                B[i]=1;
            }
            else{
                SC[i]= a[i];
                B[i]= 1;
            }
            if(A[i-1]==1){
                SL[i]= SL[i-1]+ a[i];
                A[i]= 1;
            }
        }
        else{
            if(A[i-1]==1){
                SC[i]= SL[i-1]+ a[i];
                B[i]= 1;
            }
            if(B[i-1]==1&&SC[i-1]>0){
                SL[i]= SC[i-1]+ a[i];
                A[i]= 1;
            }
            else{
                SL[i]= a[i];
                A[i]= 1;
            }
        }
    }
    long long int sum= -1e9;
    for(int i=1; i<=n; i++){
        if(B[i]==1){
            if(sum< SC[i]) sum= SC[i];
        }
    }
    cout<< sum;;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[100];
int b[100];
// int doanmax(int *mang, int length){
//     for(int i= 0; i<length; i++){
//         if(b[i]< mang[length-1]){
//             if(a[length]<a[i]+1){
//                 a[length]=a[i]+ 1;
//                 b[length]= mang[length-1];
//             }
//         }
//         else{
//             if(a[length]<a[i]){
//                 a[length]= a[i];
//                 b[length]
//             }
//         }
//     }
// }
int doan(int* mang, int length){
    for(int i=1; i<length; i++){
        for(int j=0; j<i; j++){
            if(b[j]< mang[i]){
                if(a[i]< a[j]+ 1){
                    a[i]= a[j]+ 1;
                    b[i]= mang[i];
                }
                // else{
                //     a[i]= a[j];
                //     b[i]= b[j];
                // }
            }
            else{
                if(a[i]< a[j]){
                    a[i]= a[j];
                    b[i]= b[j];
                }
                // else{
                //     a[i]= a[j];
                //     b[i]= b[j];
                // }
            }
        }
    }
    return a[length-1];
}
int main(){
    int a1[]={10,9,2,5,3,7,101,18};
    int a2[]={3,5,6,2,5,4,19,5,6,7,12};
    int length= 11;
    a[100]={};
    b[100]={};
    a[0]= 1;
    b[0]= a2[0];
    // cout<<doan(a2, length)<<"\n";
    // for(int i=0; i<length; i++){
    //     cout<<" "<<a[i];
    // }
    // cout<<"\n";
    // for(int i=0; i<length; i++){
    //     cout<<" "<<b[i];
    // }
    a[100]={};
    b[100]={};
    a[0]= 0;
    b[0]= -100;
    cout<<doan(a2, length)<<"\n";
    for(int i=0; i<length; i++){
        cout<<" "<<a[i];
    }
    cout<<"\n";
    for(int i=0; i<length; i++){
        cout<<" "<<b[i];
    }
    // cout<<doan(a1, length)<<"\n";

}
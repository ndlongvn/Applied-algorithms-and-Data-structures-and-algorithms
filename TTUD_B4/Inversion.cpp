#include<bits/stdc++.h>
using namespace std;
const int modMax= 1e9+7;
const int nMax= 1e6+1;
int n;
int num;
int a[nMax];
int temp[nMax];
void mergeSort(int left, int right){
    if(left>= right) return;
    int mid= (left+ right)/2;
    mergeSort(left, mid);
    mergeSort(mid+1, right);
    int i= left, j= mid+1;
    int des= left;
    while((i<=mid)&&(j<=right)){
        if(a[i]<= a[j]) temp[des++]= a[i++];
        else {
            temp[des++]= a[j++];
            num=(num+ mid- i+1)%modMax;
        }
    }
    while(i<= mid){
        temp[des++]= a[i++]; 
    }
    while(j<= right){
        temp[des++]= a[j++];
    }
    for(int v= left; v<= right; v++){
        a[v]= temp[v];
    }
}
int main(){
    num= 0;
    cin>>n;
    for(int i=0; i<n; i++) cin>> a[i];
    mergeSort(0, n-1);
    cout<< num;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void swap(int* a, int* b){
    int temp= *a;
    *a= *b;
    *b= temp;
}
void Merge(int a[], int left, int mid, int right){
    int st1= left;
    int st2= mid+1;
    int tempa[100];
    int index= left;        
    for(;st1<=mid && st2<=right; index++){
        if(a[st1]<a[st2]){
            tempa[index]= a[st1];
            st1++;
        }
        else{
            tempa[index]= a[st2];
            st2++;
        }
    }
    for(; st2<=right; st2++,index++){
        tempa[index]=a[st2];
            //index++;
    }
    for(; st1<=mid; st1++, index++){
        tempa[index]=a[st1];
            //index++;
    }
    
    for(int i=left; i<=right; i++){
        a[i]=tempa[i];
    }
}
void MergeSort(int a[], int left, int right){
    if(left<right){
        int mid= (left+right)/2;
        MergeSort(a, left, mid);
        MergeSort(a, mid+1, right);
        Merge(a, left, mid, right);
    }
}
int main(){
    int a[]={1,5,7,2,4,6,8,1, 9, 10, 12, 13};
    MergeSort(a,0,11);
    for(int i=0; i<12; i++){
        cout<<a[i]<<" ";
    }
}
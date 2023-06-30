#include<bits/stdc++.h>
using namespace std;
void swap(int* a, int* b){
    int temp= *a;
    *a= *b;
    *b= temp;
}
int Partition(int a[], int left, int right){
    int i= left;
    int j= right+1;
    int pivot = a[left];
    while(true){
        i+=1;
        while(i<=right && a[i]<pivot) i+=1;
        j-=1;
        while(j>=left && a[j]>pivot) j-=1;
        if(i>=j) break;
        swap(&a[i],&a[j]);
    }
    swap(&a[j], &a[left]);
    return j;
}
void QuickSort(int a[], int left, int right){
    if(left<right){
        int pivot= Partition(a,left, right);
        QuickSort(a, left, pivot-1);
        QuickSort(a,pivot+1, right);
    }
    
}
int main(){
    int a[]={9,8,4,1,2,3,4,6};
    QuickSort(a,0,7);
    for (int i=0; i<8; i++){
        cout<<a[i]<<" ";
    }
}
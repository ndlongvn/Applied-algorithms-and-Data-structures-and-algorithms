#include<bits/stdc++.h>
using namespace std;
void swap(int* a, int* b){
    int temp= *a;
    *a= *b;
    *b= temp;
}
void InsertionSort(int a[], int n){
    for(int i=1; i<n; i++){
        int pos= i;
        int temp= a[i];
        while(pos>0&&a[pos-1]>temp){
            a[pos]=a[pos-1];
            pos--;
        }
        a[pos]= temp;
    }
}
int main(){
    int a[]={2,5,4,3,10};
    InsertionSort(a, 5);
    for(int i=0; i<5; i++){
        cout<<a[i]<<" ";
    }
}
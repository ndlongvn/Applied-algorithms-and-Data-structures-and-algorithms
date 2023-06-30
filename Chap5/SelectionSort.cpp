#include<bits/stdc++.h>
using namespace std;
void swap(int* a, int* b){
    int temp= *a;
    *a=*b;
    *b=temp;
}
void SelectionSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int temp= a[i];
        int index_min=i;
        for(int j=i+1; j<n; j++){
            if(a[j]<temp){
                index_min= j;
            }
        }
        swap(&a[i],&a[index_min]);
    }
}
int main(){
    int a[]={9, -2, 1, 2, 15};
    SelectionSort(a,5);
    for(int i=0; i<7; i++){
        cout<<a[i]<<" ";
    }
}
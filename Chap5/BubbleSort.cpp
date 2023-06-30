#include<bits/stdc++.h>
using namespace std;
void swap(int* a, int* b){
    int temp= *a;
    *a= *b;
    *b= temp;
}
void BubbleSort(int a[], int n){
    bool sorted= false;
    for(int i=1; i<n; i++){
        if(!sorted){
            sorted= true;
            for(int j=0; j<=n-i-1;j++){
                if(a[j]>a[j+1]){
                    swap(&a[j],&a[j+1]);
                    sorted= false;
                }
            }
        }
    }
}
int main(){
    int a[]={1,5,7,2,3,4,6};
    BubbleSort(a, 7);
    for(int i=0; i<7; i++){
        cout<<a[i]<<" ";
    }
}
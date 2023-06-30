#include<bits/stdc++.h>
using namespace std;
bool binary_search(int a[], int k, int first, int last){
    while(first <=last){
        int mid= (first+ last)/2;
        if (a[mid]==k ) {
            return true;
        }
        else if (a[mid]< k) first= mid+ 1;
        else if (a[mid]> k) last= mid-1 ;
    }
    return false;
}
int main(){
    freopen("test1Mil.txt", "r", stdin);
    int n, q;
    cin>> n >>q;
    int a[n];
    for( int i=0; i<n; i++){
        cin>> a[i];
    }
    // int n=100, q=100;
    // int a[100];
    // for (int i= 0; i<100; i++){
    //     a[i]=i+1;
    // }
    // cin>> q;
    sort(a, a+ n);
    int k=0;
    for( int i=0; i<n; i++){
        if(binary_search(a, q-a[i], i+1, n-1)) k++;
    }
    cout<< k;
}
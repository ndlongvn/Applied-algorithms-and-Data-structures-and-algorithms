#include<bits/stdc++.h>
using namespace std;
int BinarySearchDeQuy(int *s, int k, int lo, int hi){
    int mid= (lo+hi)/2;
    if (lo>hi) return -1;
    else{
        if( s[mid]==k) return mid;
        if( s[mid]<k ) return BinarySearchDeQuy( s, k, mid+1, hi);
        if( s[mid]>k ) return BinarySearchDeQuy( s, k, lo, mid-1);
    }
    return 0;
}
int BinarySearch( int *s, int k, int lo, int hi){
    while(lo<=hi){
        int mid= (lo+hi)/2;
        if ( s[mid]==k) return mid;
        else if (s[mid]<k){
            lo= mid+1;
        }
        else if( s[mid]>k){
            hi= mid-1;
        }
        
    }
    return -1;
}
int main(){
    int s[]= {1,2,3,4,6,15,9};
    //cout<<BinarySearchDeQuy(s, 5, 0, 6);
    cout<< BinarySearch(s, 5, 0, 6);
    return 0;
}
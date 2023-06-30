#include<bits/stdc++.h>
using namespace std;
int PalindromeDequy(char *s, int n, int lo, int hi){
    if(n==0|| n==1) return 1;
    if (s[lo]!= s[hi]) return 0;
    else{
        return PalindromeDequy(s, n-2, lo+1, hi-1);
    }
    return 0;
}
int Palindrome(char *s, int n){
    if (n==0|| n==1) return 1;
    else{
        for(int i=0; i<n/2; i++){
            if ( s[i]!=s[n-1-i]){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
int main(){
    char s[]="madam";
    cout<< PalindromeDequy(s, 5, 0, 4)<<endl;
    cout<< Palindrome( s, 5);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define maxN 100001
int n, a[maxN];
void countSolution(int left, int right){
    int mid= (left+ right)/2;
    countSolution(left, mid);
    countSolution(mid+1, right);
    merge()
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>> n;
    for(int i=1; i<=n; i++) cin>> a[i];
}
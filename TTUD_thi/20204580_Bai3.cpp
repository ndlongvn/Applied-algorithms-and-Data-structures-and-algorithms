#include<bits/stdc++.h>
using namespace std;
#define N 30
int n, a, b;
int sub[N];
int ans;
vector<int> vec1, vec2;
void input(){
    cin>> n>> a>> b;
    for(int i=0; i<n; i++){
        cin>> sub[i];
    }
}
void merge(int begin, int size, vector<int>&  res){
	int len = 1<<size; 
	for (int i = 0; i < len; i++){
		int sum = 0;
		for (int j = 0; j < size; j++) {
			if (i & (1 << j))
				sum =sum+ sub[j + begin];
		}
		res.push_back(sum);
	}
}
void solution(){
	merge(0, n/2, vec1);
    vector<int>::iterator low, upp;
	if (n%2==0){
        merge(n/2, n/2, vec2);
    }		
	else{
        merge(n/2, n/2+1, vec2);
    }
	sort(vec2.begin(), vec2.end());
	
	ans = 0;
	for (int i = 0; i < vec1.size(); i++) {
        low = lower_bound(vec2.begin(), vec2.end(), a - vec1[i]);
        upp = upper_bound(vec2.begin(), vec2.end(), b - vec1[i]);
		ans = (upp - low)+ ans;
	}
	cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solution();
    return 0;
}
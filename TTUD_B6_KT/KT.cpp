#include <bits/stdc++.h>
using namespace std;


int N, counted=0;
bool used[10];
int a[10];

bool check (int v, int k) {
	if (used[v]) return false;
	return true;
}
void Try(int k){ 
	for (int v=1; v<=9; v++) {
		if (check(v,k)) {
			a[k] = v;
			used[v] =true;
			
			if (k==7){
				int S=a[1]*100+a[2]*10+a[3]-a[7]*100-62 +a[4]*1000+a[5]*100+a[6]*10+a[3];
				if (S==N)
				counted++;
			}
			else Try(k+1);
			
			a[k] = 0;
			used[v] =false;
		}
	}
}

int main() {
	cin>>N;
	Try(1);
	cout <<counted;
	return 0;
}
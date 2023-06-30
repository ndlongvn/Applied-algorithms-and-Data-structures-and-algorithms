#include<bits/stdc++.h>
using namespace std;
#define N 100001
int n, a[N], m;
vector<string> tokenize(string s, string del = " "){   
    vector<string> a;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        a.push_back(s.substr(start, end - start));
        // cout << s.substr(start, end - start) << endl;
    } while (end != -1);
    return a;
}
void input(){
    cin>> n;
    for(int i=1; i<=n; i++) cin>> a[i];
    cin>> m; string str; getline(cin, str); fflush(stdin); 
    for(int i=1; i<=m; i++){
        getline(cin, str);
        vector<string> vt= tokenize(str);
        if(vt[0]=="update"){
            a[stoi(vt[1])]= stoi(vt[2]);
        }
        else{
            int m= 0;
            for(int k= stoi(vt[1]); k<= stoi(vt[2]); k++){
                m= max(m, a[k]);
            }
            cout<< m<<endl;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
int binary_sear(int begin, int finish, string k){
    int mid= (begin+ finish) /2;
    if(begin>finish) return -1;
    if(ans[mid]==k) return mid;
    else if(ans[mid]<k) return binary_sear(mid+1, finish, k);
    else return binary_sear(begin, mid-1, k);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s, m; int k;
    while(1){
        cin>>s;
        if(s=="*") break;
        ans.push_back(s);
    }
    while(1){
        cin>>s;
        if(s=="***") break;
        cin>>m>>k;
        int hour= stoi(m.substr(0, 2));
        int minu= stoi(m.substr(3, 2));
        int sec= stoi(m.substr(6, 2));
        k= k+ hour*3600+ minu*60+ sec;
        int day= k/(3600*24);
        k= k- day*3600*24;
        hour= (k)/3600;
        k= k- hour*3600;
        minu= (k)/60;       
        sec= (k-minu*60);        
        int h= binary_sear(0, ans.size()-1, s);
            if(h!=-1){
                cout<< ans[h+day]<<" ";
                if(hour<10) cout<< 0<< hour<<":";
                else cout<<hour<<":";
                if(minu<10) cout<<0<<minu<<":";
                else cout<<minu<<":";
                if(sec<10) cout<<0<<sec<<endl;
                else cout<<sec<<endl;
            }
        
    }
}
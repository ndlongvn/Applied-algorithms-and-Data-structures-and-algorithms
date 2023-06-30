#include<bits/stdc++.h>
using namespace std;
unsigned long long N= 1e9+7;
unsigned long long exp(unsigned long long a,unsigned long long b){
    if(b==0) return 1;
    if(b==1) return a%N;
    unsigned long long m= exp(a, b/2);
    m= (m*m)%N;
    if(b%2==1) m=(m*a)%N;
    return m%N;
}
int main(){
    string a, b;
    cin>>a>>b;
    unsigned long long a1, b1, a2, b2;
    if(a.size()>3&&b.size()>3){
        a1= stoll(a.substr(0, a.size()-3));
        a2= stoll(a.substr(a.size()-3, a.size()));
        b1= stoll(b.substr(0, b.size()-3));
        b2= stoll(b.substr(b.size()-3, b.size()));
        // cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;
        cout<<(exp(exp(((a1%N)*1000+a2)%N, b1), 1000)*exp(((a1%N)*1000+a2)%N, b2))%N;
    }
    else{
        cout<< exp(stoll(a), stoll(b));
    }

    return 0;
} 
// 18446744073709551611 18446744073709551610
// 446959252

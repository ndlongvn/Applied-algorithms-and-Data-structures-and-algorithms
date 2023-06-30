#include<bits/stdc++.h>
using namespace std;
int lay(string x, int j, int k){
    int curnum=0;
    for(int i=j; i<=k; i++){
        curnum= curnum*10+ x[i]-'0';
    }
    return curnum;
}
int Karatshuba(string x, string y, int n ){
    if (n==1) return ((x[0]-'0')*(y[0]-'0'));
    else{
        int a= lay(x, n/2, n-1);
        int b= lay(x, 0, n/2-1);
        int c= lay(y, n/2, n-1);
        int d= lay(y, 0, n/2-1);
        int u= Karatshuba(to_string(a),to_string(c),n/2);
        int v= Karatshuba(to_string(b),to_string(d),n/2);
        int w= Karatshuba(to_string((a+b)), to_string((c+d)), n/2);
        return u*pow(10,n)+(w-u-v)*pow(10, n/2)+v;
    }
    return 0;
}
int main(){
    string x="1111";
    string y="1111";
    cout<<Karatshuba(x,y,4);
    return 0;
}
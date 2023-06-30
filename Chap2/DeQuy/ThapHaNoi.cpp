#include<bits/stdc++.h>
using namespace std;
void chuyen(char x, char y){
    cout<<"chuyen tu coc "<<x<<" sang "<<y<<endl;
}
void ThapHaNoi(int n,char a, char c, char b){
    if(n==1) chuyen(a,c);
    else{
        ThapHaNoi(n-1, a, b,c);
        ThapHaNoi(1, a, c ,b);
        ThapHaNoi(n-1, a, c, b);
    }

}
int main(){
    ThapHaNoi(5, 'a', 'b', 'c');
    return 0;
}
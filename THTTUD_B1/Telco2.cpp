#include<bits/stdc++.h>
using namespace std;
bool checkphone(string s){
    if(s.size()!=10) return false;
    for(int i=0; i<10; i++){
        if((s[i]<'1')||(s[i]>'9')) return false;
    }
    return true;
}
int counttime(string s){
    return (s[0]-'0')*36000+ (s[1]-'0')*3600+ (s[3]-'0')*600+ (s[4]-'0')*60+ (s[6]-'0')*10+ (s[7]-'0');
}
int main(){
    string sign, fnum, tnum, date, ftime, etime;
    map<string, int> numbercall;
    map<string, int> numbertime;
    bool check= true;
    int totalcall= 0;
    do{
        cin>> sign;
        if(sign=="#") continue;
        cin>> fnum>> tnum>> date>> ftime>> etime;
        totalcall++;
        if(check){
            if(checkphone(fnum)) check= false;
            if(checkphone(tnum)) check= false;
        }
        numbercall[fnum]++;
        numbertime[fnum]+= counttime(etime)- counttime(ftime);
        

    }
    while(sign!="#");
    string query;
    do{
        cin>> query;
        if(query=="#") continue;
        if(query=="?check_phone_number"){
            cout<<check<<endl;
        }
        if(query=="?number_total_calls"){
            cout<<totalcall<<endl;
        }
        if(query=="?number_calls_from"){
            string phone;
            cin>> phone;
            cout<< numbercall[phone]<<endl;
        }
        if(query=="?count_time_calls_from"){
            string phone;
            cin>> phone;
            cout<< numbertime[phone]<<endl;
        }
    }
    while(query!="#");
    return 0;
}
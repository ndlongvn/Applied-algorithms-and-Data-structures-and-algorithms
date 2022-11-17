#include<bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef struct call{
    int num_call;
    int time;
} call;
int main(){
    map<string, call> m1;
    bool check= true;
    int num= 0;
    int i= 0;
    string k= "";
    while(1){
        // call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
        getline(cin, k);       
        if((k!= "#")&&(k!="")&& i== 0) {
            num++;
            string s1= k.substr(5, 10);
            string s2= k.substr(16, 10);
            if(check){
                if ((s1.size()!=10 )||(s2.size()!=10 )){
                    check= false;
                } 
                for(int j=0; j< 10; j++){
                    if((!isdigit(s1[j]))||(!isdigit(s2[j]))) {
                        check= false;
                    }            
                }
            }
            int time = (k[47] - k[38]) * 36000 + (k[48] - k[39]) * 3600 + (k[50] - k[41]) * 600 + (k[51] - k[42]) * 60 + (k[53]-k[44]) *10 + (k[54] - k[45]);
            call *ca= &(m1[s1]);
            ca->num_call+=1;
            ca->time+= time;
        }
        if((k!= "#")&&(k!="")&& i== 1) {
            if(k=="?check_phone_number"){
                if(check) cout<<1<<endl;
                else{
                    cout<<0<<endl;
                }
            }
            else if(k.substr(0, 18)=="?number_calls_from"){
                cout<< m1[k.substr(19, 10)].num_call<< endl;
            }
            else if(k.substr(0, 19)=="?number_total_calls"){
                cout<< num<<endl;
            }
            else if(k.substr(0,22)=="?count_time_calls_from"){
                cout<< m1[k.substr(23, 10)].time <<endl;
            }
        }  
        if(k == "#" ) i++;         
        if(i==2) break;
    }
}
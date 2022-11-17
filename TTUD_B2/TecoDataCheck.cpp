#include<bits/stdc++.h>
using namespace std;
int count_number_call(vector<vector<string>> m, string n){
    int cou= 0;
    for(int i= 0; i< m.size(); i++){
        if (m[i][1]== n) cou++;
    }    
    return cou;
}
bool check_number(vector<vector<string>> m){
    for(int i= 0; i< m.size(); i++){
        
        if ((m[i][1].size()!=10 )||(m[i][2].size()!=10 )){
            return false;
        } 
        for(int j=0; j< 10; j++){
            if((!isdigit(m[i][1][j]))||(!isdigit(m[i][2][j]))) {
                return false;
            }            
        }
    }    
    return true;
}
int number_time_call(vector<vector<string>> m, string n){
    int cou= 0;
    for(int i= 0; i< m.size(); i++){
        if (m[i][1]== n) {
            vector<int> new_1;
            vector<int> new_2;
            string k1="";  
            istringstream iss1(m[i][4]);
            istringstream iss2(m[i][5]);
            while ( getline( iss1, k1, ':') ) {
                new_1.push_back(atoi(k1.c_str()) );
            }   
            while ( getline( iss2, k1, ':') ) {
                new_2.push_back(atoi(k1.c_str() ));
            }   
            cou= cou+ new_2[0]*360+ new_2[1]*60+ new_2[2]-(new_1[0]*360+ new_1[1]*60+ new_1[2]);
        }
    }    
    return cou;    
}
void lenh(vector<vector<string>> m, vector<string> m1){
        if(m1[0]=="?check_phone_number"){
            if(check_number(m)) cout<<1<<endl;
        }
        else if(m1[0]=="?number_calls_from"){
            cout<< count_number_call(m, m1[1])<< endl;
        }
        else if(m1[0]=="?number_total_calls"){
            cout<< m.size()<<endl;
        }
        else if(m1[0]=="?count_time_calls_from"){
            cout<<number_time_call(m, m1[1])<<endl;
        }
}
int main(){
    int i= 0;
    vector<string> s;
    vector<string> s1;
    vector<vector<string>> m;
    vector<vector<string>> m1;
    string k ="";
    bool check= true;
    while(1){     
            getline(cin, k);       
            if((k!= "#")&&(k!="")&& i== 0) {
                vector<string> new_;
                string k1="";  
                istringstream iss(k);
                while ( getline( iss, k1, ' ') ) {
                    new_.push_back(k1.c_str() );
                }
                m.push_back(new_);    
            }             
            if((k!= "#")&&(k!="")&& i== 1) {
                vector<string> new_1;
                string k1="";  
                istringstream iss(k);
                while ( getline( iss, k1, ' ') ) {
                    new_1.push_back(k1.c_str() );
                }
                lenh(m, new_1);
            }  
            if(k == "#" ) i++;         
            if(i==2) break;
    }
}

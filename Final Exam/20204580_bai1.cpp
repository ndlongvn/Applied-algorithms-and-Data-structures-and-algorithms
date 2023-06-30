#include<bits/stdc++.h>
using namespace std;
vector<string> day;
int binary_sear(int begin, int finish, string k){
    if(begin> finish) return -1;
    int mid= (begin+ finish)/2;
    if(day[mid]==k) return mid;
    else if(day[mid]> k) return binary_sear(begin, mid-1, k);
    else if(day[mid]< k) return binary_sear(mid+1, finish, k);
    return -1;
}
map<string, int> qty_custom;
map<string, vector<pair<string, string>>> qty_time;
set<string> trip;
struct dta{
    string day, code, date, time;
    int qty;
};
vector<dta> dtaa;
int cal_sec(string d1, string d2, string s1, string s2){
    int hour1= stoi(s1.substr(0, 2));
    int minu1= stoi(s1.substr(3, 2));
    int sec1= stoi(s1.substr(6, 2));
    int hour2= stoi(s2.substr(0, 2));
    int minu2= stoi(s2.substr(3, 2));
    int sec2= stoi(s2.substr(6, 2));
    int da1= binary_sear(0, day.size()-1, d1);
    int da2= binary_sear(0, day.size()-1, d2);
    return (da2- da1)*24*3600+ (hour2-hour1)*60*60+ (minu2- minu1)*60+ sec2- sec1;
}
void input(){
    string s;
    while(1){
        cin>>s;
        if(s=="*") break;
        day.push_back(s);
    }
    while(1){
        cin>>s;
        if(s=="***") break;
        string m, n, p; int q;
        cin>> m>>n>>p>>q;
        dtaa.push_back(dta{s, m, n, p, q});
        if(qty_time.find(s)==qty_time.end()){
            vector<pair<string, string>> h;
            h.push_back(pair<string, string>(n, p));
            qty_time[s]= h;
        }
        else{
            vector<pair<string, string>> h= qty_time[s];
            h.push_back(pair<string, string>(n, p));
            qty_time[s]= h;
        }
        trip.insert(s);
    }
    // cout<<qty_time.size();
    // for(auto i: qty_time){
    //     cout<<i.first<<" "<<i.second.size()<<" ";
    // }
    int total= 0;
    int total_trip= trip.size();
    // for(auto i: qty_time){
    //     sort(i.second.begin(), i.second.end(), [](pair<string, string> a, pair<string, string> b){
    //         if(a.first==b.first) return a.second< b.second;
    //         return a.first< b.first;
    //     });
    // }
    for(dta i: dtaa){
        total+= i.qty;
    }
    for(dta i: dtaa){
        if(qty_custom.find(i.code)!=qty_custom.end()){
            qty_custom[i.code]+= i.qty;
        }
        else{
            qty_custom[i.code]= i.qty;
        }
    }
    while(1){
        cin>>s;
        string m, n, p, q;
        if(s=="***") break;
        if(s=="TOTAL_QTY") cout<<total<<endl;
        if(s=="QTY_CUSTOMER"){
            cin>>m;
            cout<<qty_custom[m]<<endl;
        }
        if(s=="QTY_MAX_PREVIOD"){
            cin>>m>>n>>p>>q;
            vector<int> k;
            for(dta i: dtaa){
                if(cal_sec(m, i.date, n, i.time)>= 0){
                    if(cal_sec(i.date, p, i.time, q)>=0){
                        k.push_back(i.qty);
                    }
                }
            }
            int maxx= 0;
            for(int i: k){
                maxx= max(maxx, i);
            }
            cout<< maxx<<endl;
        }
        if(s=="TOTAL_TRIPS") cout<<total_trip<<endl;
        if(s=="TRAVEL_TIME_TRIP"){
            cin>>m;
            if(qty_time.find(m)==qty_time.end()) cout<<0<<endl;
            vector<pair<string, string>> k= qty_time[m];
            if(k.size()==1) cout<<0<<endl;
            else{
                sort(k.begin(), k.end(), [](pair<string, string> a, pair<string, string> b){
                    if(a.first==b.first) return a.second< b.second;
                    return a.first< b.first;
                });
                string x= k[0].first;
                string y= k[k.size()-1].first;
                string z= k[0].second;
                string t= k[k.size()-1].second;
                cout<<cal_sec(x, y, z, t)<<endl;
            }  
        } 
        if(s=="MAX_CONFLICT_TRIP"){
            cout<< 0<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
}
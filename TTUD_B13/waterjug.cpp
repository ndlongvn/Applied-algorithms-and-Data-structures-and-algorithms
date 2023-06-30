#include<bits/stdc++.h>
using namespace std;
#define pai pair<int, int>
int a, b, c;
int BFS_max(){
    int m= max(a, b);
    int n= min(a, b);
    int cnt= 0;
    if(c> m) return -1;
    queue<pai> Q;
    Q.push(pai(0, 0));
    while(!Q.empty()){
        pai a= Q.front(); Q.pop();
        if(a.first==c|| a.second==c){
            return cnt;
        }
        else{
            if(a.second==0){
                a.second+= m;
                cnt++;         
            }
            else if(a.first==0){
                int k= min(a.second, n);
                a.first= k;
                a.second-= k;
                cnt++;
            }
            else if(a.first==n){
                a.first= 0;
                cnt++;
            }
            else{
                if(a.first+ a.second> n){
                    a.second= a.second-(n- a.first); 
                    a.first= n;    
                    cnt++;  
                }
                else{
                    a.first= a.second+ a.first;
                    a.second= 0;
                    cnt++;
                }
            }
            // cout<<"("<< a.first<<","<<a.second<<")"<<endl;
            Q.push(a);
        }
        
    }
    return -1;
}
int BFS_min(){
    int n= max(a, b);
    int m= min(a, b);
    int cnt= 0;
    if(c> n) return -1;
    queue<pai> Q;
    Q.push(pai(0, 0));
    while(!Q.empty()){
        pai a= Q.front(); Q.pop();
        if(a.first==c|| a.second==c){
            return cnt;
        }
        else{
            if(a.second==0){
                a.second+= m;
                cnt++;         
            }
            else if(a.first==0){
                int k= min(a.second, n);
                a.first= k;
                a.second-= k;
                cnt++;
            }
            else if(a.first==n){
                a.first= 0;
                cnt++;
            }
            else{
                if(a.first+ a.second> n){
                    a.second= a.second-(n- a.first); 
                    a.first= n;    
                    cnt++;  
                }
                else{
                    a.first= a.second+ a.first;
                    a.second= 0;
                    cnt++;
                }
            }
            // cout<<"("<< a.first<<","<<a.second<<")"<<endl;
            Q.push(a);
        }
        
    }
    return -1;
}
int main(){
    cin>> a>> b>> c;
    // cout<< BFS_min()<<endl;
    cout<< min(BFS_max(), BFS_min());
    return 0;
}
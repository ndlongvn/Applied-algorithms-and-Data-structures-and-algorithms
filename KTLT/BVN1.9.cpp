// Nguyen Duy Long 20204580
// Viet chuong trinh in ra tat ca day con cua day cho truoc
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, *a; // n la kich thuoc cua mang; arr la con tro tro toi phan tu dau tien cua mang
    cin>>n; // Nhap n tu ban phim
    a= new int[n]; // Cap phat dong 
    for(int i=0; i<n; i++){ // Duyet lan luot cac phan tu cua mang
        cin>> *(a+i); // Nhap cac phan tu trong mang tu ban phim
    }
    for(int i=0; i<n; i++){ // Duyet lan luot tung phan tu i cua mang
        for(int j= i; j<n; j++){ // Duyet lan luot cac day phan tu j cua mang sau i
            for(int k=i; k<=j; k++){ // Duyet lan luot cac phan tu tu i toi j
                cout<<*(a+k)<<" "; // In ra day con bat dau tu i toi j
            }
        cout<<endl;
        }
    }
}
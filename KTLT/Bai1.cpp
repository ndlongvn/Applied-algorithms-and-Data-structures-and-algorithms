// Nguyen Duy Long 20204580 
// Viet chuong trinh nhap vao ma tran m*n
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

void allocate_mem(int ***mt, int m, int n){
    *mt= new int*[m]; // cap phat mt la mang cua cac con tro gom m phan tu
    for(int i=0; i<m; i++){ // duyet tung con tro cua mang mt
        *(*mt+i)= new int[n]; // voi moi con tro cap phat no la 1 mang gom n phan tu
    }
}


void input(int **mt, int m, int n){
    for(int i=0; i<m; i++){ // Duyet tung hang cua ma tran
        for(int j=0; j<n; j++){ // Duyet tung cot cua ma tran
            cout<<"mt["<<i<<"]["<<j<<"] = ";
            cin>>*(*(mt+i)+j); // Nhap phan tu cua ma tran
        }
    }
}

void output(int **mt, int m, int n){
    //# Print all elements of the matrix
    for(int i=0; i<m; i++){ // Duyet tung hang cua ma tran
        for(int j=0; j<n; j++){ // Duyet tung cot cua ma tran
            cout<<*(*(mt+i)+j)<<" "; // In ra tung phan tu cua ma tran
        }
        cout<<endl;
    }
    
}

int process(int **mt, int m, int n){
    int tong = 0;
    for(int i=0; i<m; i++){ // Duyet tung hang cua ma tran
        for(int j=0; j<n; j++){ // Duyet tung cot cua ma tran
            if(*(*(mt+i)+j)%2==0) tong+= *(*(mt+i)+j); // Neu phan tu do ma la so chan thi cong no vao bien tong
        }
    }
    
    return tong;
}

void free_mem(int **mt, int m, int n){
    //# Free memory
    for(int i=0; i<m; i++){ // Duyet tung hang cua ma tran
        free(*(mt+i)); // Giai phong ma tran cua tung hang
    }  
    free(mt); // Giai phong con tro tro toi ma tran
}

int main(){
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}
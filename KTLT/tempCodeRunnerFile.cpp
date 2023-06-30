// Nguyen Duy Long 20204580 
// Viet chuong trinh nhap mang tu ban phim va sap xep mang tang dan

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int *a;
int n, tmp;

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Cap phat bo nho dong cho a la con tro tro mot mang so nguyen 
    a= new int[n]; 
       
    for(int i = 0; i < n; i++)
        scanf("%d", a + i); 
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    //#Sort array
    
    for(int i=0; i<n-1; i++){ // Su dung sap xep chon de sap xep lai mang
        tmp= *(a+i);
        int index_min=i;
        for(int j=i+1; j<n; j++){
            if(*(a+j)<tmp){
                index_min= j;
            }
        }
        int tmp= *(a+i);
        *(a+i)=*(a+index_min);
        *(a+index_min)=tmp;
    }
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    delete [] a;
    return 0;
}
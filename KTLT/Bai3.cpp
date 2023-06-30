#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
// Nhap vao 3 so, dung con tro de in ra ket qua 3 so + 100 
// Nguyen Duy Long 20204580
// Ham counteven dem so chan trong mang ma ham nhan duoc

int counteven(int* arr, int size){
    // Khoi tao bien dem count dem so luong so chan
    int count = 0;

    for(int i=0; i< size; i++){// Duyet tung phan tu trong mang arr voi kich thuoc size
        
        if(*(arr+ i)%2==0) count++;// Neu phan tu thu i trong mang ma la so chan thi tang bien dem count
    }
    
    return count;// tra ve gia tri bien dem count so luong phan tu chan trong mang 
}
// Nguyen Duy Long 20204580
// Ham tra ve con tro tro toi gia tri lon nhat trong mang

double* maximum(double* a, int size){

    double *max; // Khoi tao con tro max kieu double

    max = a; // tro con tro toi phan tu dau tien cua mang

    if (a==NULL) return NULL; // neu con tro mang la rong thi tra ve null



    for(int i=0; i< size; i++){ // Duyet tung phan tu trong mang arr voi kich thuoc size
        if(*max< *(a+ i)){ // Neu noi dung con tro max tro den nho hon phan tu thu i cua mang
            max= a+ i; // thi gan max tro den phan tu thu i cua mang
        }
    }
    

    return max; // tra ve con tro max tro den phan tu lon nhat cua mang

}
// Nguyen Duy Long 20204580
// Ham dao nguoc mang cac so nguyen

void reversearray(int arr[], int size){

    int l = 0, r = size - 1, tmp;// Khoi tao l de duyet cac phan tu trong mang arr, r de chi kich thuoc mang, 
    // tmp la bien trung gian de thay doi gia tri cua 2 phan tu 

    for(l= 0; l<= r/2; l++ ){ // Duyet tung phan tu trong mang arr
        tmp= arr[l];
        arr[l]= arr[r-l];
        arr[r-l]= tmp;
        // Doi cho gia tri cac phan tu arr[l] voi arr[r-l]
    }

}
void ptr_reversearray(int *arr, int size){

    int l = 0, r = size - 1, tmp;// Khoi tao l de duyet cac phan tu trong mang arr, r de chi kich thuoc mang, 
    // tmp la bien trung gian de thay doi gia tri cua 2 phan tu 

    for(l= 0; l<= r/2; l++ ){ // Duyet tung phan tu trong mang arr
        tmp= *(arr+ l);
        *(arr+ l)= *(arr+r-l);
        *(arr+r-l)= tmp;
        // Doi cho gia tri ma con tro arr+l va arr+r-l tro den
    }

    

}
int main() {

    int x, y, z;

    int *ptr;
    int a[10]= {1,2,3,4,5,6,7,8,9,10};
    scanf("%d %d %d", &x, &y, &z);

    printf("Here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);

    ptr= &x;
    *ptr+= 100;
    ptr= &y;
    *ptr+= 100;
    ptr= &z;
    *ptr+= 100;
    

    printf("Once again, here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);
    cout<<counteven(a, 10);

    return 0;

} 
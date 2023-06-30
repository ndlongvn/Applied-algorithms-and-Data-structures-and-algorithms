#include<bits/stdc++.h>
using namespace std;
typedef struct NV{
    char ho[20], dem[20], ten[20];
    int nam, thang, ngay;
} NV;
//Dinh nghia phuong thuc so sanh
int compare_struct(NV* nv1, NV* nv2){
    int r1= strcmp(nv1->ten, nv2->ten);
    if( r1==0){
        int r2= strcmp(nv1->dem, nv2-> dem);
        if (r2==0){
            int r3= strcmp( nv1->ho, nv2->ho);
            if( r3==0){
                if(nv1->nam== nv2->nam){
                    if(nv1->thang== nv2->thang){
                        if(nv1-> ngay== nv2-> ngay){
                            return 0;
                        }
                        return nv1-> ngay< nv2-> ngay;
                    }
                    return nv1->thang< nv2->thang;
                }
                return nv1->nam< nv2->nam;
            }
            return r3< 0;
        }
        return r2< 0;
    }
    return r1< 0;    
}
// int compare_struct(NV a, NV b) {
//     int cmp;
//     cmp = strcmp(a.ho, b.ho);
//     if (cmp) return cmp;
//     cmp = strcmp(a.dem, b.dem);
//     if (cmp) return cmp;
//     cmp = strcmp(a.ten, b.ten);
//     if (cmp) return cmp;
//     cmp = a.nam - b.nam;
//     if (cmp) return cmp;
//     cmp = a.thang - b.thang;
//     if (cmp) return cmp;
//     cmp = a.ngay - b.ngay;
//     if (cmp) return cmp;
//     return 0;
// }
//neu nv1 < nv2 return 1
//ham sort

void Merge(NV* a, int left, int mid, int right){
    int st1= left;
    int st2= mid+1;
    NV tempa[right+1];
    int index= left;        
    for(;st1<=mid && st2<=right; index++){
        if(compare_struct(&a[st1], &a[st2])){
            tempa[index]= a[st1];
            st1++;
        }
        else{
            tempa[index]= a[st2];
            st2++;
        }
    }
    // for(int i= st2; i<=right; i++,index++){
    //     tempa[index]=a[st2];
    //         //index++;
    // }
    
    // for(int i= st1; i<=mid; i++, index++){
    //         tempa[index]=a[st1];
    //         //index++;
    // }
    // for(int i=left; i<=right; i++){
    //     a[i]=tempa[i];
    // }
    for(; st2<=right; st2++,index++){
        tempa[index]=a[st2];
            //index++;
    }
    for(; st1<=mid; st1++, index++){
        tempa[index]=a[st1];
            //index++;
    }
    
    for(int i=left; i<=right; i++){
        a[i]=tempa[i];
    }
}
void MergeSort(NV* a, int left, int right){
    if(left<right){
        int mid= (left+right)/2;
        MergeSort(a, left, mid);
        MergeSort(a, mid+1, right);
        Merge(a, left, mid, right);
    }
}
// ham main
int main(){
    NV* a = new NV[5]{
        {"Linh", "Dep", "Trai", 2002, 3, 16 },
        {"Do", "Duc", "Manh", 2021, 5, 26 },
        {"Nguyen", "Van", "Khanh", 2002, 10, 11 },
        {"Tran", "Thanh", "Luan", 1996, 12, 31 },
        {"Le", "Duc", "Minh", 2004, 2, 13 }
    };
    MergeSort(a, 0, 4);
    for(int i=0; i<5; i++){
        printf("%s %s %s: %d/%d/%d\n", a[i].ho, a[i].dem, a[i].ten, a[i].ngay, a[i].thang, a[i].nam);
    }
}

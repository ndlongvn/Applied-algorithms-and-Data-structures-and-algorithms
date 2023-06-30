#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    printf("Address Contents\n");
    for (int i=0; i < 3; i++){
        for (int j=0; j < 4; j++){
            printf("%8d %5d\n", &a[i][j], a[i][j]);
        }
    }
    
    int *ptr = &a[0][0];
    printf("Address Contents\n");
    for (int i=0; i < 3; i++){
        for (int j=0; j < 4; j++){
            printf("%8d %5d\n", ptr+ (i*4+j), *(ptr+ (i*4+j)));
        }
    }
    return 0;
}
    
    

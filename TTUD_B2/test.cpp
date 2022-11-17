#include<bits/stdc++.h>
using namespace std;
#define ROWS 3
#define COLS 3
void k(int m, int n){
    if((m>=0) &&(n> 0)){
        if(m== 0) cout<< 1;
    }
    // return 0;
}
int sosanh(char* s1, char* s2){
    return strcmp(s1, s2);
}
void inputMatrix(int matrix[][COLS], int rows, int cols){
    for(int i=0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            cin>>*(*(matrix+i)+j);
        }
    }
}
void printMatrix(int (*matrix)[COLS], int rows, int cols){
    for(int i=0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            cout<<*(*(matrix+i)+j)<<" ";
        }
        cout<<endl;
    }
}
int* sort_mang(int* a, int* b, int n, int m){
    int *mang= new int[n+m];
    for(int i=0; i<n; i++){
        mang[i]= a[i];
    }
    for(int i=n; i<n+m; i++){
        mang[i]= b[i-n];
    }
    sort(mang, mang+n+m, greater<int>());
    return mang;
}
typedef struct tri{
    int x;
    int y;
} tri;
int main(){
    int hist[4]={1,2,3,1};
    stack<int> s;
    int max_area = 0; // Initialize max area
    int tp; // To store top of stack
    int area_with_top= 0; // To store area with top bar
                       // as the smallest bar
  
    // Run through all bars of given histogram
    int i = 0;
    int n= 4;
    while (i < n) {
        // If this bar is higher than the bar on top
        // stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i]){
            printf("%d, push %d\n", i, hist[i]);
            s.push(i++);

        }

  
        // If this bar is lower than top of stack,
        // then calculate area of rectangle with stack
        // top as the smallest (or minimum height) bar.
        // 'i' is 'right index' for the top and element
        // before top in stack is 'left index'
        else {
            tp = s.top(); // store the top index
            s.pop(); // pop the top
  
            // Calculate the area with hist[tp] stack
            // as smallest bar
            area_with_top
                = hist[tp]
                  * (s.empty() ? i : i - s.top() - 1);
            printf("%d, cal %d\n", i, area_with_top);
            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
}

// call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
// call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
// call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
// call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
// #
// ?check_phone_number
// ?number_calls_from 0912345678
// ?number_total_calls
// ?count_time_calls_from 0912345678
// ?count_time_calls_from 0132465789
// #
// 3 3 2 2
// 1 1 1
// 1 0 1
// 1 1 1
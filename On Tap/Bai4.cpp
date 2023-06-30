#include<bits/stdc++.h>
using namespace std;
typedef struct RQ{
    // char time[20];
    // char date[20];
    string time;
    string date;
    int cout;
} RQ;
int compare_struct(RQ* rq1, RQ* rq2){
    // return strcmp(&(rq1->date), &(rq2->date));
    return (rq1->date).compare(rq2->date);
}
void Merge(RQ* a, int left, int mid, int right){
    int st1= left;
    int st2= mid+1;
    int index= left;
    RQ tempa[100];
    for(;st1<= mid && st2<= right; index++){
        if(compare_struct(&a[st1], &a[st2])<0){
            tempa[index]= a[st1];
            st1++;
        }
        else{
            tempa[index]= a[st2];
            st2++;
        }
    }
    for(;st1<=mid; index++,st1++){
        tempa[index]= a[st1];
    }
    for(;st2<=right; index++, st2++){
        tempa[index]= a[st2];
    }
    for(int i= left; i<= right; i++){
        a[i]= tempa[i];
    }
}
void Merge_Sort(RQ* a, int left, int right){
    if(left< right){
        int mid = (left+ right)/2;
        Merge_Sort(a, left, mid);
        Merge_Sort(a, mid+ 1, right);
        Merge(a, left, mid, right);
    }
}
void addRQ(string time, string date , RQ* root, int* length){
    bool a= false;
    for (int i=0; i< *length; i++){
        if (root[i].date.compare(date)==0){
            a= true;
            root[i].cout+= 1;
        }
    }
    if (!a){
        *length= *length+ 1;
        RQ* a= new RQ;
        a->cout=1;
        a->date= date;
        a->time= time;
        root[*length-1]= *a;
    }
}
int main(){
    RQ a[1000];
    int length= 0;
    // char date[20];
    // char time[20];
    // char name[20];
    string date, time, name, asg;
    for(int i=0; i<6; i++){
        cin>> date >> time >> name >>asg;
        addRQ(time, date, a, &length);
    }
    Merge_Sort(a, 0, length-1);
    for( int i=0; i<length; i++){
        printf("%s : %d\n", a[i].date.c_str(), a[i].cout);
    }
}
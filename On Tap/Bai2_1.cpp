#include<bits/stdc++.h>
using namespace std;
typedef struct SV {
    char ho[20], dem[20], ten[20];
    int nam, thang, ngay;
} SV;
void printSVArray(SV* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%20s %20s %20s (%d-%d-%d)\n", a[i].ho, a[i].dem, a[i].ten, a[i].nam, a[i].thang, a[i].ngay);
    }
}
void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
int compare(SV a, SV b) {
    int cmp;
    cmp = strcmp(a.ho, b.ho);
    if (cmp) return cmp;
    cmp = strcmp(a.dem, b.dem);
    if (cmp) return cmp;
    cmp = strcmp(a.ten, b.ten);
    if (cmp) return cmp;
    cmp = a.nam - b.nam;
    if (cmp) return cmp;
    cmp = a.thang - b.thang;
    if (cmp) return cmp;
    cmp = a.ngay - b.ngay;
    if (cmp) return cmp;
    return 0;
}
SV* tmpA = new SV[100];
void mergeSort(SV* a, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    int id1, id2, id;
    id = 0;
    id1 = l;
    id2 = mid + 1;
    while (id1 <= mid && id2 <= r) {
        if (compare(a[id1], a[id2]) < 0) {
            tmpA[id] = a[id1];
            id1++;
        }
        else {
            tmpA[id] = a[id2];
            id2++;
        }
        id++;
    }
    while (id1 <= mid) {
        tmpA[id] = a[id1];
        id1++;
        id++;
    }
    while (id2 <= r) {
        tmpA[id] = a[id2];
        id2++;
        id++;
    }
    for (id1 = l, id2 = 0; id2 < id; id2++, id1++) {
        a[id1] = tmpA[id2];
    }
}
int main() {
    int n = 12;
    SV* a = new SV[5]{
        {"Linh", "Dep", "Trai", 2002, 3, 16 },
        {"Do", "Duc", "Manh", 2021, 5, 26 },
        {"Nguyen", "Van", "Khanh", 2002, 10, 11 },
        {"Tran", "Thanh", "Luan", 1996, 12, 31 },
        {"Le", "Duc", "Minh", 2004, 2, 13 }
    };
    mergeSort(a, 0, 4);
    printSVArray(a, 5);
    return 0;
}
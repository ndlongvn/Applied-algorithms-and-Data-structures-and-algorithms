#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int n, a[N], m;
struct Node{
    int id, L, R;
};
int ST[N];
int maxVal[N];

void update(int id, int l, int r, int i, int v) {
    if (i < l || r < i) {
        // i nằm ngoài đoạn [l, r], ta bỏ qua nút i
        return ;
    }
    if (l == r) {
        // Đoạn chỉ gồm 1 phần tử, không có nút con
        ST[id] = v;
        return ;
    }

    // Gọi đệ quy để xử lý các nút con của nút id
    int mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);

    // Cập nhật lại giá trị max của đoạn [l, r] theo 2 nút con:
    ST[id] = max(ST[id*2], ST[id*2 + 1]);
}

// Truy vấn: tìm max đoạn [u, v]
// Hàm tìm max các phần tử trên cây ST nằm trong cây con gốc id - quản lý đoạn [l, r]
int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        // Đoạn [u, v] không giao với đoạn [l, r], ta bỏ qua đoạn này
        return 0;
    }
    if (u <= l && r <= v) {
        // Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, ta trả lại
        // thông tin lưu ở nút id
        return ST[id];
    }
    int mid = (l + r) / 2;
    // Gọi đệ quy với các con của nút id
    return max(get(id*2, l, mid, u, v), get(id*2 + 1, mid+1, r, u, v));
}

void input(){
    cin>> n; int k;
    for(int i=1; i<=n; i++){
        cin>> k;
        update(1, 1, n, i, k);
    }
    cin>> m; 
    string str; 
    int x, y;
    for(int i=1; i<=m; i++){
        cin>> str>> x>> y; 
        if(str=="update"){
            update(1, 1, n, x, y);
        }
        else{
            cout<<get(1, 1, n, x, y)<<endl;
        }
    }
}
int main(){
    input();
    return 0;
}
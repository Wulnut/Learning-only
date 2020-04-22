//quick_sort
#include <bits/stdc++.h>
using namespace std;

const int N = 10000010;

int n;
int q[N];

void quick_sort(int l, int r) {
    if (l >= r) return ;

    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    //q[(l + r) >> 1] 中的“>>”可以认为是向右移一位表示除2；愿意是位运算符 同理“<<”可以理解成乘2；

    while(i < j) {
        do i ++ ; while(q[i] < x);
        do j -- ; while(q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main(){
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> q[i];

    quick_sort(0, n - 1);

    for (int i = 0; i < n; ++i) cout << q[i] <<endl;

    return 0;
}

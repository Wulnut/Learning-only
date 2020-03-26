//binary_search

#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int q[N];
int n = 0;

bool binary_search(int x) {

    int l = 0, r = n;

    // 当左右两个值的在同一位置的时候循环结束
    while(r - l >= 1) {

        // >> 1 表示右移1，等价于除以2
        int i = (l + r) >> 1;
        
        // 二分查找的核心代码 分治的思想
        if(q[i] == x) return true;
        else if (q[i] < x) l = i + 1;
        else r = i;
        
    }

    return false;
}


int main(){
    cin >> n;

    for (int i  = 0; i < n; ++ i) cin >> q[i];

    sort(q, q + n); // binary_search的使用前提是数组有序

    binary_search(12); // 12表示查找的数

    return 0;
}

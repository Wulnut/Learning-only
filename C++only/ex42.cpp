// 问题描述
// 　　在数列 a[1], a[2], ..., a[n] 中，如果对于下标 i, j, k 满足 0<i<j<k<n+1 且 a[i]<a[j]<a[k]，则称 a[i], a[j], a[k] 为一组递增三元组，a[j]为递增三元组的中心。
// 　　给定一个数列，请问数列中有多少个元素可能是递增三元组的中心。
// 输入格式
// 　　输入的第一行包含一个整数 n。
// 　　第二行包含 n 个整数 a[1], a[2], ..., a[n]，相邻的整数间用空格分隔，表示给定的数列。
// 输出格式
// 　　输出一行包含一个整数，表示答案。
// 样例输入
// 5
// 1 2 5 3 5
// 样例输出
// 2
// 样例说明
//　　a[2] 和 a[4] 可能是三元组的中心。

#include <bits/stdc++.h>
using namespace std;
const int N = 10005;

int main() {
    int a[N];
    int n = 0;
    int sum = 0;

    cin >> n;

    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }

    for ( int i = 0; i < n; ++ i) {
        for (int j = i + 1; j < n - 1; ++ j) {
            for (int k = j + 1; k < n; ++ k) {
                if (a[i] < a[j] && a[j] < a[k]) {
                    sum ++;
                    a[j] = 0;
                    break;
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}

//
// Created by 98595 on 2020/4/6.
// 洛谷

#include <iostream>
#include <algorithm>
using namespace std;

const int M = 50005;
int arr[M];
int first[7];
int last[7];
int n;
int ans;

int main() {

    cin >> n;

    for (int i = 1; i <= n; ++ i) cin >> arr[i], arr[i] = (arr[i] + arr[i - 1]) % 7;

    for (int i = n; i >= 1; -- i) first[arr[i]] = i;

    for (int i = 1; i <= n; ++ i) last[arr[i]] = i;

    for (int i = 0; i <= 6; ++ i) ans = max(ans, last[i] - first[i]);

    cout << ans << endl;

    return 0;
}


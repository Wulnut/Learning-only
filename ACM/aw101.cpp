//
// Created by 98595 on 2020/4/17.
//https://www.acwing.com/problem/content/103/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define cin ios::sync_with_stdio(false); cin
typedef unsigned long long ll;

const int N = 10010;
ll height[N];

int main() {
    ll n, p, h, m;

    cin >> n >> p >> h >> m;
    height[1] = h;
    // unordered_set可以使用pair进行嵌套，但是要自定义哈希表
    set<pair<ll, ll> > exited;

    for (int i = 0, a, b; i < m; ++ i) {
        cin >> a >> b;

        if (a > b) swap(a, b);
        //通过唯一性来过滤相同的区间
        if (!exited.count({a, b})) {
            exited.insert({a, b});
            height[a + 1] --, height[b] ++;
        }
    }

    for (int i = 1; i <= n; ++ i) {
        height[i] += height[i - 1];
        cout << height[i] << "\n";
    }

    return 0;
}

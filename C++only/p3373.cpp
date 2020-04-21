//
// Created by 98595 on 2020/4/16.
//https://www.luogu.com.cn/problem/P3373 线段树
#include <iostream>
#include <algorithm>
#include <cstdio>
#define cin ios::sync_with_stdio(false); cin
using namespace std;
typedef unsigned long long ll;

const ll M = 100010;
ll data[M << 2];
ll arr [M << 2];
ll b   [M << 2];

ll n, m, q;

// 建立线段树
void build(ll l, ll r, ll p) {

    if (l == r) {
        data[p] = arr[l];
        return ;
    }

    ll m = (l + r) >> 1;
    build(l, m, p << 1);
    build(m + 1, r, p << 1 | 1);
    data[p] = data[p << 1] + data[p << 1 | 1];
}

// 区间加 [l, r]为被查询区间 [s, t]是操作区间
void updata_a(ll l, ll r,ll c,ll s,ll t, ll p) {

    if (l <= s && t <= r) {
        data[p] += (t - s + 1) * c;
        b[p] += c;
        return ;
    }

    ll m = (s + t) >> 1;
    if (b[p] && s != t) {
        data[p << 1] += b[p] * (m - s + 1), data[p << 1 | 1] += b[p] * (t - m);
        b[p << 1] += b[p], b[p << 1 | 1] += b[p];
        b[p] = 0;
    }

    if (l <= m) updata_a(l, r, c, s, m, p << 1);
    if (r >  m) updata_a(l, r, c, m + 1, t, p << 1 | 1);
    data[p] = data[p << 1] + data[p << 1 | 1];
}

// 区间乘
void updata_t(ll l, ll r, ll c, ll s, ll t, ll p) {

    if (l <= s && t <= r) {
        data[p] *= (t - s + 1) * c;
        b[p] += c;
        return ;
    }

    ll m = (s + t) >> 1;
    if (b[p] && s != t) {
        data[p << 1] *= b[p] * (m - s + 1), data[p << 1 | 1] *= b[p] * (t - m);
        b[p << 1] += b[p], b[p << 1 | 1] += b[p];
        b[p] = 0;
    }

    if (l <= m) updata_t(l, r, c, s, m, p << 1);
    if (r >  m) updata_t(l, r, c, m + 1, t, p << 1 | 1);
    data[p] = data[p << 1] + data[p << 1 | 1];
}

// 区间求和
ll query(ll l, ll r, ll s, ll t, ll p) {

    if (l <= s && t <= r) {
        return data[p];
    }

    ll m = (s + t) >> 1;
    if (b[p]) {
        data[p << 1] += b[p] * (m - s + 1), data[p << 1 | 1] += b[p] * (t - m);
        b[p << 1] += b[p], b[p << 1 | 1] += b[p];
        b[p] = 0;
    }

    ll sum = 0;
    if (l <= m) sum  = query(l, r, s, m, p << 1);
    if (r >  m) sum += query(l, r, m + 1, t, p << 1 | 1) % q;
    return sum;
}


int main() {

    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);

    ll x, y, k, a, sum;

    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++ i) {
        cin >> arr[i];
    }

    build(1, n, 1);
    
    // 这里的m使用 m--才对尽量少用--m
    while (m--) {

        cin >> a;

        switch (a) {

            case 1: {
                cin >> x >> y >> k;
                updata_t (x, y, k, 1, n, 1);
                break;
            }

            case 2: {
                cin >> x >> y >> k;
                updata_a(x, y, k, 1, n, 1);
                break;
            }

            case 3: {
                cin >> x >> y;
                sum = query(x, y, 1, n, 1);
                cout << sum  << '\n';
            }
        }
    }

    return 0;
}
//
// Created by 98595 on 2020/4/16.
//https://www.luogu.com.cn/problem/P3373 线段树
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define cin ios::sync_with_stdio(false); cin

typedef unsigned long long ll;

const int M = 100005;

ll data[M << 2];
ll arr[M << 2];
ll b[M << 2];

void build(ll l, ll s, ll q) {

    if (l == s) {
        data[q] = arr[l];
        return ;
    }

    ll m = (l + s) >> 1;

    build (l, m, q << 1);
    build (m + 1, s, q << 1 | 1);
    data[q] = data[q << 1] + data[q << 1 | 1];
}

void updata(ll l, ll r, ll c, ll s, ll t, ll q) {

    if (l <= s && t <= r) {
        data[q] += c * (t - s + 1);
        b[q] += c;
        return ;
    }

    ll m = (s + t) >> 1;

    if (b[q] && s != t) {
        data[q << 1] += b[q] * (m - s + 1), data[q << 1 | 1] += b[q] * (t - m);
        b[q << 1] += b[q], b[q << 1 | 1] += b[q];
        b[q] = 0;
    }

    if (l <= m) updata(l, r, c, s, m, q << 1);
    if (r >  m) updata(l, r, c, m + 1, t, q << 1 | 1);

    data[q] = data[q << 1] + data[q << 1 | 1];
}

int query(ll l, ll r, ll s, ll t, ll q) {

    if (l <= s && t <= r) {
        return data[q];
    }

    ll m = (s + t) << 1;

    if (b[q]) {
        data[q << 1] += b[q] * (m - s + 1), data[q << 1 | 1] += b[q] * (t - m);
        b[q << 1] += b[q], b[q << 1 | 1] += b[q];
        b[q] = 0;
    }

    ll sum = 0;
    if (l <= m) sum   = query(l, r, s, m + 1, q << 1);
    if (r > m)  sum  += query(l, r, m, t, q << 1 | 1);

    return sum;
}

ll query_m(ll l, ll r, ll s, ll t, ll q, ll p) {
    if ( l <= s && t <= r) {
        return data[q] % p;
    }

    ll m = (s + t) << 1;

    if (b[q]) {
        data[q << 1] += b[q] * (m - s + 1), data[q << 1 | 1] += b[q] * (t - m);
        b[q << 1] += b[q], b[q << 1 | 1] += b[q];
        b[q] = 0;
    }

    ll sum = 0;
    if (l <= m) sum  = query_m(l, r, s, m + 1, q << 1, p);
    if (r >  m) sum += query_m(l, r, m, t, q << 1 | 1, p);

    return sum % p;
}


int main() {
    ll n, m, p;
    ll a, x, y, w;

    cin >> n >> m >> p;

    for (ll i = 1; i <= n; ++ i) {
        scanf("%lld", &arr[i]);
    }

    build(1, n, 1);

    while (-- m) {
        cin >> a;

        switch (a) {

            case 1: {
                scanf("%lld%lld%lld", &x, &y, &w);
                updata(x, y, w, 1, n, 1);
                break;
            }

            case 2: {
                ll sum = 0;
                scanf("%lld%lld", &x, &y);
                sum = query(x, y, 1, n, 1);
                cout << sum << "\n";
            }

            case 3: {
                ll sum = 0;
                scanf("%lld%lld", &x, &y);
                sum = query_m(x, y, 1, n, 1, p);
                cout << sum << "\n";
            }
        }

    }
    return 0;
}


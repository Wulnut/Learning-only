#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define cin ios::sync_with_stdio(false); cin
typedef unsigned long long ll;

const ll M = 10000010;

ll arr[M << 2];
ll date[M << 2];
ll b[M << 2];

void build (ll l, ll r, ll p) {

    if (l == r) {
        date[p] = arr[l];
        return ;
    }

    ll m = (l + r) >> 1;
    build(l, m, p << 1);
    build (m + 1, r, p << 1 | 1);
    date[p] = date[p << 1] + date[p << 1 | 1];
}

void update(ll l, ll r, ll c,ll s, ll t, ll p) {

    if (l <= s && t <= r) {
        date[p] += c * (t - s + 1);
        b[p] += c;
        return ;
    }

    ll m = (s + t) >> 1;
    if (b[p] && s != t) {
        date[p << 1] += b[p] * (m - s + 1), date[p << 1 | 1] += b[p] * (t - m);
        b[p << 1] += b[p], b[p << 1 | 1] += b[p];
        b[p] = 0;
    }

    if (l <= m) update(l, r, c, s, m, p << 1);
    if (r > m)  update(l, r, c, m + 1, t, p << 1 | 1);

    date[p] = date[p << 1] + date[p << 1 | 1];
}

ll query(ll l, ll r, ll s, ll t, ll p) {

    if (l <= s && t <= r) {
        return date[p];
    }

    ll m = (s + t) >> 1;

    if (b[p]) {
        date[p << 1] += b[p] * (m - s + 1), date[p << 1 | 1] += b[p] * (t - m);
        b[p << 1] += b[p], b[p << 1 | 1] += b[p];
        b[p] = 0;
    }

    ll sum = 0;
    if (l <= m) sum  = query(l, r, s, m, p << 1);
    if (r > m)  sum += query(l, r, m + 1,  t, p << 1 | 1);
    return sum;
}

int main() {
    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    ll n, m, a;
    ll x, y, w;

    scanf("%lld%lld", &n, &m);;

    for (int i = 1; i <= n; ++ i) {
       scanf("%lld",&arr[i]);;
    }

    build(1, n, 1);

    while (m --) {
       scanf("%lld",&a);;

        switch (a) {

            case 1:{
                scanf("%lld%lld%lld",&x,&y,&w);;
                update(x, y, w, 1, n, 1);
                break;
            }

            case 2:{
                ll sum = 0;
               scanf("%lld%lld",&x,&y);;
                sum = query(x, y, 1, n, 1);
                cout << sum << "\n";
            }
        }
    }
    return 0;
}

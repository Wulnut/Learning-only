// https://www.acwing.com/problem/content/102/
// acwing增减序列

#include <bits/stdc++.h>
using namespace std;
#define cin ios::sync_with_stdio(false); cin // cin 优化加速
#define N 110000
typedef long long ll;

ll n, m, i, j, p, q, a[N];

int main() {
    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
     
    cin >> n;

    for (i  = 1; i <= n; ++ i) {
        cin >> a[i];
    }

    for (i = 2; i <= n; ++ i) {
        ll c = a[i] - a[i - 1];
        if (c > 0) {
            p += c;
        } else {
            q -= c;
        }
    }
    // min(p, q) + abs(p - q) = max(p, q)
    ll ans1 = max(p, q), ans2 = abs(p - q) + 1;
    cout << ans1 << endl << ans2;

    return 0;
}
// https://www.luogu.com.cn/problem/P4552
// 洛谷
#include <bits/stdc++.h>
using namespace std;
#define cin ios::sync_with_stdio(false); cin
typedef long long ll;
const int M = 1e5 + 5;

ll arr[M];
ll p, q;


int main() {

    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        cin >> arr[i];
    }

    for (int i = 2; i <= n; ++ i) {
        ll c = arr[i] - arr[i - 1];

        if (c > 0) p += c;
        else q -= c;
    }

    ll ans1 = max(p, q), ans2 = abs(p - q) + 1;

    cout << ans1 << "\n" << ans2;

    return 0;
}
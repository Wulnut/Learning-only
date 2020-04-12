// https://www.acwing.com/problem/content/102/
// acwing增减序列

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M = 1e5 + 5;

int arr[M];
ll n, p, q;

int main()
{

    cin >> n;

    for (ll i = 1; i <= n; ++i) arr[i];

    for (ll i = 2; i <= n; ++ i) {

        ll c = arr[i] - arr[i - 1];

        if (c > 0) p += c;
        else q -= c;
    }

    ll ans1 = max(p, q), ans2 = abs(p - q) + 1;

    cout << ans1 << endl << ans2;

    return 0;
}
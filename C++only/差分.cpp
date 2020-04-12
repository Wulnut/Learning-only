// https://www.acwing.com/problem/content/799/
// acwing差分


#include <bits/stdc++.h>
using namespace std;

const int M = 100005;

int l , r, c;
int pre[M];
int arr[M];
int n, m;


int main() {

    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> pre[i];

    for (int i = 1; i <= n; ++i) arr[i] = pre[i] - pre[i - 1];

    for (int i = 0; i < m; ++ i) {
        cin >> l >> r >> c;

        arr[l] += c;
        arr[r + 1] -= c;

    }

    for (int i = 1; i <= n; ++ i) {
        arr[i] = arr[i - 1] + arr[i];
        cout << arr[i] << " ";
    }

    //for (int i = 1; i <= n; ++ i) cout << arr[i] << " ";

    return 0;
}
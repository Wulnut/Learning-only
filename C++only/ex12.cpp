#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int a[MAX];
int n, k;

bool dfs(int i, int s) {
    if (s > k) return false;
    if (i == n) return s == k;

    if (dfs(i + 1, s)) return true;
    if (dfs(i + 1, s + a[i])) return true;

    return false;
}

int main() {
    cin >> n >> k;

    for ( int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (dfs(0, 0)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
    return 0;
}
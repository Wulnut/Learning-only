#include <bits/stdc++.h>
using namespace std;

const int M = 10000000;

int n;
long long  fib[M];

void solve() {
    long long ans = 0;
    int i = 0;
    fib[0] = 0;
    fib[1] = 1;

    if (n == 1 || n == 2) {
        cout << 1 << endl;
        return ;
    }

    for (i = 2; i <= n; i++ ) {
        fib[i] = fib[i - 1]  + fib[i - 2] ;
        ans = fib[i];
    }

    //ans %= 10007;
    cout << ans << endl;
}

//999999

int main() {
    cin >> n;


    solve();


    return 0;
}
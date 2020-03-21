// 级数求和
// https://vijos.org/p/1127

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 1;
    int a = 0;
    double sum = 0;

    cin >> a;

    while (sum <= a) {
        sum += 1.0 / n;
        n++;
    }

    cout << n - 1 << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool cmp (const int& a, const int& b) {
    return a > b;
}

int main() {
    int ping_n = 0;
    int tao_n = 0;
    int ping[ping_n];
    int tao[tao_n];

    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);

    cin >> ping_n >> tao_n;

    for (int i = 0; i < ping_n; ++ i) cin >> ping[i];
    getchar();
    for (int i = 0; i < tao_n; ++ i) cin >> tao[i];

    sort(ping, ping + ping_n, cmp);
    sort(tao, tao + tao_n, cmp);

    //cout << ping[1] << tao[1] << endl;

    for (int i = 0; i < ping_n; ++ i) {
        for (int j = 0; j < tao_n; ++ j) {

            if (ping[i] > tao[j]) {
                -- tao_n;
            }

        }
    }

    cout << tao_n + 1 << endl;

    return 0;
}
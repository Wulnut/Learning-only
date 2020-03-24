#include <bits/stdc++.h>
using namespace std;

const int N = 20005;

bool cmp (const int& a, const int& b) {
    return a > b;
}

int main() {
    int ping_n = 0;
    int tao_n = 0;
    int ping[N];
    int tao[N];
    int ans = 0; 

     //freopen("note.txt", "r", stdin);
     //freopen("ans.txt", "w", stdout);

    cin >> ping_n >> tao_n;
    for (int i = 0; i < ping_n; ++ i) cin >> ping[i];
    for (int i = 0; i < tao_n; ++ i) cin >> tao[i];

    sort(ping, ping + ping_n, cmp);
    sort(tao, tao + tao_n, cmp);

    //  for (int i = 0; i < ping_n; ++ i) cout << " " << ping[i];
    //  cout << endl;
    //  for (int i = 0; i < tao_n; ++ i) cout << " " << tao[i];

    ans = tao_n;

    for (int i = 0; i < ping_n; ++ i) {
        for (int j = 0; j < tao_n; ++ j) {
            if (ping[i] > tao[j] && tao[j] != 0 && ping[i] != 0) {
                ping[i] = 0;
                -- ans;
                tao[j] = 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
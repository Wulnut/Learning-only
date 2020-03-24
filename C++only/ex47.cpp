#include <bits/stdc++.h>
using namespace std;

 const int N = 10005;   

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int L = 0; // 路的长度
    pair<int, int> area[N];
    int M = 0; // 循环次数
    int w1 = 0; //
    int w2 = 0;

    cin >> L >> M;

    for (int i = 0; i < M ; ++ i) {
        cin >> area[i].first >> area[i].second;
    }

    sort(area, area + M, cmp);

    for (int i = 0; i < M; ++ i) {
        
        if (area[i].second > area[i + 1].first && area[i].second < area[i + 1].second) {
            w1 = max(w1, (area[i + 1].second - area[i].first + 1));
        } else {
        w2 = L - area[i].second + area[i].first;
        }

    }

    w2 = w2 - w1 + 1;

    cout << w2 <<endl;

    return 0;
}
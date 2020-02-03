#include <bits/stdc++.h>
using namespace std;
int i = 0;

int solve(int x){
    int cnt = 1;
    if (cnt == i) {
        return cnt;
    }

    return (solve(cnt + 1) + 1) * 2;
}

int main(){
    int ans = 0;

    cin >> i;

    ans = solve(i);

    cout << ans << endl;

    return 0;
}
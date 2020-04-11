#include <bits/stdc++.h>
using namespace std;

const int M = 5005;

int table[M][M];

int n, r;
int ans;

int main() {

    cin >> n >> r;

    int row, colnum;

    row = colnum = r;

    for (int i = 1; i <= n; ++i) {

        int x, y, z;

        cin >> x >> y >> z;

        x ++ ;
        y ++ ;

        table[x][y] = z;  

        row = max(row, x);
        colnum = max(colnum, y);
        
    }

    for (int i = 1; i <= row; ++ i) {
        for (int j = 1; j <= colnum; ++ j) {
            table[i][j] = table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1] + table[i][j];
        }
    }

    for (int i = r; i <= row; ++ i) {
        for (int j = r; j <= colnum; ++ j) {
            ans = max(ans, table[i][j] - table[i-r][j] - table[i][j - r] + table[i - r][j - r]);
        }
    }

    cout << ans << endl;

    return 0;
}
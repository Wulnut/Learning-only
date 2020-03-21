//https://vijos.org/p/1096
// 存钱
#include <bits/stdc++.h>
using namespace std;

int main() {
    int b = 0;
    int h = 300;
    int cnt = 0;
    int s = 0;
    int e = 0;

    //freopen("note.txt", "r", stdin);
    //freopen("ans.txt", "w", stdout);
    
    for (int i = 0; i < 12; ++i) {
        cin >> b;

        if ((h - b) >= 100) {
            s = (h - b) / 100 * 100;
            cnt += s;

            h = h - b - s;
            if (h < 0) {
                e = i;
                break;
            }
            h += 300;
        }
        else {
            h -= b;
            if (h < 0) {
                e = i + 1;
                break;
            }
            h  += 300;
        }

    }
    h -= 300;

    if (h > 0) {
        //cout << h << endl;
        h = h + 1.2 * cnt;
        cout << h << endl;  
    }
    else {
        cout << -e << endl;
    }

    return 0;   
}

// 乒乓球
//https://vijos.org/p/1217

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;

int main() {
    
    int w_11Temp = 0, l_11Temp = 0, w_21Temp = 0, l_21Temp = 0; // 已11 21为单位统计数量
    int w11[MAX], l11[MAX], w21[MAX], l21[MAX]; // 记录每次比赛的小比分
    int c11 = 0, c21 = 0;

    char c;

    while ((c = getchar()) != 'E') {

        if (c == 'W') ++ w_11Temp, ++ w_21Temp;
        if (c == 'L') ++ l_11Temp, ++ l_21Temp;

        if ((w_11Temp > 10 || l_11Temp > 10) && abs(w_11Temp - l_11Temp) > 1) {
            w11[c11] = w_11Temp, l11[c11] = l_11Temp, ++ c11, w_11Temp = l_11Temp = 0;
        }

        if ((w_21Temp > 20 || l_21Temp > 20) && abs(w_21Temp - w_21Temp) > 1) {
            w21[c21] = w_21Temp, l21[c21] = l_21Temp, ++ c21, w_21Temp = l_21Temp = 0;
        }

    }

    for (int i = 0; i < c11; ++ i) {
        cout << w11[i] << ":" << l11[i] << endl;
    }
    cout << w_11Temp << ":" << l_11Temp << endl;

    cout << endl;
    
    for (int i = 0; i < c21; ++ i) {
        cout << w21[i] << ":" << l21[i] << endl;
    }
    cout << w_21Temp << ":" << l_21Temp << endl;


    return 0;
}
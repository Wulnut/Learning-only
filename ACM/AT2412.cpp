//
// Created by 98595 on 2020/4/6.
//洛谷

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int M = 100005;
//
//int main() {
//    int n;
//    int k;
//    int arr[M];
//    int ans = 0;
//
//    cin >> n >> k;
//
//    for (int i = 0; i < n; ++ i) cin >> arr[i];
//
//    int first = 0;
//    int second = k - 1;
//
//    while (second < n && (second - first + 1)) {
//
//        int temp = 0;
//        for (int i = first; i <= second; ++ i) {
//            temp += arr[i];
//        }
//
//        ans = max(ans, temp);
//
//        first ++;
//        second ++;
//
//    }
//
//    cout << ans << endl;
//
//    return 0;
//}
//

// 前缀和解法

#include <iostream>
#include <algorithm>
using namespace std;

const int M = 100005;

int arr[M];
int sub[M];
int n;
int k;
int ans;


int main() {
    cin >> n >> k;

    //for (int i = 1; i < n; ++ i) cin >> arr[i], sub[i] = sub[i - 1] + arr[i];

    for (int i = 1; i < n; ++ i) {
        cin >> arr[i];
        sub[i] = sub[i - 1] + arr[i];
    }

    for (int i = k; i < n; ++ i) {
        ans = max(ans, sub[i] - sub[i - k]);
    }

    cout << ans << endl;

    return 0;
}

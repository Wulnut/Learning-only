// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximRectangle(vector<int>& h) {
        stack<int> s; // 下标
        h.push_back(0); // 在最后一位添加一个最低点
        int sum = 0;

        for (int i = 0; i < h.size(); ++ i) {
            if (s.empty() || h[i] > h[s.top()]) 
            s.push(i);

            else {
                int temp = 0;
                sum = max(sum, h[s.top()] * (s.empty() ? i : i - s.top() - 1));
                -- i;
            }
        }
        
        return sum;
    }
};

int main() {
     Solution s;
     int a[3] = {2, 4, 3};

     vector<int> h(a, a + 3);


    // s.maximRectangle(h);

     cout << s.maximRectangle(h) << endl;

    // stack<int> a;

    // for (int i = 0; i < 5; ++ i) {
    //     a.push(i);
    // }

    // cout << a.top() << endl;

    return 0;
}

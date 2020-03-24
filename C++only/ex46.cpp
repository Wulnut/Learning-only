// 栈排序


#include <bits/stdc++.h>
using namespace std;

stack<int> sorting(stack<int> s) {
    stack<int> result; // result存放了返回值，即输出栈

    if (s.empty()) return result; // 边界情况

    int tmp = s.top();

    s.pop();

    while (!s.empty() || (!result.empty() && result.top() > tmp)) {

        if (result.empty() || result.top() <= tmp) {
            result.push(tmp);
            tmp = s.top();// 更新tmp
            s.pop();
        } else {
            // 如果tmp比result的栈顶要小
            s.push(result.top());
            result.pop();
        }
    }

    result.push(tmp);

    return result;

}

int main() {

    return 0;
}


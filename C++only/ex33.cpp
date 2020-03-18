#include <bits/stdc++.h>
using namespace std;

int main() {

    // 声明
    set<int> s;

    // 插入元素
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    // 查找元素
    set<int>::iterator ite;

    ite = s.find(1);

    if (ite == s.end()) puts("not found");
    else puts("found");

    ite = s.find(2);
    if (ite == s.end()) puts("not found");
    else puts("found");

    s.erase(3);

    // 其他的查找元素的方法

    if (s.count(3) != 0) puts("found");
    else puts("not found");

    // 遍历所有元素
    for (ite = s.begin(); ite != s.end(); ++ ite) {
        printf("%d ", *ite);
    }

    // 遍历整个容器
    for (const auto& i : s) {
        printf("%d", i);
    }

    return 0;
}
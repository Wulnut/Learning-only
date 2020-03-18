#include <bits/stdc++.h>
using namespace std;

int main() {
    // 声明（int为键值，const char* 为值）
    map<int, const char*> m;

    // 插入元素
    m.insert(make_pair(1, "one"));
    m.insert(make_pair(2, "two"));
    m[100] = "HUNDERD"; // 另一种写法

    // 查找元素
    map<int, const char*> :: iterator ite;
    ite = m.find(1);
    puts(ite -> second);

    ite = m.find(2);
    if (ite == m.end()) puts("Not found"); //not found
    else puts(ite -> second);

    puts(m[10]);

    // 删除元素
    m.erase(10);

    // 遍历所有元素
    for (ite = m.begin(); ite != m.end(); ++ ite) {
        printf("%d: %s\n", ite -> first, ite -> second);
    }

    // 这是c++11的新特性，范围for，相当于java的for each。v是一个可遍历的容器或流，比如vector类型，i就用来在遍历过程中获得容器里的每一个元素。

    // 例如：vector<int> v={1,2,3,4};

    // for(auto i:v)

    // cout<<i

    // 结果就是1234

    return 0;
}
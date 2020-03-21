#include <map>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> x;

    for (int i = 0; i < 10; ++i) {
        x.push_back(i); // add element;
    }
    // x.pop_back(); // pop 元素
    // x.insert(pos, e) // 在某个位置插入
    // vector类似一个栈

    /*
    * vector<Elem> c; 普通构造
    * vector<Elem> c1(c2); 拷贝构造
    * x.size() vector当前的长度
    * x.empty() vector是否位空
    * == != < > <= >= 比较两个vector不是比较两个vector里面的值
    * x.swap(x1) 交换两个vector交换两个vector里面所有的值
    * x.begin() & x.end() // 返回第一个位置和最后一个位置的迭代器
    * x.at(index) 某个index上的元素
    * x[index] []被重载过和数组使用类似
    * x.front() & x.back() 会给第一个元素和最后一个元素
    * x.erase(pos) 清除某个位置上的数据
    * x.clear() 全部清除
    * x.find(first, last, item) 给一个开始与结束，在给个数据查找是否在vector里面
    */
    vector<int>::iterator p;
    // 如果只是访问就const auto& i 好一些
    for (const auto& q : x) {
        cout << q << endl;
    }

    for (p = x.begin(); p != x.end(); ++p) {
        cout << *p << endl;
    }

    return 0;
}

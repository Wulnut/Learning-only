
//stack的手动实现
#include <bits/stdc++.h>
using namespace std;

class Stack {
    private:
    int data[10000];
    int top = -1;
    public:
    void push(int x);
    void pop();
    int topval();
};

void Stack::push(int x) {
    top ++;
    if (top < 10000 ) {
        data[top] = x;
    }
    else{
        top --;
        cout << "stack overflow" << endl;
    }
}

void Stack::pop() {
    if (top >= 0) {
        top --;
    }
}

int Stack::topval() {
    if (top >= 0) {
        return data[top];
    }
}

int main(){
    return 0;
}
/*
template <class T, class Container = std::deque<T> >
class stack {
 public:
    typedef typename Container::value_type value_type;
    typedef typename Container::reference reference;
    typedef typename Container::const_reference const_reference;
    typedef typename Container::size_type size_type;
    typedef Container container_type;
 
 protected:
    Container c;
 
 public:
    explicit stack(const Container&);
    explicit stack(Container&& = Container());
    template <class Alloc> explicit stack(const Alloc&);
    template <class Alloc> stack(const Container&, const Alloc&);
    template <class Alloc> stack(Container&&, const Alloc&);
    template <class Alloc> stack(const stack&, const Alloc&);
    template <class Alloc> stack(stack&&, const Alloc&);
 
    bool empty() const {
        return c.empty();
    }
    size_type size() const {
        return c.size();
    }
    reference top() {
        return c.back();
    }
    const_reference top() const {
        return c.back();
    }
    void push(const value_type& x) {
        c.push_back(x);
    }
    void push(value_type&& x) {
        c.push_back(std::move(x));
    }
    template <class... Args> void emplace(Args&&... args) {
        c.emplace_back(std::forward<Args>(args)...);
    }
    void pop() {
        c.pop_back();
    }
    void swap(stack& s) noexcept(noexcept(swap(c, s.c))) {
        using std::swap;
        swap(c, s.c);
    }
};

g++ ex2.cpp -o ex2
*/

#include<bits/stdc++.h>

using namespace std;


int main(){

   stack<int> s;

    for( int i = 0; i < 10; i++){
        s.push(i);
    }

    cout<<s.size()<<endl;
    cout<<s.top()<<endl;


    s.push(11);
    cout<<s.top()<<endl;



    return 0;
}
#ifndef MYSTL_LIST_H_
#define MYSTL_LIST_H_

// 这是一个头文件包含list的模板类
// list:双向链表

#include <initializer_list>
#include "iterator.h"

namespace MySTL {

    // 声明了两个结构体变量。
    template <class T> struct list_node_base;
    template <class T> struct list_node;

    // 奖两个结构体放在一起
    template <class T>
    struct node_traits {
        typedef list_node_base<T>* base_ptr;
        typedef list_node<T>*      node_ptr;
    };

    // list的节点
    template <class T>
    struct list_node_base {
        // 重命名两个指针
        typedef typename node_traits<T>::base_ptr base_ptr;
        typedef typename node_traits<T>::node_ptr node_ptr;

        base_ptr prev; // 前一个节点
        base_ptr next; // 下一个节点

        // =default 是C++11新特性表示申明为默认构造函数
        list_node_base() = default;

        node_ptr as_node() {
            return static_cast<node_ptr>(self());
        }

        // 前一个节点和下一个节点都指向这个结构体的地址
        void unlink() {
            prev = next = self();
        } 

        base_ptr self() {
            return static_cast<base_ptr>(&* this);
        }

    };

    template <class T> 
    struct list_node : public list_node_base<T> {

        typedef typename node_traits<T>::base_ptr base_ptr;
        typedef typename node_traits<T>::node_ptr node_ptr;

        T value; // 数据域

        list_node() = default;

        list_node(const T& v) : value(v) { }
        // move是std种包含在utility中的一个方法，可以将左值转换为右值
        list_node(T&& v) : value(MySTL :: move(v)) { }

        base_ptr as_base () {
            return static_cast<base_ptr>(&* value);
        }

        node_ptr self() {
            return static_cast<node_ptr>(&* this);
        }
    };

    // list 的迭代器设计
    template <class T>
    struct list_iterator : public MySTL::iterator<MySTL::bidirectional_iterator_tag, T> {
        typedef T                                       value_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef typename node_traits<T>::base_ptr       base_ptr;
        typedef typename node_traits<T>::node_ptr       node_ptr;
        typedef list_iterator<T>                        self;

        base_ptr node_; // 指向当前节点

        // 构造函数
        list_iterator() = default;
        list_iterator (base_ptr x)
                      : node_(x) {}
        list_iterator (node_ptr x) 
                      : node_(x->as_base()) {}
        list_iterator (const list_iterator rhs) 
                      : node_(rhs.node_) {}


        // 重载操作符
        reference operator*  () const {return node_->as_node()->value;}
        pointer   operator-> () const {return &(operator());}

        self& operator++ () {
            MYSTL_DEBUG(node_ != nullptr);
            node_ = node_->next;
            return *this;
        }

        self operator++ (int) {
            self tmp = *this;
            ++ *this;
            return tmp;
        }

        self& operator-- () {

            MYSTL_DEBUG(node_ != nullptr);
            node_ = node_->prev;
            return *this;
        }

        self operator-- (int) {

            self tmp = *this;
            -- *this;
            return tmp;
        }

        // 重载比较操作符
        bool operator == (const self& rhs) const {return node_ == rhs.node_; }
        bool operator != (const self& rhs) const {return node_ != rhs.node_; }
    };

    // 模板类:list
    // 模板参数T代表数据类型

    template <class T>
    class list {

        public:

        // list 的嵌套型别定义
        typedef MySTL::allocator<T>                                 allocator_type;
        typedef MySTL::allocator<T>                                 data_allocator;
        typedef MySTL::allocator<list_node_base<T>>                 base_allocator;
        typedef MySTL::allocator<list_node<T>>                      node_allocator;

        typedef typename allocator_type::value_type                 value_type;
        typedef typename allocator_type::pointer                    pointer;
        typedef typename allocator_type::const_pointer              const_pointer;
        typedef typename allocator_type::reference                  reference;
        typedef typename allocator_type::const_reference            const_reference;
        typedef typename allocator_type::size_type                  size_type;
        typedef typename allocator_type::difference_type            difference_type;

        typedef list_iterator<T>                                    iterator;
        typedef list_const_iterator<T>                              const_iterator;
        typedef MySTL::reverse_iterator<iterator>                   reverse_iterator;
        typedef MySTL::reverse_iterator<const_iterator>             const_reverse_iterator;

        typedef typename node_traits<T>::base_ptr                   base_ptr;
        typedef typename node_traits<T>::node_ptr                   node_ptr;

        allocator_type get_allocator() {return node_allocator(); }

        private:

        base_ptr  node_; // 指向末节点
        size_type size_; // 大小

        public:
        // 构造，复制，移动，析构函数
        list() {
            fill_init(0, value_type());
        }

        explicit list(size_type n) {
            fill_init(n, value_type());
        }

        list(size_type n, const T& value) {
            fill_init(n, value);
        }

        template <class Iter, typename std::enable_if<
                MySTL:: is_input_iterator<Iter>::value, int>::type = 0>
        list(Iter first, Iter last) {
            copy_init(first, last);
        }

        list(std::initializer_list<T> ilist) {
            copy_init(ilist.begin(), ilist.end());
        }

        list(const list& rhs) {
            copy_init(rhs.cbegin(), rhs.cend());
        }

        list(list&& rhs) noexcept : node_(rhs.node_), size_(rhs.size_) {
            rhs.node_ = nullptr;
            rhs.size_ = 0;
        }

        list& operator= (const list& rhs) {
            if (this != &rhs) {
                assign(rhs.begin(), rhs.end);
            }

            return *this;
        }

        list& operator= (std::initializer_list<T> ilist) {

            list tmp(ilist.begin(), ilist.end());
            swap(tmp);
            return *this;
        }

        ~list() {
            if (node_) {
                clear();
                base_allocator::deallocate(node_);
                node_ = nullptr;
                size_ = 0;
            }
        }

        public:
        // 迭代器相关操作

        iterator
    };


    
}
#endif /* MYSTL_LIST_H_ */
#ifndef MYSTL_LIST_H_
#define MYSTL_LIST_H_

// 这是一个头文件包含list的模板类
// list:双向链表

namespace MySTL {

    // 声明了两个结构体变量。
    template <class T> struct list_node_base;
    template <class T> struct list_node;

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

        void unlink() {
            prev = next = self();
        } 

        base_ptr self() {
            return static_cast<base_ptr>(&*this);
        }

    };

    template <class T> 
    struct list_node : public list_node_base<T> {

        typedef typename node_traits<T>::base_ptr base_ptr;
        typedef typename node_traits<T>::node_ptr node_ptr;

        T value; // 数据域

        list_node() = default;

        list_node(const T& v) : value(v) { }
        list_node(T&& v) : value(MySTL :: move(v)) { }

        base_ptr as_base () {
            return static_cast<base_ptr>(&* value);
        }

        node_ptr self() {
            return static_cast<node_ptr>(&* this);
        }
    };
}
#endif /* MYSTL_LIST_H_ */
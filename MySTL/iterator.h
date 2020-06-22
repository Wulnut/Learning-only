#ifndef MYSTL_ITERATOR_H_
#define MYSTL_ITERATOR_H_

// 该头文件用于迭代器设计

#include <cstddef>
#include "type_traits.h"

namespace MySTL {

    // 五种迭代器类型
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_iterator_tag : public bidirectional_iterator_tag {};

    // iterator模板
    template <class Category, class T, class Distance = ptrdiff_t,
              class Pointer = T*, class Reference = T&>
              struct iterator {

                  typedef Category              iterator_category;
                  typedef T                     value_type;
                  typedef Pointer               pointer;
                  typedef Reference             reference;
                  typedef Distance              difference_type;
              };
    
    // iterator traits

    template <class T>
    struct has_iterator_cat {
        private:
            struct two {char a; char b;};
            template <class U> static two test(...); // test C++11 新特性测试单元
            template <class U> static char test(typename U::iterator_category* = 0);
        public:
            static const bool value = sizeof(test<T>(0)) == sizeof(char);

    };

    template <class Iterator, bool>
    struct iterator_traits_impl {};

    template <class Iterator>
    struct iterator_traits_impl<Iterator, true> {

        typedef typename Iterator::iterator_category    iterator_category;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::difference_type      defference_type;
    };

    template <class Iterator, bool>
    struct iterator_traits_helper {};

    template <class Iterator>
    struct iterator_traits_helper<Iterator, true>
           : public iterator_traits_impl<Iterator,
           std::is_convertible<typename Iterator::value_category, input_iterator_tag>::value ||
           std::is_convertible<typename Iterator::value_category, output_iterator_tag>::value>
    {

    };

    



} // namespace MySTL






#endif // MYSTL_ITERATOR_H_
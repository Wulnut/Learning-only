#ifndef MYSTL_CONSTRUCT_H_
#define MYSTL_CONSTRUCT_H_


// 这个头文件包含两个函数 construct， destory
// construct : 负责对象的构造
// destory   : 负责对象的析构

#include <new>
#include "type_traits.h"
#include "iterator.h"

#ifdef _MSC_VER
#pargma warning(push)
#pargma warning(disable:4100)
#endif

namespace MySTL {
    // construct 构造对象
    template <class Ty>
    void construct(Ty* ptr) {

        :: new ((void*) ptr) Ty();
    }

    template <class Ty1, class Ty2> 
    void construct(Ty* ptr, const Ty2& value) {

        :: new((void*) ptr) Ty1(value);
    }

    template <class Ty, class... Args>
    void construct(Ty* prt, Args&&... args) {

        :: new((void*) prt) Ty(MySTL::forward<Args>(args)...);
    }

    // destroy 析构对象

    template <class Ty>
    void destroy_one(Ty* , std::true_type) { }

    template <class Ty>
    void destroy_one(Ty* pointer, std::false_type) {

        if (pointer != nullptr) {

            pointer->~Ty();
        }
    }

    template <class ForwardIter>
    void destroy_one(ForwardIter, ForwardIter, std::true_type) { }

    template <class ForwardIter>
    void destroy_one(ForwardIter first, ForwardIter last, std::false_type) {

        for (; first != last; ++ first) {

            destroy(&*first);
        }
    }

    template <class Ty>
    void destroy(Ty* pointer) {

        destroy_one(pointer, std::is_trivially_destructible<Ty>{});
    }

    template <class ForwardIter>
    void destroy(ForwardIter first, ForwardIter last) {

        destroy_one(first, last, std::is_trivially_destructible<
                    typename iterator_traits<ForwardIter>::value_type>{});
    }

} // namespace MySTL

#ifdef _MSC_VER
#pargma warning(pop)
#endif

#endif
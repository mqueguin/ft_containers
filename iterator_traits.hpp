/*#pragma once

#include <cstddef>
#include <iterator>

namespace ft {

   template<typename Iterator>
    struct iterator_traits {
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
    };

    template<typename Tpointer>
    struct iterator_traits<Tpointer*> {
        typedef std::random_access_iterator_tag iterator_category;
        typedef Tpointer                        value_type;
        typedef std::ptrdiff_t                  difference_type;
        typedef Tpointer*                       pointer;
        typedef Tpointer&                       reference;
    };

    template<typename Tpointer>
    struct iterator_traits<const Tpointer*> {
        typedef std::random_access_iterator_tag iterator_category;
        typedef Tpointer value_type;
        typedef std::ptrdiff_t difference_type;
        typedef const Tpointer* pointer;
        typedef const Tpointer& reference;
    };

    template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
    struct iterator {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };
}*/
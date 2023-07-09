#ifndef UNINITIALIZED_H_
#define UNINITIALIZED_H_

#include "algorithm.h"
#include "construct.h"
#include "type_traits.h"

namespace fj {
// 函数的前向声明
// true_type 表示是POD
// false_type 表示是非POD
// fill是填充，构建数组的时候用

template <class ForwardIterator, class T>
void _uninitialized_fill_aux(ForwardIterator first, ForwardIterator last,
                             const T &value, true_type);

template <class ForwardIterator, class T>
void _uninitialized_fill_aux(ForwardIterator first, ForwardIterator last,
                             const T &value, false_type);

// 对外暴露的接口
template <class ForwardIterator, class T>
void uninitialized_fill(ForwardIterator first, ForwardIterator last,
                        const T &value) {
  typedef typename type_traits<T>::is_POD_type isPODType;
  _uninitialized_fill_aux(first, last, value, isPODType());
}

// 下面是两个_uninitialized_fill_aux的具体实现

// 是POD
template <class ForwardIterator, class T>
void _uninitialized_fill_aux(ForwardIterator first, ForwardIterator last,
                             const T &value, true_type) {
  fill(first, last, value);
}

// 不是POD
template <class ForwardIterator, class T>
void _uninitialized_fill_aux(ForwardIterator first, ForwardIterator last,
                             const T &value, false_type) {
  for (; first != last; ++first) {
    construct(first, value);
  }
}

/***************************************************************************/

// 前向声明
template <class ForwardIterator, class Size, class T>
ForwardIterator _uninitialized_fill_n_aux(ForwardIterator first, Size n,
                                          const T &x, true_type);

template <class ForwardIterator, class Size, class T>
ForwardIterator _uninitialized_fill_n_aux(ForwardIterator first, Size n,
                                          const T &x, false_type);

template <class ForwardIterator, class Size, class T>
inline ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n,
                                            const T &x) {
  typedef typename type_traits<T>::is_POD_type isPODType;
  return _uninitialized_fill_n_aux(first, n, x, isPODType());
}

//  具体实现
// POD
template <class ForwardIterator, class Size, class T>
ForwardIterator _uninitialized_fill_n_aux(ForwardIterator first, Size n,
                                          const T &x, true_type) {
  return fill_n(first, n, x);
}

// 非POD
template <class ForwardIterator, class Size, class T>
ForwardIterator _uninitialized_fill_n_aux(ForwardIterator first, Size n,
                                          const T &x, false_type) {
  int i = 0;
  for (; i != n; ++i) {
    construct(static_cast<T *>(first + i), x);
  }
  return (first + i);
}
} // namespace fj

#endif
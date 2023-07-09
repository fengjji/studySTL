#ifndef VECTOR_H_
#define VECTOR_H_

//#define STUDYVECTOR
// 测试学习期间
// 全部改用public

#include "alloactor.h"
#include "alloc.h"
#include "uninitialized.h"

namespace fj {

template <typename T, class Alloc = allocator<T>> 
class vector {
private:
  T *b_; // begin_
  T *f_; // finish_
  T *e_; // end
  using dataAllocator = Alloc;

public:
  // 改用using ,而不是typedef
  // 没有完全按照标准来定义，自学习用
  using type = T;
  using iterator = T *;
  using pointer = iterator;
  using const_iterator = const T *;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  //构造，复制，析构相关函数
  vector() : b_(0), f_(0), e_(0) {}

#ifdef STUDYVECTOR
  // 学习模板的一些知识
  // 模板的学习单独在vs2019上学了
  explicit vector(char c) {}
#else
#endif

  explicit vector(size_type n) { allocateAndFillN(n, type()); }

  vector(const size_type n, const type &value) { allocateAndFillN(n, value); }

  size_t size() const { return finish_ - start_; }
  size_t capacity() const { return endOfStorage_ - start_; }

  //修改容器相关的操作
  //清空容器，销毁容器中的所有对象并使容器的size为0，但不回收容器已有的空间
  // 基础类型 int int* 就不多说了
  // 自定义一个类 比如说 class Foo
  // fj::vector<Foo*>  v
  // 推断出 T==> Foo*
  // 是POD, 故执行空 destroy
  // 若 fj::vector<Foo>  执行 类Foo的析构
  void clear() {
    iterator tmp = b_;
    dataAllocator::destroy(b_, f_);
    f_ = b_;
  }

private:
  void allocateAndFillN(size_type n, const type &value) {
    b_ = dataAllocator::allocate(n); // 从内存池拿空间；
    uninitialized_fill_n(b_, n, value);
    f_ = e_ = b_ + n;
  }
};

} // namespace fj

#endif

#ifndef PAIR_H_
#define PAIR_H_

namespace fj {

template <typename T1, typename T2> struct pair {
  using first_type = T1;
  using second_type = T2;

  // 我们知道类中若有引用变量
  // 需要在构造函数的时候初始化的
  // 所以若参数是 & 就不对了
  first_type first;
  second_type second;

  // 这个写法参考了MSVC2019
  pair() : first(), second() {}

  pair(const first_type &a, const second_type &b) : first(a), second(b) {}

  //  const属性不建议使用 std::move
  pair(const pair &arg) : first(arg.first), second(arg.second) {}

  // 右值引用版
  // pair(pair&& arg):fisrt(std::move(arg.first)),second(std::move(arg,second))
  // noexcept {}

  bool operator==(const pair<first_type, second_type> &p) {
    // first和second都要相同才可以
    return first == p.first && second == p.second;
  }

  bool operator!=(const pair<first_type, second_type> &p) {
    //直接判断是否相等，取反就行
    return !(*this == p);
  }

}; // end pair

template <class T1, class T2> pair<T1, T2> make_pair(const T1 &a, const T2 &b) {
  return pair<T1, T2>(a, b);
}

}; // namespace  fj

#endif
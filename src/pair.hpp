#ifndef PAIR_H_
#define PAIR_H_

namespace fj {

template <typename T1, typename T2> struct pair {
  using first_type = T1;
  using second_type = T2;

  // 我们知道类中若有引用变量 （有时可能带有const修饰符）
  // 需要在构造函数的时候初始化的
  // 故视情况而定时候是否需要在<>里面写&
  // 结合目前对C++组件的使用情况看，貌似很少在<>里写&
  // 更多的就是单纯写一下类型名 （即class后面那窜字符仅此而已）

  first_type first;
  second_type second;

  // 这个写法参考了MSVC2019
  // boost也这种写法
  pair() : first(), second() {}

  pair(const first_type &a, const second_type &b) : first(a), second(b) {}

  //  const属性不建议使用 std::move
  pair(const pair &arg) : first(arg.first), second(arg.second) {}

  // 右值引用版
  //
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
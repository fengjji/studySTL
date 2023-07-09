#ifndef PAIR_H_
#define PAIR_H_

namespace fj {
template <typename T1, typename T2> 
struct pair {
  using first_type = T1;
  using second_type = T2;

  first_type fist;
  second_type second;

  pair() : fist(), second() {}

  pair(const first_type &a, const second_type &b) : first(a), second(b) {}
};

} // namespace  fj

#endif
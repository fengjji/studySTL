#ifndef ALGORITHM_H_
#define ALGORITHM_H_

//fill():用一给定值填充所有元素。
//fill_n():用一给定值填充前n个元素。
//ForwardIterator 正向迭代器

namespace fj {

// fill的实现
template<typename ForwardIterator, typename Value>
void fill(ForwardIterator first, ForwardIterator end,const Value& value) { // 迭代器是值拷贝
    for(;first!=end;++first) { // 前置++相较而言效率高
		    *first = value;   //  用给定值去初始化整个容器
    } 

}


// fill_n
// 有点想明白为啥要返回 OutputIterator
// 看到一些使用案例，对其返回值不关心
template<class OutputIterator, class Size, class T>
OutputIterator fill_n(OutputIterator first, Size n, const T& value) {
		for (; n > 0; --n, ++first) {
            *first = value;
        }
		return first;
}



} //endnamespace








#endif
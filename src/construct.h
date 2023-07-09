#ifndef CONSTRUCT_H_
#define CONSTRUCT_H_

#define STUDY

#include <new>
#include "type_traits.h"
//#include 


namespace fj{

	// 定位new
	// 依据传入的参数，去构造, 去掉相应的构造函数

	template<class T1, class T2>
	inline void construct(T1 *ptr1, const T2& value){
		new(ptr1) T1(value);
	}

	template<class T>
	inline void destroy(T *ptr){
		ptr->~T();
	}

 

   

	 template<class ForwardIterator>
	 inline void _destroy(ForwardIterator first, ForwardIterator last, true_type){}
     
	 template<class ForwardIterator>
	 inline void _destroy(ForwardIterator first, ForwardIterator last, false_type){
	 	for (; first != last; ++first){
	 		destroy(&*first);
	 	}
	 }


     template<class ForwardIterator>
	inline void destroy(ForwardIterator first, ForwardIterator last){
		typedef typename type_traits<ForwardIterator>::is_POD_type is_POD_type;
		_destroy(first, last, is_POD_type());
	}

	

}





#endif
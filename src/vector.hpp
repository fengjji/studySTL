#ifndef VECTOR_H_
#define VECTOR_H_

//#define STUDYVECTOR
// 测试学习期间
// 全部改用public

#include "alloc.h"
#include "alloactor.h"
#include "uninitialized.h"



namespace fj {


template <typename T, class Alloc = allocator<T>>
class vector {
    private:
        T* b_; //begin_
		T* f_; //finish_
		T* e_; //end
        using dataAllocator = Alloc;

    public:
        // 改用using ,而不是typedef
        // 没有完全按照标准来定义，自学习用
        using type = T;
        using iterator = T*;
        using pointer = iterator;
        using const_iterator = const T*;
        using reference = T&;
        using const_reference = const T&;
        using size_type = size_t;
        


        //构造，复制，析构相关函数
		vector() :b_(0), f_(0), e_(0){}

        #ifdef STUDYVECTOR
        // 学习模板的一些知识
        // 模板的学习单独在vs2019上学了
        explicit vector(char c) {
        }
        #else
        #endif
			
		explicit vector(size_type n) {
            allocateAndFillN(n,type());
        }

 
	

		vector(const size_type n, const type& value) {
           allocateAndFillN(n,value); 
        }
		
   
    private:
        void allocateAndFillN(size_type n, const type& value) {
            b_ = dataAllocator::allocate(n); // 从内存池拿空间；
            uninitialized_fill_n(b_, n, value);
            f_ = e_ = b_ + n;
        }
      
        
        

};

}



#endif


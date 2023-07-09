<h1 align = "center"> Allocator </h1>

## Allocator
 * 直接先上源码，用源码说事
 * 很巧的设计思想，空间分配与构造函数的调用分离了
 * 调用定位new，需要显性调用析构函数释放内存。
```c++
// Alloc::allocate(...) 返回void*  
// 如果所需空间大于最大则启 malloc
// 不然则优先从内存池挖出合适的空间并返回首地址
// 故转换成目标指针
// deallocate(...) 底层 free

template<class T, class Alloc>
	class simple_alloc {
	public:
		static T *allocate(size_t n) 
		      { return 0 == n ? 0 : (T*) Alloc::allocate(n * sizeof(T));}

		static T *allocate(void)
		      { return (T*) Alloc::allocate( sizeof(T) );}

		static void deallocate(T *p, size_t n)
		      { if(0 != n) Alloc::deallocate(p, n * sizeof(T));}

		static void deallocate(T *p)
		      { Alloc::deallocate(p, sizeof (T));}
	};
```
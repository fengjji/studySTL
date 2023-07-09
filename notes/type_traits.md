<h1 aligin = "center"> type_traits </h1>

``` c++
class A {
public:
	A() { std::cout << ".."<<"\n";
	a = 100;
	}

	explicit A(int x) {
		std::cout << "...copy number" << "\n";
		a = x;
	}

	A(const A&) {
		std::cout << "...copy" << "\n";
	}
	~A() {
		std::cout << "...bye" << "\n";
	}
	int a = 0;
};
//////////////////////

struct true_type{};
struct false_type {};

template <typename T>
struct type_traits {
	using is_POD = false_type;
};

template <typename T>
struct type_traits<T*> { // 偏特化
	using is_POD = true_type;
};


template <>
struct type_traits<int> { // 全特化
	using is_POD = true_type;
};


void fun(true_type) {
	std::cout << "...1"<<"\n";
}

void fun(false_type) {
	std::cout << "...2"<<"\n";
}

template <typename T>
void funWrapper(T arg) {
	typedef typename type_traits<T>::is_POD isPODType;
	fun(isPODType());
}

//////////////////////////////////

A a;
funWrapper(a);   //  非POD
funWrapper(&a);  //  POD  
指针类型 (T*) 算POD 

```
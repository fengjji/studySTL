#ifndef TYPETRAITS_H_
#define TYPETRAITS_H_

// 学习用，故不完全实现

namespace fj {
    // 空结构体不占大小
    struct true_type{};
    struct false_type{};


    // 主模板类
    template <typename T>
    struct type_traits {
        using is_POD_type = false_type;
    };

    // 偏特化
    template<typename T>
	struct type_traits<T*>
	{
		typedef true_type		is_POD_type;
	};

    // 全特化
    template<>
    struct type_traits<int>
	{
		typedef true_type		is_POD_type;
	};


       // 全特化
    template<>
    struct type_traits<int*>
	{
		typedef true_type		is_POD_type;
	};


    
    
}


#endif 
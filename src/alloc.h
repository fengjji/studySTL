// SGI空间配置器的仿写
// 本次设计以简易的数组代替与模式二级空间配置器的实现

#ifndef ALLOC_H_
#define ALLOC_H_

#include <cstdlib>

namespace fj {
    class Alloc {
    public:
        enum {MAXSIZE = 4096}; //4K
        static char* begin_;
        static char* end_;
        static size_t  offset_;

    public:
    static char FreeSpace[MAXSIZE];
    static void *allocate(size_t bytes);
    static void deallocate(void *ptr, size_t bytes);

};
}



#endif //ALLOC_H_
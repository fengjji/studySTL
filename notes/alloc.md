<h1 align = "center"> Alloc </h1>

## Alloc
* 看了源码，其本质可以理解为内存池，当需要开辟空间时，优先从内存池里去取合适的空间。就是说比如：上层调用了开辟空间的函数，以前可能是走malloc，系统从堆里挖出一块合适的区域返回其首地址，现在优先从自定义的内存池去挖合适的空间给上层去用。
#include "alloc.h"

namespace fj {
char Alloc::FreeSpace[MAXSIZE] = {'\0'};
char *Alloc::begin_ = Alloc::FreeSpace;
char *Alloc::end_ = Alloc::FreeSpace + MAXSIZE;
size_t Alloc::offset_ = 0;

void *Alloc::allocate(size_t bytes) {
  if (bytes == 0 || bytes >= MAXSIZE)
    return 0;
  else {

    char *tmp = 0;

    if (begin_ + bytes > end_) {
      return 0;
    } else {
      tmp = begin_;
      begin_ += bytes;
      offset_ += bytes;
    }
    return static_cast<void *>(tmp);
  }
}

void Alloc::deallocate(void *ptr, size_t bytes) {
  offset_ -= bytes;
  begin_ -= bytes;
}

} // namespace fj

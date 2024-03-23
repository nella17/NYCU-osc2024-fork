#include "heap.hpp"

char* heap_cur = __heap_start;

void heap_reset() {
  heap_cur = __heap_start;
}

void* heap_malloc(int size) {
  if (!heap_free(size))
    return nullptr;
  void* tmp = heap_cur;
  heap_cur += size;
  return tmp;
}

bool heap_free(int size) {
  return heap_cur + size <= __heap_end;
}
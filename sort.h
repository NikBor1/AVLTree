#ifndef MERGE_SORT
#define MERGE_SORT

#include <iostream>
#include <cstdint>
template <typename T, typename S, typename W>
void Merge(const T* first_begin, const T* first_end, const S* second_begin, const S* second_end, W* out) {
  size_t first_len = first_end - first_begin;
  size_t second_len = second_end - second_begin;
  size_t first_ptr = 0;
  size_t second_ptr = 0;

  while (first_ptr < first_len && second_ptr < second_len) {
    if (!(second_begin[second_ptr] < first_begin[first_ptr])) {
      out[first_ptr + second_ptr] = first_begin[first_ptr];
      ++first_ptr;
    } else {
      out[first_ptr + second_ptr] = second_begin[second_ptr];
      ++second_ptr;
    }
  }

  while (first_ptr < first_len) {
    out[first_ptr + second_ptr] = first_begin[first_ptr];
    ++first_ptr;
  }

  while (second_ptr < second_len) {
    out[first_ptr + second_ptr] = second_begin[second_ptr];
    ++second_ptr;
  }
}

template <typename T>
void Sort(T* begin, T* end) {
  size_t len = end - begin;
  if (len > 1) {
    Sort(begin, begin + len / 2);
    Sort(begin + len / 2, begin + len);
    Merge(begin, begin + len / 2, begin + len / 2, begin + len, begin);
  }
}
#endif
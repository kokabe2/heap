// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef KOKABE2_HEAP_SRC_HEAP_H_
#define KOKABE2_HEAP_SRC_HEAP_H_

#define Delete(x) Del((void**) & x)

typedef struct {
  void* (*New)(int size);
  void (*Del)(void** memory);
  int (*Usage)(void);
  void (*SetUsageWarning)(int size, void (*func)(int usage));
} Heap;

extern const Heap heap;

#endif  // KOKABE2_HEAP_SRC_HEAP_H_

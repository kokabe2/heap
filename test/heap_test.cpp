// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "heap.h"
}

TEST(HeapTest, HowToUse) {
  char* c = (char*)heap.New(128);

  EXPECT_TRUE(c != NULL);

  heap.Delete(c);

  EXPECT_EQ(NULL, c);
}

TEST(HeapTest, Usage) {
  void* v1 = (char*)heap.New(25);
  void* v2 = (char*)heap.New(8);
  void* v3 = (char*)heap.New(17);

  EXPECT_GE(heap.Usage(), 50);  // Actual size is implementation-dependent.

  heap.Delete(v1);
  heap.Delete(v2);
  heap.Delete(v3);

  EXPECT_EQ(0, heap.Usage());
}

namespace {
bool is_over_limit;
int given_usage;
void WarningFunc(int usage) {
  is_over_limit = true;
  given_usage = usage;
}
}  // namespace
TEST(HeapTest, WarnWhenOverUsageLimit) {
  is_over_limit = false;
  given_usage = 0;

  heap.SetUsageWarning(128, WarningFunc);

  void* v1 = (char*)heap.New(1);
  EXPECT_FALSE(is_over_limit);
  void* v2 = (char*)heap.New(128);
  EXPECT_TRUE(is_over_limit);
  EXPECT_EQ(heap.Usage(), given_usage);

  heap.Delete(v1);
  heap.Delete(v2);
}

add_library(
  heap
  ""
)

target_sources(
  heap
  PRIVATE
    gnu/heap.c
)

target_include_directories(
  heap
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

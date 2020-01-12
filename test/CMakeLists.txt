add_executable(
  gtests
  ""
)

target_sources(
  gtests
  PRIVATE
    heap_test.cpp
)

target_link_libraries(
  gtests
  gtest_main
  heap
)

add_test(
  NAME
    heap_test
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/gtests
)

cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()


set (SRC_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/tree/le_traversal.cc) # your source files
add_executable(main ${SRC_FILES}) # build executable "sample"


target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tree/include) # include directory for header files

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

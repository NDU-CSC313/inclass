list(APPEND flags "-DEXAMPLE0")
list(APPEND flags4 "-DEXAMPLE4")
add_executable(avl main-avl.cpp avl.cpp "${PROJECT_SOURCE_DIR}/include/avl.h")
add_executable(bst main-bst.cpp "${PROJECT_SOURCE_DIR}/include/bst.h")

add_executable(heap0 main-heap.cpp "${PROJECT_SOURCE_DIR}/include/heap.h" "${PROJECT_SOURCE_DIR}/include/Test.h")
add_executable(heap4 main-heap.cpp "${PROJECT_SOURCE_DIR}/include/heap.h" "${PROJECT_SOURCE_DIR}/include/Test.h")


target_include_directories(avl PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(bst PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_include_directories(heap0 PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(heap4 PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_compile_options(heap0 PRIVATE ${flags})
target_compile_options(heap4 PRIVATE ${flags4})

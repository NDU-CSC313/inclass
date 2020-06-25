

add_executable(avl main-avl.cpp avl.cpp "${PROJECT_SOURCE_DIR}/include/avl.h")
add_executable(bst main-bst.cpp "${PROJECT_SOURCE_DIR}/include/bst.h")
target_include_directories(avl PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(bst PUBLIC "${PROJECT_SOURCE_DIR}/include")
#add_custom_target(heap_examples)

function(example number)
    add_executable(heap_example${number} main-heap.cpp)
    target_compile_definitions(heap_example${number} PRIVATE EXAMPLE${number})
#   add_dependencies(heap_examples heap_example${number})
    target_include_directories(heap_example${number} PUBLIC "${PROJECT_SOURCE_DIR}/include")
    target_compile_options(heap_example${number} PRIVATE "-DEXAMPLE${number}")
endfunction(example)

example(0)
example(1)
example(2)
example(3)
example(4)

function(map_example number)
    add_executable(map_example${number} main-map.cpp)
    target_compile_definitions(map_example${number} PRIVATE EXAMPLE${number})
#   add_dependencies(heap_examples heap_example${number})
    target_include_directories(map_example${number} PUBLIC "${PROJECT_SOURCE_DIR}/include")
    target_compile_options(map_example${number} PRIVATE "-DEXAMPLE${number}")
endfunction(map_example)

map_example(1)
map_example(2)
map_example(3)
map_example(4)


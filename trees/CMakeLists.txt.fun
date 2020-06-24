set(CMAKE_CXX_STANDARD 17)

# ------------------------------------------------------------------------------
# Recipe 01
# ------------------------------------------------------------------------------

#add_custom_target(heap_examples)

function(example number)
    add_executable(heap_example${number} main-heap.cpp)
    #target_compile_definitions(heap_example${number} PRIVATE EXAMPLE${number})
    #    add_dependencies(heap_examples heap_example${number})
    target_include_directories(heap_example${number} PUBLIC "${PROJECT_SOURCE_DIR}/include")
    target_compile_options(heap_example${number} PRIVATE "-DEXAMPLE${number}")
endfunction(example)

example(0)
example(1)
example(2)
example(3)
example(4)


add_executable(list list.cpp "${PROJECT_SOURCE_DIR}/include/list.h")
target_include_directories(list PUBLIC "${PROJECT_SOURCE_DIR}/include")



function(vec_example number)
    add_executable(vector_example${number} vector.cpp "${PROJECT_SOURCE_DIR}/include/vector.h")
    target_compile_definitions(vector_example${number} PUBLIC EXAMPLE${number})
#   add_dependencies(heap_examples heap_example${number})
    target_include_directories(vector_example${number} PUBLIC "${PROJECT_SOURCE_DIR}/include")
    target_compile_options(vector_example${number} PUBLIC "-DEXAMPLE${number}")
endfunction(vec_example)
vec_example(1)
vec_example(2)
vec_example(3)
vec_example(4)
vec_example(5)
vec_example(6)
vec_example(7)
vec_example(8)
vec_example(9)
vec_example(10)





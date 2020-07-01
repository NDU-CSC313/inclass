

add_executable(sort main-sort.cpp  "${PROJECT_SOURCE_DIR}/include/sort.hpp" 
	"${PROJECT_SOURCE_DIR}/include/std-sort.h")
target_include_directories(sort PUBLIC "${PROJECT_SOURCE_DIR}/include")
#add_custom_target(heap_examples)

function(example number)
    add_executable(heap_example${number} main-heap.cpp)
    target_compile_definitions(heap_example${number} PRIVATE EXAMPLE${number})
#   add_dependencies(heap_examples heap_example${number})
    target_include_directories(heap_example${number} PUBLIC "${PROJECT_SOURCE_DIR}/include")
    target_compile_options(heap_example${number} PRIVATE "-DEXAMPLE${number}")
endfunction(example)


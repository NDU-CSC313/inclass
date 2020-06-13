add_executable(vector vector.cpp "${PROJECT_SOURCE_DIR}/include/vector.h")
add_executable(list list.cpp "${PROJECT_SOURCE_DIR}/include/list.h")
target_include_directories(vector PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(list PUBLIC "${PROJECT_SOURCE_DIR}/include")

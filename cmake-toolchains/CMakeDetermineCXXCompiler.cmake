set(CMAKE_CXX_COMPILER_ENV_VAR "CXX")

if (CMAKE_CXX_COMPILER STREQUAL "raw-clang++")
    find_program(_CLANGXX_FULL_PATH clang++)
    set(CMAKE_CXX_COMPILER ${_CLANGXX_FULL_PATH})
    set(CMAKE_CXX_COMPILER_FRONTEND_VARIANT "No Frontend")
endif ()



configure_file(${CMAKE_CURRENT_LIST_DIR}/CMakeCXXCompiler.cmake.in
        ${CMAKE_PLATFORM_INFO_DIR}/CMakeCXXCompiler.cmake)

set(CLANG_NO_DRIVER "clang++ -cc1")
set(CMAKE_CXX_OUTPUT_EXTENSION .bc)
set(CLANG_COMPILE_OBJECT_RULE "${CLANG_NO_DRIVER} -triple arm-none-eabi -tune-cpu cortex-m3 -emit-llvm-bc <SOURCE> -o <OBJECT>")

set(CMAKE_CXX_COMPILE_OBJECT "${CLANG_COMPILE_OBJECT_RULE}")

set(CMAKE_CXX_COMPILER_FORCED TRUE)
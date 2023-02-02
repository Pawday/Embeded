set(CMAKE_C_COMPILER_ENV_VAR "CC")

if (CMAKE_C_COMPILER STREQUAL "raw-clang")
    find_program(_CLANG_FULL_PATH clang)
    set(CMAKE_C_COMPILER ${_CLANG_FULL_PATH})
    set(CMAKE_C_COMPILER_FRONTEND_VARIANT "No Frontend")
endif ()



configure_file(${CMAKE_CURRENT_LIST_DIR}/CMakeCCompiler.cmake.in
        ${CMAKE_PLATFORM_INFO_DIR}/CMakeCCompiler.cmake)

set(CLANG_NO_DRIVER "clang -cc1")

set(CLANG_COMPILE_OBJECT_RULE "${CLANG_NO_DRIVER} -triple arm-none-eabi -tune-cpu cortex-m3 -emit-llvm-bc <SOURCE> -o <OBJECT>")

set(CMAKE_C_COMPILE_OBJECT "${CLANG_COMPILE_OBJECT_RULE}")

set(CMAKE_C_COMPILER_FORCED TRUE)
message(STATUS "Selected Raw LLVM Toolchain")
message(STATUS "Toolchain location: " ${CMAKE_CURRENT_LIST_DIR})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
include(SetLLVMLinker)


set(CMAKE_SYSTEM_NAME None)

set(CMAKE_C_COMPILER raw-clang)
set(CMAKE_CXX_COMPILER raw-clang++)



set(CMAKE_TOOLCHAIN_FILE FALSE)
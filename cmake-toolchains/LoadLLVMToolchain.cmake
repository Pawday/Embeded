if (CMAKE_IS_INIT_CACHE_INVOCATION)
    message(STATUS "[LLVM_TOOLCHAIN] Initialising cmake cache")
else()
    message(STATUS "[LLVM_TOOLCHAIN] Repairing existing cache")
endif()

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_LINKER ld.lld)

set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)

# TODO[cmake]: Expose triple selection for toolchain frontend
# TODO[cmake]: Implement triple selection validation
set(CMAKE_C_COMPILE_OBJECT "<CMAKE_C_COMPILER> -cc1 -triple thumb-none-eabi -tune-cpu cortex-m3 <FLAGS> -emit-obj <DEFINES> <INCLUDES> -o <OBJECT> <SOURCE>")

include(${CMAKE_CURRENT_LIST_DIR}/SetLLVMLinker.cmake)


if (NOT CMAKE_IS_INIT_CACHE_INVOCATION)
    # On repairing cmake cache toolchain file already
    # injected loaded to the CmakeSystem file
    # and not required anymore
    # cmake complain about it via warning ("Manually-specified variable CMAKE_TOOLCHAIN_FILE were not used by the project:")
    # this unset disables this warning
    unset(CMAKE_TOOLCHAIN_FILE)
endif()
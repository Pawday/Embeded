set(CMAKE_IS_INIT_CACHE_INVOCATION TRUE)

#TODO[cmake]: pass -triple arm-none-eabi -tune-cpu cortex-m3 options to llvm toolchain loader

# On first run it disables double inclusion for this toolchain file
set(CMAKE_TOOLCHAIN_FILE FALSE)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_CUSTOM_CODE "include(${CMAKE_CURRENT_LIST_DIR}/LoadLLVMToolchain.cmake)")
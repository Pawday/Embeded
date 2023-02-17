set(LLD_ARM_LINKER_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/link-arm.ld)

# option "--lto-O0" is the key for allowing per symbol link manipulation
# without this option llvm linker just throw away "unused" symbols (for example: VectorTable)
# TODO[lto]: find some way to tell LTO "not optimize that symbol"

set(_LINK_EXE_LLD_RULE "ld.lld --script ${CMAKE_CURRENT_LIST_DIR}/link-arm.ld --lto-O0 -entry main <FLAGS> <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET>")

set(CMAKE_C_LINK_EXECUTABLE ${_LINK_EXE_LLD_RULE})
set(CMAKE_CXX_LINK_EXECUTABLE ${_LINK_EXE_LLD_RULE})
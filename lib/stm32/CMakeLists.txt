set(_STM32_PRIVATE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/private)
set(STM32_PUBLIC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/public)

add_library(STM32_VectorTable OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/src/VectorTable.c)


target_include_directories(STM32_VectorTable PRIVATE ${_STM32_PRIVATE_INCLUDE_DIR})
target_include_directories(STM32_VectorTable PUBLIC ${STM32_PUBLIC_INCLUDE_DIR})


# I feel it kinda bad for exposing stub VectorTable
# but while there is no proper runtime its the only way make examples work
# TODO: Allow user redefine runtime via VectorTable in future
add_library(STM32_VectorTableStub OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/src/VectorTableStubs.c)
target_include_directories(STM32_VectorTableStub PRIVATE ${_STM32_PRIVATE_INCLUDE_DIR})


add_library(STM32 ALIAS STM32_VectorTable)
add_library(STM32::BasicVectorTable ALIAS STM32_VectorTableStub)
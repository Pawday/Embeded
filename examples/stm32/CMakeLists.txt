add_executable(Blink_13 Blink_13.c)

# Blink_13 uses optimise able spinlock for delay
# it necessary for proper delay to disable optimisations
target_compile_options(Blink_13 PRIVATE "-O0")

target_link_libraries(Blink_13 PRIVATE STM32)
target_link_libraries(Blink_13 PRIVATE STM32::BasicVectorTable)

MakeFlashTarget(Blink_13)

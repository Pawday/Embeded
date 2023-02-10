cmake_minimum_required(VERSION 3.21)

project(Pwd_Embedded C)

function(MakeFlashTarget Target)

    get_property(TARGET_NAME TARGET ${Target} PROPERTY NAME)
    get_property(TARGET_BIN_DIR TARGET ${Target} PROPERTY BINARY_DIR)

    if (NOT ${TARGET_NAME}_MakeFirmware)
        MakeFirmwareTarget(${Target})
    endif()


    add_custom_target(
            ${Target}_FlashFirmware
            COMMAND st-flash write ${TARGET_NAME}.bin 0x08000000
            WORKING_DIRECTORY ${TARGET_BUILD_DIR}
            DEPENDS ${TARGET_NAME}_MakeFirmware
    )

endfunction()

function(MakeFirmwareTarget Target)

    get_property(TARGET_NAME TARGET ${Target} PROPERTY NAME)
    get_property(TARGET_BIN_DIR TARGET ${Target} PROPERTY BINARY_DIR)

    add_custom_target(
        ${TARGET_NAME}_MakeFirmware
        COMMAND llvm-objcopy -O binary ${TARGET_NAME} ${TARGET_NAME}.bin
        WORKING_DIRECTORY ${TARGET_BUILD_DIR}
        DEPENDS ${Target}
    )
endfunction()

add_library(Reset OBJECT Reset.c)

add_executable(Blink_13 Blink_13.c)
target_link_libraries(Blink_13 PRIVATE Reset)
MakeFlashTarget(Blink_13)
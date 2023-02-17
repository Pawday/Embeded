
#TODO[cmake,external_tools]: determine st-flash location and deal with case when there is no st-flash

function(MakeFlashTarget Target)

    get_property(TARGET_NAME TARGET ${Target} PROPERTY NAME)
    get_property(TARGET_BIN_DIR TARGET ${Target} PROPERTY BINARY_DIR)

    if (NOT ${TARGET_NAME}_MakeFirmware)
        MakeFirmwareTarget(${Target})
    endif()


    add_custom_target(
            ${Target}_FlashFirmware
            COMMAND st-flash --reset write ${TARGET_NAME}.bin 0x08000000
            WORKING_DIRECTORY ${TARGET_BUILD_DIR}
            DEPENDS ${TARGET_NAME}_MakeFirmware
            COMMENT "Flashing ${Target}"
            VERBATIM
    )

endfunction()

function(MakeFirmwareTarget Target)

    get_property(TARGET_NAME TARGET ${Target} PROPERTY NAME)
    get_property(TARGET_BIN_DIR TARGET ${Target} PROPERTY BINARY_DIR)

    add_custom_target(
            ${TARGET_NAME}_MakeFirmware
            COMMAND llvm-objcopy -O binary ${TARGET_NAME} ${TARGET_NAME}.bin
            WORKING_DIRECTORY ${TARGET_BUILD_DIR}
            COMMENT "Making binary firmware for ${Target}"
            DEPENDS ${Target}
            BYPRODUCTS ${TARGET_NAME}.bin
            VERBATIM
    )
endfunction()


add_subdirectory(stm32)
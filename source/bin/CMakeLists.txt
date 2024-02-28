add_executable(blubber $<TARGET_OBJECTS:bubble::arch> blubber.c)
target_compile_features(blubber PRIVATE c_std_23)
target_compile_options(blubber PRIVATE
    -fno-exceptions
    -fno-unwind-tables
    -fno-asynchronous-unwind-tables
    )
target_link_options(blubber PRIVATE
    -nostdlib
    -nostartfiles
    -ffreestanding
    $<$<CONFIG:RELEASE>:-s>
    )
target_link_libraries(blubber PRIVATE blubber::common)

if(BLUBBER_OPT_ENABLE_ASAN)
    target_compile_options(bubble PRIVATE -fsanitize=address -fsanitize=undefined)
    target_link_options(bubble PRIVATE -fsanitize=address -fsanitize=undefined)
endif()

if(BLUBBER_OPT_ENABLE_TSAN)
    target_compile_options(bubble PRIVATE -fsanitize=thread)
    target_link_options(bubble PRIVATE -fsanitize=thread)
endif()

if(BLUBBER_OPT_ENABLE_LTO)
    set_property(TARGET bubble PROPERTY INTERPROCEDURAL_OPTIMIZATION ON)
endif()

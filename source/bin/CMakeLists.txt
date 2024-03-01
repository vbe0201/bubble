add_executable(bubble $<TARGET_OBJECTS:bubble::arch> bubble.c)
target_compile_features(bubble PRIVATE c_std_23)
target_compile_options(bubble PRIVATE
    -fno-exceptions
    -fno-unwind-tables
    -fno-asynchronous-unwind-tables
    )
target_link_options(bubble PRIVATE
    -nostdlib
    -nostartfiles
    -ffreestanding
    $<$<CONFIG:RELEASE>:-Wl,-nmagic>
    $<$<CONFIG:RELEASE>:-s>
    )
target_link_libraries(bubble PRIVATE bubble::common)

if(BUBBLE_OPT_ENABLE_ASAN)
    target_compile_options(bubble PRIVATE -fsanitize=address -fsanitize=undefined)
    target_link_options(bubble PRIVATE -fsanitize=address -fsanitize=undefined)
endif()

if(BUBBLE_OPT_ENABLE_TSAN)
    target_compile_options(bubble PRIVATE -fsanitize=thread)
    target_link_options(bubble PRIVATE -fsanitize=thread)
endif()

if(BUBBLE_OPT_ENABLE_LTO)
    set_property(TARGET bubble PROPERTY INTERPROCEDURAL_OPTIMIZATION ON)
endif()

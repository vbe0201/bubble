add_library(bubble_common STATIC
    impl/debug.h
    macros/arch.h
    macros/attr.h
    assert.h
    syscall.h
    types.h

    assert.c
    )
add_library(bubble::common ALIAS bubble_common)

target_include_directories(bubble_common PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )
target_compile_definitions(bubble_common PUBLIC
    $<$<CONFIG:Debug>:BUBBLE_ENABLE_DEBUG_ASSERTIONS>
    )
target_compile_features(bubble_common PRIVATE c_std_23)

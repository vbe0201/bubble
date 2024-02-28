add_library(blubber_common STATIC
    impl/debug.h
    macros/arch.h
    macros/attr.h
    assert.h

    assert.c
    )
add_library(blubber::common ALIAS blubber_common)

target_include_directories(blubber_common PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )
target_compile_definitions(blubber_common PUBLIC
    $<$<CONFIG:Debug>:BLUBBER_ENABLE_DEBUG_ASSERTIONS>
    )
target_compile_features(blubber_common PRIVATE c_std_23)

include(CheckSymbolExists)

# Checks if we're compiling for a specific architecture
# based on a given compiler symbol. This will help us
# include code for only the architecture we target.
function(check_target_architecture symbol arch)
    if(NOT DEFINED BUBBLE_ARCH)
        set(CMAKE_REQUIRED_QUIET 1)
        check_symbol_exists("${symbol}" "" BLUBBER_ARCH_${arch})
        unset(CMAKE_REQUIRED_QUIET)

        if(BLUBBER_ARCH_${arch})
            set(BLUBBER_ARCH "${arch}" PARENT_SCOPE)
        endif()
    endif()
endfunction()

check_target_architecture("__x86_64__" amd64)

add_library(blubber_arch OBJECT
    ${BLUBBER_ARCH}/start.S
    )
add_library(blubber::arch ALIAS blubber_arch)

# Set a default value, for systems without git.
set(BUBBLE_GIT_REV "unknown")

find_package(Git)
if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_BINARY} rev-parse --short HEAD
        OUTPUT_VARIABLE BUBBLE_GIT_REV
        ERROR_QUIET
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
endif()

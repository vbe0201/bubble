include_directories(.)

############################
## Compiler configuration ##
############################

if(NOT LINUX)
    message(FATAL_ERROR "blubber only supports Linux platforms")
endif()

add_compile_options(
    -Wall
    -Werror=array-bounds
    -Werror=missing-declarations
    -Werror=missing-field-initializers
    -Werror=sign-compare
    -Werror=switch
    -Werror=uninitialized
    -Werror=unused-function
    -Werror=unused-result
    -Werror=unused-variable
    -Wextra
    -Wmissing-declarations
    -Wno-attributes
    -Wno-unused-parameter
    -Wa,--noexecstack
    -static
    $<$<CONFIG:Release>:-fno-stack-protector>
    $<$<CONFIG:Release>:-ffunction-sections>
    $<$<CONFIG:Release>:-fdata-sections>
)

add_link_options(
    $<$<CONFIG:Release>:-Wl,--gc-sections>
)

if(LINUX OR MINGW)
    # GNU ar: Create thin archive files.
    # Requires binutils-2.19 or later.
    set(CMAKE_C_ARCHIVE_CREATE   "<CMAKE_AR> qcTP <TARGET> <LINK_FLAGS> <OBJECTS>")
    set(CMAKE_C_ARCHIVE_APPEND   "<CMAKE_AR> qTP  <TARGET> <LINK_FLAGS> <OBJECTS>")
    set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> qcTP <TARGET> <LINK_FLAGS> <OBJECTS>")
    set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> qTP  <TARGET> <LINK_FLAGS> <OBJECTS>")
endif()

#############
## Modules ##
#############

add_subdirectory(arch)
add_subdirectory(bin)
add_subdirectory(common)

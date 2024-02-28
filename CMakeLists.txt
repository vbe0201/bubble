cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

######################
## Project settings ##
######################

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

project(blubber
    DESCRIPTION "A web server written in C"
    VERSION "0.1.0"
    LANGUAGES C ASM
    )

include(GitRevision)
message(STATUS "Compiling blubber ${CMAKE_PROJECT_VERSION}, git revision ${BUBBLE_GIT_REV}")

#########################
## CMake configuration ##
#########################

# Enforce the C standard for the project.
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Nicely support folders inside IDEs.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Disallow in-source builds of the project.
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
        FATAL_ERROR
            "In-source builds are not allowed.\n"
            "Please create a new directory and run cmake from there."
    )
endif()

# Set the default build type, if not provided by the user.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the build type" FORCE)
endif()

# Define customization options for the build.
option(BLUBBER_OPT_ENABLE_ASAN "Enables the AddressSanitizer for blubber" OFF)
option(BLUBBER_OPT_ENABLE_TSAN "Enables the ThreadSanitizer for blubber" OFF)
option(BLUBBER_OPT_ENABLE_LTO "Builds blubber with LTO" OFF)

####################
## Subdirectories ##
####################

add_subdirectory(source)

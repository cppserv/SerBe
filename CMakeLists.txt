cmake_minimum_required (VERSION 2.8.11)
project (ServBe)
# The version number.
execute_process(
    COMMAND git describe --always --tags
    OUTPUT_VARIABLE serbe_VERSION)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# C_STANDARD
set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)

include_directories("include")
add_definitions(-O3 -g -pipe -flto -ffat-lto-objects) # -Wall -Wextra -Werror eliminado por problema con libressl

set(WARNINGFLAGS "-Wall -Wextra -Werror")

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -flto -O3 -g -pipe")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -flto -O3 -g -pipe")

#Function to make output a bit more quiet
function(message)
    if (NOT MESSAGE_QUIET)
        _message(${ARGN})
    endif()
endfunction()

#Function to remove imported executables
function(add_executable)
    if (NOT NO_COMPILE_EXECUTABLES)
        _add_executable(${ARGN})
    else()
        _add_executable(${ARGN})
        set_target_properties(${ARGV0} PROPERTIES EXCLUDE_FROM_ALL 1 EXCLUDE_FROM_DEFAULT_BUILD 1)
    endif()
endfunction()

#Function to remove custom targets
function(add_custom_target)
    if (NOT NO_ADD_CUSTOM)
        _add_custom_target(${ARGN})
    else()
    endif()
endfunction()

function(INSTALL)
    if (NOT NO_COMPILE_EXECUTABLES)
        _INSTALL(${ARGN})
    else()
    endif()
endfunction()

#Import all .hpp
file(GLOB serbe_INCLUDE
    "include/*.h"
    "include/*.hpp"
)

#Import all .cpp
file(GLOB serbe_SRC
    "src/*.c"
    "src/*.cpp"
)

include(Config.cmake)

# Dependencies

#HPTL
#set(NO_COMPILE_EXECUTABLES ON)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/hptimelib)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/hptimelib/include)
#add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/dependencies/hptimelib ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/hptimelib/build)
#unset(NO_COMPILE_EXECUTABLES)

#NETLIB
#set(NO_COMPILE_EXECUTABLES ON)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/netlib)
#add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/dependencies/netlib)
#unset(NO_COMPILE_EXECUTABLES)

#Tests
add_executable(serBe ${serbe_SRC} ${serbe_INCLUDE})

#Link library executables
target_link_libraries(serBe netlib hptl)

#Library wall messages
set_target_properties(serBe PROPERTIES COMPILE_FLAGS "${WARNINGFLAGS}")

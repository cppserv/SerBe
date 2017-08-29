
# The version number.
execute_process(
    COMMAND git describe --always --tags
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE serbe_VERSION)
string(REGEX REPLACE "\n$" "" serbe_VERSION "${serbe_VERSION}")

MESSAGE (STATUS "---------------------------------------------")
MESSAGE (STATUS "Building SERBE " ${serbe_VERSION})
MESSAGE (STATUS "---------------------------------------------")

# C_STANDARD
set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)

# OutputDirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# InputDirs
set(SERBE_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR}/..)
set(SERBE_INCLUDE_DIR ${SERBE_ROOT_DIR}/include)
set(SERBE_SRC_DIR ${SERBE_ROOT_DIR}/src)
set(SERBE_MK_DIR ${CMAKE_CURRENT_LIST_DIR})

# InputDirs
set(SERBE_LIRBRARIES magic)

# Default flags
add_definitions(-O3 -g -pipe -flto -ffat-lto-objects) # -Wall -Wextra -Werror eliminado por problema con libressl

set(WARNINGFLAGS "-Wall -Wextra -Werror")

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -flto -O3 -g -pipe")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -flto -O3 -g -pipe")

# Include headers
include_directories("${SERBE_INCLUDE_DIR}")
file(GLOB serbe_INCLUDE
    "${SERBE_INCLUDE_DIR}/*.h"
    "${SERBE_INCLUDE_DIR}/*.hpp"
)

# Include source files
file(GLOB_RECURSE serbe_SRC
    "${SERBE_SRC_DIR}/*.c"
    "${SERBE_SRC_DIR}/*.cpp"
)

function(serbe_common_fun)
    include(${SERBE_MK_DIR}/dependencies.cmake)
endfunction(serbe_common_fun)

# Sites
include(${SERBE_MK_DIR}/sites.cmake)
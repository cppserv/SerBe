# Dependencies Directory
set(SERBE_DEPENDENCY_DIR ${SERBE_ROOT_DIR}/dependencies)

# Sets up some interesting functions

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
set(NO_REDEFINEFUNTIONS ON)

# Include all the dependencies under ROOT/dependencies
unset(files CACHE)
file(GLOB files "${SERBE_DEPENDENCY_DIR}/*.cmake")
foreach(file ${files})
    MESSAGE( STATUS "Including dependency: " ${file})
    include(${file})
endforeach()
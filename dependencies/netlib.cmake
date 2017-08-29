#NETLIB
set(NO_COMPILE_EXECUTABLES ON)
include_directories(${SERBE_DEPENDENCY_DIR}/netlib/include)
add_subdirectory (${SERBE_DEPENDENCY_DIR}/netlib)
unset(NO_COMPILE_EXECUTABLES)

# add it to link
set(SERBE_LIRBRARIES ${SERBE_LIRBRARIES} netlib)
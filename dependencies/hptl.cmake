# HPTL
set(NO_COMPILE_EXECUTABLES ON)
include_directories(${SERBE_DEPENDENCY_DIR}/hptimelib/include)
add_subdirectory (${SERBE_DEPENDENCY_DIR}/hptimelib ${SERBE_DEPENDENCY_DIR}/hptimelib/build)
unset(NO_COMPILE_EXECUTABLES)

# add it to link
set(SERBE_LIRBRARIES ${SERBE_LIRBRARIES} hptl)
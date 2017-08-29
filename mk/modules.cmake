# Dependencies Directory
set(SERBE_MODULE_DIR ${SERBE_ROOT_DIR}/modules)
set(SERBE_MODULE_MKDIR ${SERBE_MK_DIR}/modules)

unset(files CACHE)
file(GLOB files "${SERBE_MODULE_MKDIR}/*.cmake")
foreach(file ${files})
    MESSAGE( STATUS "Including module: " ${file})
    include(${file})
endforeach()
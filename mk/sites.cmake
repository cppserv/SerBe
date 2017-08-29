function(serbe_sitecreate CONFIGFILE ROOTPATH)
    # Include config file
    include(${CONFIGFILE})

    # Call common routines
    serbe_common_fun()

    # Add the executable
    add_executable(serBe ${serbe_SRC} ${serbe_INCLUDE})

    #Link library executables
    target_link_libraries(serBe netlib hptl)
    target_link_libraries(serBe ${SERBE_LIRBRARIES}) 

    #Library wall messages
    set_target_properties(serBe PROPERTIES COMPILE_FLAGS "${WARNINGFLAGS}")
endfunction(serbe_sitecreate)
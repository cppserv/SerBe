################################
# SERBE CONFIG
#################################

option(SERBE_DEBUG "Enable SERBE debug text" ON)


#################################
# CONFIG FILES
#################################
#Config file
configure_file (
  "${PROJECT_SOURCE_DIR}/include/serbe_config.hpp.in"
  "${PROJECT_BINARY_DIR}/include/serbe_config.hpp"
  )
#configure_file (
#  "${PROJECT_SOURCE_DIR}/include/serbe_config.h.in"
#  "${PROJECT_SOURCE_DIR}/include/serbe_config.h"
#  )



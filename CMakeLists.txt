cmake_minimum_required (VERSION 3.2.2)
project (ServBe-StaticHtml)

# Import the common Cmake
include("mk/common.cmake")

# Create a plain-html server
serbe_sitecreate(example.org.config.cmake "SERBE_ROOT_DIR/websites/example.org")

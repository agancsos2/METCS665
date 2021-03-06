###############################################################################
## Name        : CMakeLists                                                   #
## Author      : Abel Gancsos                                                 #
## Version     : v. 1.0.0                                                     #
## Description : Build configuration file                                     #
## Based on Example: https://bit.ly/2lNz6gb                                   #
###############################################################################

cmake_minimum_required(VERSION 3.11) ## Version of cmake needed
project(Example)    ## Root folder/project name

###############################################################################
#                          Glob files in source                               #
###############################################################################
file(GLOB_RECURSE sources main.cpp com/*.cpp com/*.h)
## file(GLOB_RECURSE sources_test test/*.cpp) ## Unit Testing
file(GLOB_RECURSE data resources/*)
###############################################################################

add_executable(example ${sources} ${data})

###############################################################################
#                         Compiler options                                    #
###############################################################################
target_compile_options(example PUBLIC -std=c++11)

###############################################################################
#                        Set project includes                                 #
###############################################################################
target_include_directories(example PUBLIC src)

###############################################################################
#                        Package resources                                    #
###############################################################################
file(COPY ${data} DESTINATION resources)

###############################################################################
#                         Package project                                     #
###############################################################################
install(TARGETS example DESTINATION bin)
install(DIRECTORY resources DESTINATION bin)

###############################################################################
#                         Package information                                 #
############################################################################### 
set(CPACK_PACKAGE_NAME "Example")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_MONOLITHIC_INSTALL 1)
include(CPack)

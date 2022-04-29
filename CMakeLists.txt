cmake_minimum_required( VERSION 3.0 )
project( hw5 )

list( APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake )

enable_language( CXX )
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_BUILD_TYPE Debug )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wredundant-decls -Wcast-align -Wshadow" )

enable_testing()

set( hw5_INCDIR "${CMAKE_CURRENT_SOURCE_DIR}/.." )
include_directories( "external" )

#/////////////////////////// star information of google test ///////////////////////////////
set(GOOGLETEST_ROOT external/googletest CACHE STRING "Google Test source root")
include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )
set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )
foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()
add_library(googletest STATIC ${GOOGLETEST_SOURCES})
target_link_libraries(googletest pthread)
#///////////////////////////// end information of google test //////////////////////////////

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(hw5_SOURCES
  file_system.hpp
  file_system.cpp
  )

add_library( hw5 STATIC ${hw5_SOURCES} )

add_subdirectory( tests )




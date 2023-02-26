cmake_minimum_required( VERSION 3.12 )
project( caller )

set( CMAKE_CXX_STANDARD 20 )

find_package(Python3 COMPONENTS Interpreter)
if (NOT ${Python3_FOUND})
    message(FATAL_ERROR "Python is needed to generate sources.")
endif ()

set( MAXARGS 250 )

set( EXTRA_OPTS "-ftemplate-depth=1000" )
if ( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )
    set( EXTRA_OPTS ${EXTRA_OPTS} "-fbracket-depth=1000" )
endif()


include( Codegen.cmake )
codegen( switch.mako.cpp ${CMAKE_BINARY_DIR}/switch.cpp 250 )

add_library( functions SHARED functions.cpp )

set( SOURCES main.cpp caller_fred.cpp caller_fred2.cpp caller_trivial.cpp caller_caleth.cpp
             ${CMAKE_BINARY_DIR}/switch.cpp )

add_executable( caller_caleth main.cpp caller_caleth.cpp )
target_compile_definitions( caller_caleth PRIVATE MAXARGS=${MAXARGS} RUN_CALETH )
target_compile_options(caller_caleth PRIVATE ${EXTRA_OPTS} )
target_link_libraries( caller_caleth functions )

add_executable( caller_trivial main.cpp caller_trivial.cpp ${CMAKE_BINARY_DIR}/switch.cpp )
target_compile_definitions( caller_trivial PRIVATE MAXARGS=${MAXARGS} RUN_TRIVIAL )
target_compile_options(caller_trivial PRIVATE ${EXTRA_OPTS})
target_link_libraries( caller_trivial functions )

add_executable( caller_fred main.cpp caller_fred.cpp )
target_compile_definitions( caller_fred PRIVATE MAXARGS=${MAXARGS} RUN_FRED )
target_compile_options(caller_fred PRIVATE ${EXTRA_OPTS})
target_link_libraries( caller_fred functions )

add_executable( caller_fred2 main.cpp caller_fred2.cpp )
target_compile_definitions( caller_fred2 PRIVATE MAXARGS=${MAXARGS} RUN_FRED2  )
target_compile_options(caller_fred2 PRIVATE ${EXTRA_OPTS})
target_link_libraries( caller_fred2 functions )


add_executable( caller10  ${SOURCES} )
target_compile_definitions( caller10 PRIVATE MAXARGS=10 RUN_ALL )
target_compile_options(caller10 PRIVATE ${EXTRA_OPTS})
target_link_libraries( caller10 functions )

add_executable( caller250  ${SOURCES} )
target_compile_definitions( caller250 PRIVATE MAXARGS=250 RUN_ALL )
target_compile_options(caller250 PRIVATE ${EXTRA_OPTS})
target_link_libraries( caller250 functions )


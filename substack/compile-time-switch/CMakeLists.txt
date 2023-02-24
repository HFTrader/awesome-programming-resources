cmake_minimum_required( VERSION 3.12 )
project( caller )

set( CMAKE_CXX_STANDARD 20 )
add_library( functions SHARED functions.cpp )

set( MAXARGS 500 )
set( SOURCES main.cpp caller_fred.cpp caller_fred2.cpp caller_trivial.cpp caller_caleth.cpp )

add_executable( caller_caleth main.cpp caller_caleth.cpp )
target_compile_definitions( caller_caleth PRIVATE MAXARGS=${MAXARGS} RUN_CALETH )
target_compile_options(caller_caleth PRIVATE -ftemplate-depth=1000 -fbracket-depth=1000 )
target_link_libraries( caller_caleth functions )

add_executable( caller_trivial main.cpp caller_trivial.cpp )
target_compile_definitions( caller_trivial PRIVATE MAXARGS=${MAXARGS} RUN_TRIVIAL )
target_compile_options(caller_trivial PRIVATE -ftemplate-depth=1000 -fbracket-depth=1000)
target_link_libraries( caller_trivial functions )

add_executable( caller_fred main.cpp caller_fred.cpp )
target_compile_definitions( caller_fred PRIVATE MAXARGS=${MAXARGS} RUN_FRED )
target_compile_options(caller_fred PRIVATE -ftemplate-depth=1000 -fbracket-depth=1000)
target_link_libraries( caller_fred functions )

add_executable( caller_fred2 main.cpp caller_fred2.cpp )
target_compile_definitions( caller_fred2 PRIVATE MAXARGS=${MAXARGS} RUN_FRED2  )
target_compile_options(caller_fred2 PRIVATE -ftemplate-depth=1000 -fbracket-depth=1000)
target_link_libraries( caller_fred2 functions )


add_executable( caller10  ${SOURCES} )
target_compile_definitions( caller10 PRIVATE MAXARGS=10 RUN_ALL )
target_compile_options(caller10 PRIVATE -ftemplate-depth=1000 -fbracket-depth=1000)
target_link_libraries( caller10 functions )

add_executable( caller250  ${SOURCES} )
target_compile_definitions( caller250 PRIVATE MAXARGS=250 RUN_ALL )
target_compile_options(caller250 PRIVATE -ftemplate-depth=1000 -fbracket-depth=1000)
target_link_libraries( caller250 functions )

add_executable( caller500  ${SOURCES} )
target_compile_definitions( caller500 PRIVATE MAXARGS=500 RUN_ALL )
target_compile_options(caller500 PRIVATE -ftemplate-depth=1000 -fbracket-depth=1000)
target_link_libraries( caller500 functions )

cmake_minimum_required( VERSION 3.0 )
project( cache )

set( CMAKE_CXX_STANDARD 20 )

add_executable( testcopy testcopy.cpp )


include( FetchContent )
set( TINYPERF_BUILD_TESTS OFF CACHE INTERNAL "")
FetchContent_Declare( tinyperf GIT_REPOSITORY https://github.com/HFTrader/tiny-cpp-perf-stats.git )
FetchContent_Declare( benchmark GIT_REPOSITORY https://github.com/google/benchmark.git GIT_TAG main )
FetchContent_MakeAvailable( tinyperf benchmark )

find_package( Boost REQUIRED COMPONENTS thread )

#find_package( benchmark REQUIRED )

add_executable( testTrash testTrash.cpp )
target_link_libraries( testTrash pthread benchmark::benchmark Boost::thread tinyperfstats )

add_executable( testCycles testCycles.cpp )
target_link_libraries( testCycles  benchmark::benchmark)
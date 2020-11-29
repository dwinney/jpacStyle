cmake_minimum_required (VERSION 2.9)

project (jpacStyle)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_FLAGS "-fPIC -O3") 
set(CMAKE_BUILD_TYPE "Release")

# INSTALLATION SETTINGS
set( LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin )

# Make sure we can find ROOT 
execute_process(COMMAND root-config --prefix 
                COMMAND tr -d \\n
                RESULT_VARIABLE RC_RESULT 
                OUTPUT_VARIABLE ROOT_PREFIX)
list(APPEND CMAKE_MODULE_PATH "${ROOT_PREFIX}/share/root/cmake")

# Find ROOT
find_package(ROOT REQUIRED MathMore)
if (ROOT_FOUND)
    message("-- ROOT found! (${ROOT_USE_FILE})")
    #---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
    include(${ROOT_USE_FILE})
    list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS}) 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CXX_FLAGS}")
else()
    message(SEND_ERROR "-- Root not found!")
endif()

# BUILD LIBRARY FROM LOCAL FiLES
include_directories("include")
include_directories("src")
file(GLOB_RECURSE INC "include/*.hpp")
file(GLOB_RECURSE SRC "src/*.cpp")

add_library(jpacStyle SHARED ${INC} ${SRC} )

install(TARGETS jpacStyle
  LIBRARY DESTINATION "${LIBRARY_OUTPUT_DIRECTORY}" )

# GRAB EXECUTABLES
include_directories("examples")
file(GLOB_RECURSE EXE_FILES "examples/*.cpp")
foreach( exefile ${EXE_FILES} )
    get_filename_component( exename ${exefile} NAME_WE)
    add_executable( ${exename} ${exefile} )
    target_link_libraries( ${exename} jpacStyle)
    target_link_libraries( ${exename} ${ROOT_LIBRARIES})
endforeach( exefile ${EXE_FILES} )

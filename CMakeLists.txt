cmake_minimum_required (VERSION 2.9)

project (JpacStyle)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Look for and connect ROOT and Boost
find_package(ROOT REQUIRED MathMore)
if (ROOT_FOUND)
    include_directories(${ROOT_INCLUDE_DIRS})
    link_directories(${ROOT_LIBRARY_DIRS})
else()
    message(SEND_ERROR "Root not found!")
endif()

# BUILD LIBRARY FROM LOCAL FiLES
include_directories("cpp")
file(GLOB_RECURSE INC "cpp/*.hpp")
file(GLOB_RECURSE SRC "cpp/*.cpp")

add_library( libJpacStyle ${INC} ${SRC} )

# GRAB EXECUTABLES
include_directories("examples")
file(GLOB_RECURSE EXE_FILES "examples/*.cpp")
foreach( exefile ${EXE_FILES} )
    get_filename_component( exename ${exefile} NAME_WE)
    add_executable( ${exename} ${exefile} )
    target_link_libraries( ${exename} libJpacStyle)
    target_link_libraries( ${exename} ${ROOT_LIBRARIES})
    target_link_libraries( ${exename} ${BOOST_LIBRARIES})
endforeach( exefile ${EXE_FILES} )

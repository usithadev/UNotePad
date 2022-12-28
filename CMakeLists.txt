cmake_minimum_required(VERSION 3.1.0)

# set(CMAKE_BUILD_TYPE "Release")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

project(UNotePad VERSION 1.0.1)

find_package(wxWidgets REQUIRED core base stc)
include(UsewxWidgets)

set(SRC_FILES main.cpp main.h about.h about.cpp)
if(WIN32)
    set(SRC_FILES ${SRC_FILES} res.rc)
endif()

add_executable(UNotePad WIN32 MACOSX_BUNDLE ${SRC_FILES})

target_link_libraries(UNotePad ${wxWidgets_LIBRARIES})

#
# The doxygen documentation
#

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_PROJECT_NAME "UNotePad")
    set(DOXYGEN_PROJECT_NUMBER 1.0.1)
    set(DOXYGEN_PROJECT_BRIEF "A simple text editor application.")

    doxygen_add_docs(doxygen
        ${PROJECT_SOURCE_DIR}
        COMMENT "Generated html pages"
    )

    message("Found doxygen and generated the doxyfile")
else()
    message("Didn't find doxygen")
endif()
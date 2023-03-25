cmake_minimum_required(VERSION 3.10)
# Set project name and version
project(Tutorial VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
option(USE_MYMATH "Use tutorial provided math implementation" ON)
configure_file(TutorialConfig.h.in TutorialConfig.h)
if (USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions) # appends MathFunctions to EXTRA_LIBS
endif()
add_executable(target tutorial.cpp)
target_link_libraries(target PUBLIC ${EXTRA_LIBS})
target_include_directories(target PUBLIC #private means that this is only for this target
                          ${PROJECT_BINARY_DIR} #for TutorialConfig.h as it is built there.
                          )
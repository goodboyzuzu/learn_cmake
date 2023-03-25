cmake_minimum_required(VERSION 3.15)
# Set project name and version
project(Tutorial VERSION 1.0)
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_20)
# TODO 5: Create helper variables to determine which compiler we are using:
# * Create a new variable gcc_like_cxx that is true if we are using CXX and
#   any of the following compilers: ARMClang, AppleClang, Clang, GNU, LCC
# * Create a new variable msvc_cxx that is true if we are using CXX and MSVC
# Hint: Use set() and COMPILE_LANG_AND_ID
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
# wrap in build interface so consumer will not run
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
option(USE_MYMATH "Use tutorial provided math implementation" ON)
configure_file(TutorialConfig.h.in TutorialConfig.h)
if (USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions) # appends MathFunctions to EXTRA_LIBS
endif()
add_executable(target tutorial.cpp)
target_link_libraries(target PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)
target_include_directories(target PUBLIC #private means that this is only for this target
                          ${PROJECT_BINARY_DIR} #for TutorialConfig.h as it is built there.
                        )
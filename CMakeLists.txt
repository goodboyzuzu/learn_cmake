cmake_minimum_required(VERSION 3.15)
# Set project name and version
project(Tutorial VERSION 1.0)
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_20)
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
              
install(TARGETS target DESTINATION bin)
include(CTest)
add_test(NAME Runs COMMAND target 25)
add_test(NAME Usage COMMAND target)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
  )
add_test(NAME StandardUse COMMAND target 4)
set_tests_properties(StandardUse
  PROPERTIES PASS_REGULAR_EXPRESSION "4 is 2"
  )

# creates a function called do_test that takes 3 arguments
function(do_test target arg result)
add_test(NAME Comp${arg} COMMAND ${target} ${arg})
set_tests_properties(Comp${arg}
  PROPERTIES PASS_REGULAR_EXPRESSION ${result}
  )
endfunction()
do_test(target 4 "4 is 2")
do_test(target 9 "9 is 3")
do_test(target 5 "5 is 2.236")
do_test(target 7 "7 is 2.645")
do_test(target 25 "25 is 5")
do_test(target -25 "-25 is (-nan|nan|0)")
do_test(target 0.0001 "0.0001 is 0.01")
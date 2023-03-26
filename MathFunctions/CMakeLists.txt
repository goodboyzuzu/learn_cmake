add_library(MathFunctions mysqrt.cpp MathFunctions.cpp)

# interface as anybody linking to mathfunctions need to include current source dir. math function itself doesnt need to
target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MathFunctions tutorial_compiler_flags)

include(CheckCXXSourceCompiles)
check_cxx_source_compiles("
  #include <cmath>
  int main() {
    std::log(1.0);
    return 0;
  }
" HAVE_LOG)
check_cxx_source_compiles("
  #include <cmath>
  int main() {
    std::exp(1.0);
    return 0;
  }
" HAVE_EXP)
if(HAVE_LOG AND HAVE_EXP)
  message("---------------------------")
  message("Have log")
  message("---------------------------")
  target_compile_definitions(MathFunctions
                             PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()


# for math functions: libraries->lib and header-> include
# for tutorial exe: executable->bin and header->include
set(installable_libs MathFunctions tutorial_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
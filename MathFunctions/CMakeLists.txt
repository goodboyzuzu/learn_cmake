add_library(MathFunctions mysqrt.cpp MathFunctions.cpp)

# interface as anybody linking to mathfunctions need to include current source dir. math function itself doesnt need to
target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
message("It includes the mathfunction directory: ${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(MathFunctions tutorial_compiler_flags)
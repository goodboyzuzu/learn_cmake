add_library(MathFunctions mysqrt.cpp MathFunctions.cpp)

# interface as anybody linking to mathfunctions need to include current source dir. math function itself doesnt need to
target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
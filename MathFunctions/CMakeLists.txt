add_library(MathFunctions mysqrt.cpp MathFunctions.cpp)

# interface as anybody linking to mathfunctions need to include current source dir. math function itself doesnt need to
target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
message("It includes the mathfunction directory: ${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(MathFunctions tutorial_compiler_flags)
# for math functions: libraries->lib and header-> include
# for tutorial exe: executable->bin and header->include
set(installable_libs MathFunctions tutorial_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
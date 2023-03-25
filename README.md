At ./CMakeLists.txt: toggle USE_MYMATH, does not rebuild.

Solution:
builder.sh: remove files in build directory
runner: to run build cmake
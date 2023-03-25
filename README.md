**issue:**
At ./CMakeLists.txt: toggle USE_MYMATH, does not rebuild.
**Solution:**
builder.sh: remove files in build directory
runner: to run build cmake

### usage requirement for library
- let library define its own usage requirement, passed transitively to other targets

**issue:**
At ./CMakeLists.txt: toggle USE_MYMATH, does not rebuild.
**Solution:**
builder.sh: remove files in build directory
runner: to run build cmake

### usage requirement for library
- let library define its own usage requirement, passed transitively to other targets

### Generator expression
- evaluated during build generation. Provides info abt each build system

**What is an interface library**
STATIC libraries are archives of object files for use when linking other targets. 
SHARED libraries are linked dynamically and loaded at runtime.
MODULE libraries are plugins that are not linked into other targets but may be loaded dynamically at runtime using dlopen-like functionality.
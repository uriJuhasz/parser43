# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("parser43")

set(CMAKE_CXX_STANDARD 20)
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX /EHsc)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror -fcxx-exceptions)
endif()

# Include sub-projects.
add_subdirectory ("parser43")

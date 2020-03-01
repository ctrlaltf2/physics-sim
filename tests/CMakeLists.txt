cmake_minimum_required(VERSION 3.5.1)

project(vec3physical CXX)

add_executable(vec3physical Vec3Physical_test.cpp tests-main.cpp)

set_target_properties(vec3physical PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_include_directories(vec3physical
        PUBLIC
            ../src
)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set_target_properties(vec3physical PROPERTIES
        COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror"
    )
endif()

# Tell MSVC not to warn us about unchecked iterators in debug builds
if(${MSVC})
    set_target_properties(vec3physical PROPERTIES
        COMPILE_DEFINITIONS_DEBUG _SCL_SECURE_NO_WARNINGS)
endif()

add_custom_target(test_vec3physical ALL DEPENDS vec3physical COMMAND vec3physical)

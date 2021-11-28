cmake_minimum_required(VERSION 3.20)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
project(helloworld VERSION 0.0.${PATCH_VERSION})

set(CMAKE_CXX_STANDARD 17)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

configure_file(
        config.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

add_executable(helloworld main.cpp version.cpp version.h )
add_executable(ip_filtr ip_filter_dir/ip_filter.cpp ip_filter_dir/iPv4.cpp ip_filter_dir/iPv4.h ip_filter_dir/octate.cpp ip_filter_dir/octate.h ip_filter_dir/utils.h ip_filter_dir/util.cpp)

set_target_properties(
        helloworld ip_filtr PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        helloworld
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)

enable_testing()

add_executable(
        hello_test
        hello_test.cc version.cpp version.h
)
target_link_libraries(
        hello_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)

install(TARGETS helloworld ip_filtr RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

cmake_minimum_required(VERSION 3.16)

project(TerrainGen VERSION 0.1.0 LANGUAGES CXX)

# Generate compile_commands.json for clangd and other tooling.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Header-only terrain generation library.
add_library(TerrainGen INTERFACE)
add_library(TerrainGen::TerrainGen ALIAS TerrainGen)

target_include_directories(TerrainGen INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

target_compile_features(TerrainGen INTERFACE cxx_std_17)

# Test executables are kept separate from the header-only library.
include(CTest)

if(BUILD_TESTING)
    file(GLOB_RECURSE TERRAIN_GEN_TEST_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp"
    )

    if(TERRAIN_GEN_TEST_SOURCES)
        add_executable(TerrainGenTests ${TERRAIN_GEN_TEST_SOURCES})
        target_link_libraries(TerrainGenTests PRIVATE TerrainGen::TerrainGen)
        add_test(NAME TerrainGenTests COMMAND TerrainGenTests)
    else()
        message(STATUS "No test sources found in tests/; skipping TerrainGenTests")
    endif()
endif()

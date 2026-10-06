# Set minimum version of CMake
cmake_minimum_required(VERSION 3.20)

# Create a variable containing the program name
set(PROGRAM_NAME "RPG")

# Create PROGRAM_NAME as a project using C++
project(${PROGRAM_NAME} LANGUAGES CXX)

# With multiple source files we create libraries
# Libraries are reusable parts of code e.g. a Renderer
add_library(engine 
    src/game/character.cpp
    src/game/item.cpp
    src/game/inventory.cpp
    src/game/equipment.cpp
    src/game/item_database.cpp
    src/game/loot_table.cpp
)

# Create an executable called PROGRAM_NAME from Main.cpp
add_executable(${PROGRAM_NAME} src/main.cpp)

# When including files into our program the compiler needs to know where the headers are
# To do this we provide the program with access to our include folder and our dependencies include folder
target_include_directories(${PROGRAM_NAME} PRIVATE 
    "${CMAKE_SOURCE_DIR}/include"
)

target_include_directories(engine PRIVATE 
    "${CMAKE_SOURCE_DIR}/include"
)

# We must then link any libraries we have to the executable
# We do this by providing the library we created earlier
target_link_libraries(${PROGRAM_NAME} PRIVATE engine)

# Tell CMake to target C++20
target_compile_features(${PROGRAM_NAME} PRIVATE cxx_std_20)
target_compile_features(engine PRIVATE cxx_std_20)

# Tell CMake to place the executable in the build/bin folder no matter the build type
set_target_properties(${PROGRAM_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin"
)   

# Create a file with the CMake Binaries called build_info.txt containing the EXECUTABLE_LOCATION for future reference
file(WRITE "${CMAKE_BINARY_DIR}/build_info.txt" "EXECUTABLE_PATH=${CMAKE_BINARY_DIR}/bin/${PROGRAM_NAME}.exe\n")
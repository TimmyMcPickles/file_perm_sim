cmake_minimum_required(VERSION 3.10)
project(file_perm_sim)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compiler warnings for all platforms
if(MSVC)
  # Windows with Visual Studio
  add_compile_options(/W4)
else()
  # Linux and macOS with GCC/Clang
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Source files
set(SOURCES
    src/main.cpp
    src/item.cpp
    src/file.cpp
    src/directory.cpp
    src/user.cpp
    src/group.cpp
    src/userList.cpp
    src/groupList.cpp
)

# Header files
set(HEADERS
    src/item.hpp
    src/file.hpp
    src/directory.hpp
    src/user.hpp
    src/group.hpp
    src/userList.hpp
    src/groupList.hpp
)

# Create executable
add_executable(file_perm_sim ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(file_perm_sim PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

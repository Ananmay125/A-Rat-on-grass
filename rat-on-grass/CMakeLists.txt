# CMakeList.txt : CMake project for rat-on-grass, include source and define
# project specific logic here.

cmake_minimum_required(VERSION 3.20)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("rat-on-grass")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages with CMake configs
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# Header-only libraries (no CMake config)
find_path(STB_INCLUDE_DIR stb_image.h PATH_SUFFIXES stb)
find_path(TINYGLTF_INCLUDE_DIR tiny_gltf.h)

# Verify header-only libraries were found
if(NOT STB_INCLUDE_DIR)
    message(FATAL_ERROR "STB not found!")
endif()

if(NOT TINYGLTF_INCLUDE_DIR)
    message(FATAL_ERROR "TinyGLTF not found!")
endif()

# Add source to this project's executable
add_executable(${PROJECT_NAME} "src/Main.cpp")

# Include header-only libraries
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${STB_INCLUDE_DIR}
    ${TINYGLTF_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    OpenGL::GL
    glad::glad
    glm::glm
)
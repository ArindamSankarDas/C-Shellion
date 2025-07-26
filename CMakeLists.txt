cmake_minimum_required(VERSION 3.12)

set(CMAKE_C_STANDARD 23)
set(PROJECT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(C_Shellion LANGUAGES C)

file(GLOB SRC_FILES CONFIGURE_DEPENDS "${PROJECT_SRC_DIR}/src/*.c")

add_executable(app_exec ${SRC_FILES})

target_include_directories(app_exec PRIVATE "${PROJECT_SRC_DIR}/include")

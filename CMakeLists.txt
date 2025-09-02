cmake_minimum_required(VERSION 3.5)
project(gbc)
set(CMAKE_C_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CORE_SRC 
    src/memory.c
    src/cpu.c
    src/main.c
)


add_executable(gb ${CORE_SRC})

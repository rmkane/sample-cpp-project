cmake_minimum_required(VERSION 3.5.0)
project(LinkedListDriver VERSION 0.1.0)

set(SOURCES src/stuff.cc src/main.cc)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

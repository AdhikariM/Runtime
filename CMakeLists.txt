cmake_minimum_required(VERSION 3.5)

project(CS300PROJ2)

set(CMAKE_CXX_STANDARD 11)

# Add the executable
add_executable(${PROJECT_NAME} Main.cpp Course.cpp Courses.cpp)

# Include the header files
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add any additional libraries if necessary
target_link_libraries(${PROJECT_NAME} ${OTHER_LIBRARIES})

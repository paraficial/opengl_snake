project(opengl_snake)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${PROJECT_NAME} ${GLFW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARIES})

find_package(OpenGL REQUIRED)
include_directories(${PROJECT_NAME} ${OPENGL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})

find_package(GLEW REQUIRED)
include_directories(${PROJECT_NAME} ${GLEW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES})

set (opengl_snake
	game.h
	game.cpp
	canvas.h
	canvas.cpp
	shader.hpp
	shade.cpp
	)

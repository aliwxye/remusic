cmake_policy(SET CMP0048 NEW)
cmake_minimum_required(VERSION 3.28)
project(remusic VERSION 0.1.0 LANGUAGES CXX)

set(REMUSIC_SRC_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cc
)

add_subdirectory(lib/miniaudio)
add_subdirectory(lib/cargs)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${REMUSIC_SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE miniaudio cargs)
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

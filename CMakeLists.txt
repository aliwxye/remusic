cmake_policy(SET CMP0048 NEW)
cmake_minimum_required(VERSION 3.28)
project(remusic VERSION 0.1.0 LANGUAGES CXX)

set(SRC_FILES 
	${PROJECT_SOURCE_DIR}/src/main.cc
)

add_subdirectory(lib/miniaudio)
add_subdirectory(lib/cargs)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SRC_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)
target_link_libraries(${PROJECT_NAME} PRIVATE miniaudio cargs)

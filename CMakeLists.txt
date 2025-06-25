cmake_policy(SET CMP0048 NEW)
cmake_minimum_required(VERSION 3.28)
project(remusic VERSION 0.1.0 LANGUAGES CXX)

set(REMUSIC_SRC_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/remusic.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/Device.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cc
)

include(FetchContent)
FetchContent_Declare(
	miniaudio
	GIT_REPOSITORY https://github.com/mackron/miniaudio.git
	GIT_TAG 350784a9467a79d0fa65802132668e5afbcf3777
)
FetchContent_Declare(
	cargs
	GIT_REPOSITORY https://github.com/likle/cargs.git
	GIT_TAG 0fbac1a0c6ebb7ecd72f0d7ae89c2b79eb3a12eb
)

FetchContent_MakeAvailable(miniaudio cargs)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${REMUSIC_SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE miniaudio cargs)
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

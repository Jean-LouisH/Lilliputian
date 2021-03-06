﻿
cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE application_sources "[a-zA-Z]*.cpp")
file(GLOB_RECURSE application_headers "[a-zA-Z]*.hpp")

add_executable(application 
	  ${application_sources}
	  ${application_headers}
 )

add_dependencies(application
	lilliputian_engine
)

find_library(SDL2 SDL2.lib SDL2main.lib PATHS ../../thirdparty/SDL2-2.0.12/lib/x64)

include_directories(
		../../thirdparty/SDL2-2.0.12/include
		../../thirdparty/SDL2_image-2.0.5/include
		../../thirdparty/SDL2_mixer-2.0.4/include
		../../thirdparty/SDL2_ttf-2.0.15/include
		../../thirdparty/yaml-cpp-0.6.3/include
		../../thirdparty/glad/include
		../../thirdparty/python37/include
		../../thirdparty/pybind11-2.6.2/include
		../../thirdparty/glew-2.1.0/include
		../../thirdparty/glm-0.9.9.8/glm
		../../thirdparty/tinygltf-2.5.0/include
		../../thirdparty/zlib-1.2.11/include
		../engine
		.
)

target_link_libraries (application
		lilliputian_engine
		${SDL2}
)
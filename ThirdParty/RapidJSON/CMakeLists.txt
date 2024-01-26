cmake_minimum_required(VERSION 3.19)

add_library(RapidJSON INTERFACE)
target_include_directories(RapidJSON INTERFACE include/)
target_compile_definitions(RapidJSON INTERFACE RAPIDJSON_ASSERT_THROWS)
if(WIN32)
	target_compile_definitions(RapidJSON INTERFACE NOMINMAX)
endif()
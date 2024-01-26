option(BUILD_OBJECT_LIB "Build object library (not available in Xcode)" OFF)

add_subdirectory(ghc_filesystem)
add_subdirectory(nowide)

add_subdirectory(ZLib)
add_subdirectory(SSL)

add_subdirectory(cpp-httplib)
#add_subdirectory(mdns)
add_subdirectory(asio)
add_subdirectory(WebSocket)
#add_subdirectory(json)
add_subdirectory(RapidJSON)
add_subdirectory(json_dto)
add_subdirectory(spdlog)
add_subdirectory(MQTT)
add_subdirectory(JWT)
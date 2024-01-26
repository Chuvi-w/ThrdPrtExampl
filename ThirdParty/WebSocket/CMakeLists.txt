add_library(SimpleWSS INTERFACE)

target_include_directories(SimpleWSS INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/SimpleWSS)

find_package(Threads REQUIRED)
target_link_libraries(SimpleWSS INTERFACE Threads::Threads SSLLib asio_ssl)
target_compile_definitions(SimpleWSS INTERFACE ASIO_STANDALONE)

if(WIN32)
    target_link_libraries(SimpleWSS INTERFACE ws2_32 wsock32)
endif()


 add_executable(SimpleWS_examples SimpleWSS/ws_examples.cpp)
    target_link_libraries(SimpleWS_examples SimpleWSS)
    add_executable(SimpleWSS_examples SimpleWSS/wss_examples.cpp)
    target_link_libraries(SimpleWSS_examples SimpleWSS)
add_library(HttpLib STATIC httplib.cc httplib.h)
target_include_directories(HttpLib PUBLIC .)
if(WIN32)
  target_link_libraries(HttpLib ws2_32)
endif()

target_compile_definitions(HttpLib PUBLIC CPPHTTPLIB_ZLIB_SUPPORT CPPHTTPLIB_OPENSSL_SUPPORT )
target_link_libraries(HttpLib ZLib SSLLib)


add_library(CJwt STATIC 
JwtValue.cpp
JwtValue.h
CJwt.cpp
CJwt.h
)

target_include_directories(CJwt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(CJwt PUBLIC ErrnoException jwt)
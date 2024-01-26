add_library(ErrnoException STATIC 
ErrnoException.cpp
ErrnoException.h
)

target_include_directories(CJwt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(CJwt PUBLIC jwt)
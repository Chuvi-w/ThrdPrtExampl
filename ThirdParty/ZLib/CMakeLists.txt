

#============================================================================
# zlib
#============================================================================

set(ZLIB_PUBLIC_HDRS
    include/zlib/zconf.h
    include/zlib/zlib.h
)
set(ZLIB_PRIVATE_HDRS
    src/crc32.h
    src/deflate.h
    src/gzguts.h
    src/inffast.h
    src/inffixed.h
    src/inflate.h
    src/inftrees.h
    src/trees.h
    src/zutil.h
)

set(ZLIB_SRCS
    src/adler32.c
    src/compress.c
    src/crc32.c
    src/deflate.c
    src/gzclose.c
    src/gzlib.c
    src/gzread.c
    src/gzwrite.c
    src/inflate.c
    src/infback.c
    src/inftrees.c
    src/inffast.c
    src/trees.c
    src/uncompr.c
    src/zutil.c
)



file(READ ${CMAKE_CURRENT_SOURCE_DIR}/include/zlib/zlib.h _zlib_h_contents)
string(REGEX REPLACE ".*#define[ \t]+ZLIB_VERSION[ \t]+\"([-0-9A-Za-z.]+)\".*"
    "\\1" ZLIB_FULL_VERSION ${_zlib_h_contents})

add_library(ZLib STATIC ${ZLIB_SRCS} ${ZLIB_ASMS} ${ZLIB_PUBLIC_HDRS} ${ZLIB_PRIVATE_HDRS})
target_include_directories(ZLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ PUBLIC {CMAKE_CURRENT_SOURCE_DIR}/src/ ${CMAKE_CURRENT_SOURCE_DIR}/include/zlib)
target_compile_definitions(ZLib PUBLIC _LARGEFILE64_SOURCE)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(ZLib PRIVATE -Wno-deprecated-non-prototype)
endif()
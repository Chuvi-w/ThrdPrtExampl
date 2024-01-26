set(JWTROOT ${CMAKE_CURRENT_SOURCE_DIR}/libjwt)
set(JWTSRC ${JWTROOT}/libjwt)
set(JWTINC ${JWTROOT}/include)

add_library(jwt STATIC 
    ${JWTSRC}/base64.c
    ${JWTSRC}/base64.h
    ${JWTSRC}/jwt.c
    #${JWTSRC}/jwt-gnutls.c
    ${JWTSRC}/jwt-openssl.c
    ${JWTSRC}/jwt-private.h
    #${JWTSRC}/jwt-wincrypt.c
    ${JWTINC}/jwt.h
)

write_file(${CMAKE_CURRENT_BINARY_DIR}/config.h "")

target_include_directories(jwt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}  PRIVATE ${JWTINC} ${JANSSON_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(jwt PUBLIC jansson SSLLib)
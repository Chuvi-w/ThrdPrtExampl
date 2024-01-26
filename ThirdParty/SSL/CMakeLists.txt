
find_package(OpenSSL COMPONENTS Crypto SSL)
 add_library(SSLLib INTERFACE)
if(OpenSSL_FOUND)
    message(STATUS "Will use OpenSSL")
    target_link_libraries(SSLLib INTERFACE OpenSSL::SSL OpenSSL::Crypto)

else()

    message(STATUS "Will use LibreSSL")
    set(LIBRESSL_APPS TRUE)
    set(LIBRESSL_TESTS FALSE)
    #add_subdirectory(libressl)
	#target_link_libraries(SSLLib INTERFACE ssl crypto tls)


    add_subdirectory(libressl-3.5.3)
	target_link_libraries(SSLLib INTERFACE ssl_obj crypto_obj tls_obj bs_obj ssl crypto tls)
endif()


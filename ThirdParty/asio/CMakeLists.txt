


if(WIN32)
    function(parse_WIN32SysVer ver out)
        string(REGEX MATCH "^([0-9]+).([0-9])" ver ${ver})
        string(REGEX MATCH "^([0-9]+)" verMajor ${ver})
        # Check for Windows 10, b/c we'll need to convert to hex 'A'.
        if("${verMajor}" MATCHES "10")
            set(verMajor "A")
            string(REGEX REPLACE "^([0-9]+)" ${verMajor} ver ${ver})
        endif()
        # Remove all remaining '.' characters.
        string(REPLACE "." "" ver ${ver})
        # Prepend each digit with a zero.
        string(REGEX REPLACE "([0-9A-Z])" "0\\1" ver ${ver})
        set(${out} "0x${ver}" PARENT_SCOPE)
    endfunction()
    
    macro(get_WIN32_WINNT version)

        if(CMAKE_SYSTEM_VERSION)
            parse_WIN32SysVer(${CMAKE_SYSTEM_VERSION} ${version})
        elseif(CMAKE_HOST_SYSTEM_VERSION) #ToDo: Костыль для mingw, нужно как-то сделать цивильнее
            parse_WIN32SysVer(${CMAKE_HOST_SYSTEM_VERSION} ${version})
        endif()
    endmacro()
endif()


file(GLOB_RECURSE ASIO_HDRS asio/include/*.hpp)

#message(STATUS "ASIO_HDRS=${ASIO_HDRS}")

add_library(asio INTERFACE) #asio/src/asio.cpp )
target_sources(asio PUBLIC ${ASIO_HDRS})

target_include_directories(asio INTERFACE asio/include)
#target_compile_definitions(asio PUBLIC ASIO_SEPARATE_COMPILATION)

add_library(asio_ssl INTERFACE)# asio/src/asio_ssl.cpp ${ASIO_HDRS})

target_include_directories(asio_ssl INTERFACE asio/include)
#target_compile_definitions(asio_ssl PUBLIC ASIO_SEPARATE_COMPILATION)
target_link_libraries(asio_ssl INTERFACE SSLLib)

if(WIN32)
    get_WIN32_WINNT(NTVer)
    if(NOT NTVer)
        message(FATAL_ERROR "NTVer not set. Please fix somehow.")
    endif()
    target_compile_definitions(asio INTERFACE _WIN32_WINNT=${NTVer})
    target_compile_definitions(asio_ssl INTERFACE _WIN32_WINNT=${NTVer})
endif()

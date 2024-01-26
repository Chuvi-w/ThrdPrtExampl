



option(MQTT_C_OpenSSL_SUPPORT TRUE) #"Build MQTT-C with OpenSSL support?" OFF)
option(MQTT_C_MbedTLS_SUPPORT FALSE) #"Build MQTT-C with mbed TLS support?" OFF)
option(MQTT_C_BearSSL_SUPPORT FALSE) #"Build MQTT-C with Bear SSL support?" OFF)
option(MQTT_C_EXAMPLES TRUE) #"Build MQTT-C examples?" ON)
option(MQTT_C_INSTALL_EXAMPLES TRUE) #"Install MQTT-C examples?" OFF)
option(MQTT_C_TESTS TRUE) #"Build MQTT-C tests?" OFF)
add_subdirectory(MQTT-C)
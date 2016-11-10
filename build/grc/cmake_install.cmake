# Install script for directory: /home/zigbee/gr-tfg/grc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/grc/blocks" TYPE FILE FILES
    "/home/zigbee/gr-tfg/grc/tfg_imprimir_mensajes.xml"
    "/home/zigbee/gr-tfg/grc/tfg_repetidor_caracteres.xml"
    "/home/zigbee/gr-tfg/grc/tfg_mensaje_a_mayusculas.xml"
    "/home/zigbee/gr-tfg/grc/tfg_imprimir_bytes.xml"
    "/home/zigbee/gr-tfg/grc/tfg_test_nwk.xml"
    "/home/zigbee/gr-tfg/grc/tfg_test_aps.xml"
    "/home/zigbee/gr-tfg/grc/tfg_APS_stack.xml"
    "/home/zigbee/gr-tfg/grc/tfg_NWK_stack.xml"
    "/home/zigbee/gr-tfg/grc/tfg_translation_block.xml"
    "/home/zigbee/gr-tfg/grc/tfg_Aplication.xml"
    "/home/zigbee/gr-tfg/grc/tfg_mac.xml"
    "/home/zigbee/gr-tfg/grc/tfg_MAC_stack.xml"
    "/home/zigbee/gr-tfg/grc/tfg_test_mac.xml"
    "/home/zigbee/gr-tfg/grc/tfg_motecontrol.xml"
    )
endif()


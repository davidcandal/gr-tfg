# Install script for directory: /home/zigbee/gr-tfg/include/tfg

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/tfg" TYPE FILE FILES
    "/home/zigbee/gr-tfg/include/tfg/api.h"
    "/home/zigbee/gr-tfg/include/tfg/imprimir_mensajes.h"
    "/home/zigbee/gr-tfg/include/tfg/repetidor_caracteres.h"
    "/home/zigbee/gr-tfg/include/tfg/mensaje_a_mayusculas.h"
    "/home/zigbee/gr-tfg/include/tfg/imprimir_bytes.h"
    "/home/zigbee/gr-tfg/include/tfg/test_nwk.h"
    "/home/zigbee/gr-tfg/include/tfg/test_aps.h"
    "/home/zigbee/gr-tfg/include/tfg/APS_stack.h"
    "/home/zigbee/gr-tfg/include/tfg/NWK_stack.h"
    "/home/zigbee/gr-tfg/include/tfg/translation_block.h"
    "/home/zigbee/gr-tfg/include/tfg/Aplication.h"
    "/home/zigbee/gr-tfg/include/tfg/mac.h"
    "/home/zigbee/gr-tfg/include/tfg/MAC_stack.h"
    "/home/zigbee/gr-tfg/include/tfg/test_mac.h"
    "/home/zigbee/gr-tfg/include/tfg/motecontrol.h"
    )
endif()


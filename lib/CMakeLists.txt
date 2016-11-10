# Copyright 2011,2012,2016 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})
list(APPEND tfg_sources
    imprimir_mensajes_impl.cc
    repetidor_caracteres_impl.cc
    mensaje_a_mayusculas_impl.cc
    libNWK.cc
    libAPS.cc
    libMAC.cc
    bytes.cc
    imprimir_bytes_impl.cc
    test_nwk_impl.cc
    NWK_stack_impl.cc
    test_aps_impl.cc
    APS_stack_impl.cc
    NWK_stack_impl.cc
    translation_block_impl.cc
    Aplication_impl.cc
    mac.cc
    MAC_stack_impl.cc
    test_mac_impl.cc
    motecontrol_impl.cc )

set(tfg_sources "${tfg_sources}" PARENT_SCOPE)
if(NOT tfg_sources)
	MESSAGE(STATUS "No C++ sources... skipping lib/")
	return()
endif(NOT tfg_sources)

add_library(gnuradio-tfg SHARED ${tfg_sources})
target_link_libraries(gnuradio-tfg ${Boost_LIBRARIES} ${GNURADIO_ALL_LIBRARIES})
set_target_properties(gnuradio-tfg PROPERTIES DEFINE_SYMBOL "gnuradio_tfg_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-tfg PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
include(GrMiscUtils)
GR_LIBRARY_FOO(gnuradio-tfg RUNTIME_COMPONENT "tfg_runtime" DEVEL_COMPONENT "tfg_devel")

########################################################################
# Build and register unit test
########################################################################
include(GrTest)

include_directories(${CPPUNIT_INCLUDE_DIRS})

list(APPEND test_tfg_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/test_tfg.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_tfg.cc
)

add_executable(test-tfg ${test_tfg_sources})

target_link_libraries(
  test-tfg
  ${GNURADIO_RUNTIME_LIBRARIES}
  ${Boost_LIBRARIES}
  ${CPPUNIT_LIBRARIES}
  gnuradio-tfg
)

GR_ADD_TEST(test_tfg test-tfg)

########################################################################
# Print summary
########################################################################
message(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Building for version: ${VERSION} / ${LIBVER}")


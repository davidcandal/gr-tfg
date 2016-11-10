INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_TFG tfg)

FIND_PATH(
    TFG_INCLUDE_DIRS
    NAMES tfg/api.h
    HINTS $ENV{TFG_DIR}/include
        ${PC_TFG_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    TFG_LIBRARIES
    NAMES gnuradio-tfg
    HINTS $ENV{TFG_DIR}/lib
        ${PC_TFG_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TFG DEFAULT_MSG TFG_LIBRARIES TFG_INCLUDE_DIRS)
MARK_AS_ADVANCED(TFG_LIBRARIES TFG_INCLUDE_DIRS)


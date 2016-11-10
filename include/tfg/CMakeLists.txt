# Copyright 2011,2012 Free Software Foundation, Inc.
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
# Install public header files
########################################################################
install(FILES
    api.h
    imprimir_mensajes.h
    repetidor_caracteres.h
    mensaje_a_mayusculas.h
    imprimir_bytes.h
    test_nwk.h
    test_aps.h
    APS_stack.h
    NWK_stack.h
    translation_block.h
    Aplication.h
    mac.h
    MAC_stack.h
    test_mac.h
    motecontrol.h DESTINATION include/tfg
)

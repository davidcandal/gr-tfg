# Copyright 2011 Free Software Foundation, Inc.
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
install(FILES
    tfg_imprimir_mensajes.xml
    tfg_repetidor_caracteres.xml
    tfg_mensaje_a_mayusculas.xml
    tfg_imprimir_bytes.xml
    tfg_test_nwk.xml
    tfg_test_aps.xml
    tfg_APS_stack.xml
    tfg_NWK_stack.xml
    tfg_translation_block.xml
    tfg_Aplication.xml
    tfg_mac.xml
    tfg_MAC_stack.xml
    tfg_test_mac.xml
    tfg_motecontrol.xml DESTINATION share/gnuradio/grc/blocks
)

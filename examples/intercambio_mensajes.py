#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Intercambio Mensajes
# Generated: Tue Aug 30 00:13:58 2016
##################################################

from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser
import pmt
import tfg


class intercambio_mensajes(gr.top_block):

    def __init__(self):
        gr.top_block.__init__(self, "Intercambio Mensajes")

        ##################################################
        # Variables
        ##################################################
        self.samp_rate = samp_rate = 32000

        ##################################################
        # Blocks
        ##################################################
        self.tfg_repetidor_caracteres_0 = tfg.repetidor_caracteres(2)
        self.tfg_mensaje_a_mayusculas_0 = tfg.mensaje_a_mayusculas()
        self.tfg_imprimir_mensajes_0 = tfg.imprimir_mensajes()
        self.blocks_message_strobe_0 = blocks.message_strobe(pmt.intern("prueba"), 1000)

        ##################################################
        # Connections
        ##################################################
        self.msg_connect((self.blocks_message_strobe_0, 'strobe'), (self.tfg_mensaje_a_mayusculas_0, 'entrada'))    
        self.msg_connect((self.tfg_mensaje_a_mayusculas_0, 'salida'), (self.tfg_repetidor_caracteres_0, 'entrada'))    
        self.msg_connect((self.tfg_repetidor_caracteres_0, 'salida'), (self.tfg_imprimir_mensajes_0, 'entrada'))    

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate


def main(top_block_cls=intercambio_mensajes, options=None):

    tb = top_block_cls()
    tb.start()
    try:
        raw_input('Press Enter to quit: ')
    except EOFError:
        pass
    tb.stop()
    tb.wait()


if __name__ == '__main__':
    main()

#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Nwk
# Generated: Thu Sep  1 18:34:18 2016
##################################################

if __name__ == '__main__':
    import ctypes
    import sys
    if sys.platform.startswith('linux'):
        try:
            x11 = ctypes.cdll.LoadLibrary('libX11.so')
            x11.XInitThreads()
        except:
            print "Warning: failed to XInitThreads()"

from PyQt4 import Qt
from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser
import pmt
import sys
import tfg


class nwk(gr.top_block, Qt.QWidget):

    def __init__(self):
        gr.top_block.__init__(self, "Nwk")
        Qt.QWidget.__init__(self)
        self.setWindowTitle("Nwk")
        try:
            self.setWindowIcon(Qt.QIcon.fromTheme('gnuradio-grc'))
        except:
            pass
        self.top_scroll_layout = Qt.QVBoxLayout()
        self.setLayout(self.top_scroll_layout)
        self.top_scroll = Qt.QScrollArea()
        self.top_scroll.setFrameStyle(Qt.QFrame.NoFrame)
        self.top_scroll_layout.addWidget(self.top_scroll)
        self.top_scroll.setWidgetResizable(True)
        self.top_widget = Qt.QWidget()
        self.top_scroll.setWidget(self.top_widget)
        self.top_layout = Qt.QVBoxLayout(self.top_widget)
        self.top_grid_layout = Qt.QGridLayout()
        self.top_layout.addLayout(self.top_grid_layout)

        self.settings = Qt.QSettings("GNU Radio", "nwk")
        self.restoreGeometry(self.settings.value("geometry").toByteArray())

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
        self.tfg_NWK_stack_constructor_0 = tfg.NWK_stack_constructor(0x12, 0x24)
        self.blocks_message_strobe_0 = blocks.message_strobe(pmt.intern("asdfghk"), 1000)

        ##################################################
        # Connections
        ##################################################
        self.msg_connect((self.blocks_message_strobe_0, 'strobe'), (self.tfg_mensaje_a_mayusculas_0, 'entrada'))    
        self.msg_connect((self.tfg_NWK_stack_constructor_0, 'out(MAC)'), (self.tfg_repetidor_caracteres_0, 'entrada'))    
        self.msg_connect((self.tfg_mensaje_a_mayusculas_0, 'salida'), (self.tfg_NWK_stack_constructor_0, 'in(APS)'))    
        self.msg_connect((self.tfg_repetidor_caracteres_0, 'salida'), (self.tfg_imprimir_mensajes_0, 'entrada'))    

    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "nwk")
        self.settings.setValue("geometry", self.saveGeometry())
        event.accept()

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate


def main(top_block_cls=nwk, options=None):

    from distutils.version import StrictVersion
    if StrictVersion(Qt.qVersion()) >= StrictVersion("4.5.0"):
        style = gr.prefs().get_string('qtgui', 'style', 'raster')
        Qt.QApplication.setGraphicsSystem(style)
    qapp = Qt.QApplication(sys.argv)

    tb = top_block_cls()
    tb.start()
    tb.show()

    def quitting():
        tb.stop()
        tb.wait()
    qapp.connect(qapp, Qt.SIGNAL("aboutToQuit()"), quitting)
    qapp.exec_()


if __name__ == '__main__':
    main()

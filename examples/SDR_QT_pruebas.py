#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: TFG
# Author: David Candal
# Description: SDR ZigBee
# Generated: Sat Sep 17 14:39:08 2016
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

import os
import sys
sys.path.append(os.environ.get('GRC_HIER_PATH', os.path.expanduser('~/.grc_gnuradio')))

from PyQt4 import Qt
from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from ieee802_15_4_oqpsk_phy import ieee802_15_4_oqpsk_phy  # grc-generated hier_block
from optparse import OptionParser
import foo
import pmt
import tfg


class SDR_QT_pruebas(gr.top_block, Qt.QWidget):

    def __init__(self):
        gr.top_block.__init__(self, "TFG")
        Qt.QWidget.__init__(self)
        self.setWindowTitle("TFG")
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

        self.settings = Qt.QSettings("GNU Radio", "SDR_QT_pruebas")
        self.restoreGeometry(self.settings.value("geometry").toByteArray())

        ##################################################
        # Blocks
        ##################################################
        self.tfg_translation_block_0 = tfg.translation_block()
        self.tfg_test_aps_0 = tfg.test_aps()
        self.tfg_mac_0 = tfg.mac(True)
        self.tfg_NWK_stack_0 = tfg.NWK_stack(True, False)
        self.tfg_APS_stack_0 = tfg.APS_stack(True, False)
        self.ieee802_15_4_oqpsk_phy_0 = ieee802_15_4_oqpsk_phy()
        self.foo_wireshark_connector_0 = foo.wireshark_connector(195, False)
        self.foo_packet_pad_0 = foo.packet_pad(False, True, 0.1, 2000, 2000)
        self.blocks_message_strobe_0 = blocks.message_strobe(pmt.intern(""), 1000)
        self.blocks_file_sink_0 = blocks.file_sink(gr.sizeof_char*1, '/tmp/sensor.pcap', False)
        self.blocks_file_sink_0.set_unbuffered(True)

        ##################################################
        # Connections
        ##################################################
        self.msg_connect((self.blocks_message_strobe_0, 'strobe'), (self.tfg_test_aps_0, 'entrada'))    
        self.msg_connect((self.ieee802_15_4_oqpsk_phy_0, 'rxout'), (self.foo_wireshark_connector_0, 'in'))    
        self.msg_connect((self.ieee802_15_4_oqpsk_phy_0, 'rxout'), (self.tfg_mac_0, 'pdu in'))    
        self.msg_connect((self.tfg_APS_stack_0, 'out(NWK)'), (self.tfg_NWK_stack_0, 'in(APS)'))    
        self.msg_connect((self.tfg_NWK_stack_0, 'out(APS)'), (self.tfg_APS_stack_0, 'in(NWK)'))    
        self.msg_connect((self.tfg_NWK_stack_0, 'out(MAC)'), (self.tfg_translation_block_0, 'in(david)'))    
        self.msg_connect((self.tfg_mac_0, 'pdu out'), (self.ieee802_15_4_oqpsk_phy_0, 'txin'))    
        self.msg_connect((self.tfg_mac_0, 'app out'), (self.tfg_translation_block_0, 'in(bastibl)'))    
        self.msg_connect((self.tfg_test_aps_0, 'salida'), (self.tfg_APS_stack_0, 'in(ZCL)'))    
        self.msg_connect((self.tfg_translation_block_0, 'out(david)'), (self.tfg_NWK_stack_0, 'in(MAC)'))    
        self.msg_connect((self.tfg_translation_block_0, 'out(bastibl)'), (self.tfg_mac_0, 'app in'))    
        self.connect((self.foo_packet_pad_0, 0), (self.ieee802_15_4_oqpsk_phy_0, 0))    
        self.connect((self.foo_wireshark_connector_0, 0), (self.blocks_file_sink_0, 0))    
        self.connect((self.ieee802_15_4_oqpsk_phy_0, 0), (self.foo_packet_pad_0, 0))    

    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "SDR_QT_pruebas")
        self.settings.setValue("geometry", self.saveGeometry())
        event.accept()


def main(top_block_cls=SDR_QT_pruebas, options=None):
    if gr.enable_realtime_scheduling() != gr.RT_OK:
        print "Error: failed to enable real-time scheduling."

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

#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: TFG
# Author: David Candal
# Description: SDR ZigBee
# Generated: Tue Sep 20 00:25:27 2016
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
from PyQt4.QtCore import QObject, pyqtSlot
from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio import qtgui
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from gnuradio.qtgui import Range, RangeWidget
from ieee802_15_4_oqpsk_phy import ieee802_15_4_oqpsk_phy  # grc-generated hier_block
from optparse import OptionParser
import foo
import sip
import tfg


class SDR(gr.top_block, Qt.QWidget):

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

        self.settings = Qt.QSettings("GNU Radio", "SDR")
        self.restoreGeometry(self.settings.value("geometry").toByteArray())

        ##################################################
        # Variables
        ##################################################
        self.profileID = profileID = 0xDCBA
        self.profile = profile = ""
        self.payload = payload = "EJEMPLO"
        self.nseq = nseq = ""
        self.label_payload = label_payload = ""
        self.label_nwk_src = label_nwk_src = ""
        self.label_nwk_dst = label_nwk_dst = ""
        self.gain = gain = 30
        self.freq = freq = 2480000000
        self.enviar = enviar = False
        self.endpoint_src = endpoint_src = ""
        self.endpoint_dst = endpoint_dst = ""
        self.clusterID = clusterID = 0xABCD
        self.cluster = cluster = ""
        self.NWK_add_src = NWK_add_src = 0xABCD
        self.NWK_add_dst = NWK_add_dst = 0xDCBA
        self.Endpoint_src = Endpoint_src = 10
        self.Endpoint_dst = Endpoint_dst = 20

        ##################################################
        # Blocks
        ##################################################
        self.Tab = Qt.QTabWidget()
        self.Tab_widget_0 = Qt.QWidget()
        self.Tab_layout_0 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.Tab_widget_0)
        self.Tab_grid_layout_0 = Qt.QGridLayout()
        self.Tab_layout_0.addLayout(self.Tab_grid_layout_0)
        self.Tab.addTab(self.Tab_widget_0, 'Transmision')
        self.Tab_widget_1 = Qt.QWidget()
        self.Tab_layout_1 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.Tab_widget_1)
        self.Tab_grid_layout_1 = Qt.QGridLayout()
        self.Tab_layout_1.addLayout(self.Tab_grid_layout_1)
        self.Tab.addTab(self.Tab_widget_1, 'Recepcion')
        self.top_layout.addWidget(self.Tab)
        self.tfg_NWK_stack_0 = tfg.NWK_stack(True, False)
        self.tfg_MAC_stack_0 = tfg.MAC_stack(False, False)
        self.tfg_Aplication_0 = tfg.Aplication()
        self.tfg_APS_stack_0 = tfg.APS_stack(True, False)
        self._profileID_tool_bar = Qt.QToolBar(self)
        self._profileID_tool_bar.addWidget(Qt.QLabel("ID de perfil"+": "))
        self._profileID_line_edit = Qt.QLineEdit(str(self.profileID))
        self._profileID_tool_bar.addWidget(self._profileID_line_edit)
        self._profileID_line_edit.returnPressed.connect(
        	lambda: self.set_profileID(int(str(self._profileID_line_edit.text().toAscii()))))
        self.Tab_grid_layout_0 .addWidget(self._profileID_tool_bar,  3,2,1,1)
        self._profile_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._profile_formatter = None
        else:
          self._profile_formatter = lambda x: x
        
        self._profile_tool_bar.addWidget(Qt.QLabel('ID de perfil'+": "))
        self._profile_label = Qt.QLabel(str(self._profile_formatter(self.profile)))
        self._profile_tool_bar.addWidget(self._profile_label)
        self.Tab_grid_layout_1 .addWidget(self._profile_tool_bar,  3,2,1,1)
          
        self.perfl_r = qtgui.edit_box_msg(qtgui.INT, '', '', True, True, "perfil")
        self._perfl_r_win = sip.wrapinstance(self.perfl_r.pyqwidget(), Qt.QWidget)
        self.Tab_grid_layout_1 .addWidget(self._perfl_r_win,  3,3,1,1)
        self.payload_r = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, "payload")
        self._payload_r_win = sip.wrapinstance(self.payload_r.pyqwidget(), Qt.QWidget)
        self.Tab_grid_layout_1 .addWidget(self._payload_r_win,  0,1,1,3)
        self._payload_tool_bar = Qt.QToolBar(self)
        self._payload_tool_bar.addWidget(Qt.QLabel('Carga del mensaje'+": "))
        self._payload_line_edit = Qt.QLineEdit(str(self.payload))
        self._payload_tool_bar.addWidget(self._payload_line_edit)
        self._payload_line_edit.returnPressed.connect(
        	lambda: self.set_payload(str(str(self._payload_line_edit.text().toAscii()))))
        self.Tab_grid_layout_0 .addWidget(self._payload_tool_bar,  0,0,1,3)
        self.nseq_r = qtgui.edit_box_msg(qtgui.INT, '', '', True, True, "nseq")
        self._nseq_r_win = sip.wrapinstance(self.nseq_r.pyqwidget(), Qt.QWidget)
        self.Tab_grid_layout_1 .addWidget(self._nseq_r_win,  4,1,1,1)
        self._nseq_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._nseq_formatter = None
        else:
          self._nseq_formatter = lambda x: x
        
        self._nseq_tool_bar.addWidget(Qt.QLabel('Numero de secuencia'+": "))
        self._nseq_label = Qt.QLabel(str(self._nseq_formatter(self.nseq)))
        self._nseq_tool_bar.addWidget(self._nseq_label)
        self.Tab_grid_layout_1 .addWidget(self._nseq_tool_bar,  4,0,1,1)
          
        self._label_payload_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._label_payload_formatter = None
        else:
          self._label_payload_formatter = lambda x: x
        
        self._label_payload_tool_bar.addWidget(Qt.QLabel('Carga'+": "))
        self._label_payload_label = Qt.QLabel(str(self._label_payload_formatter(self.label_payload)))
        self._label_payload_tool_bar.addWidget(self._label_payload_label)
        self.Tab_grid_layout_1 .addWidget(self._label_payload_tool_bar,  0,0,1,1)
          
        self._label_nwk_src_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._label_nwk_src_formatter = None
        else:
          self._label_nwk_src_formatter = lambda x: x
        
        self._label_nwk_src_tool_bar.addWidget(Qt.QLabel('Direccion NWK origen'+": "))
        self._label_nwk_src_label = Qt.QLabel(str(self._label_nwk_src_formatter(self.label_nwk_src)))
        self._label_nwk_src_tool_bar.addWidget(self._label_nwk_src_label)
        self.Tab_grid_layout_1 .addWidget(self._label_nwk_src_tool_bar,  1,0,1,1)
          
        self._label_nwk_dst_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._label_nwk_dst_formatter = None
        else:
          self._label_nwk_dst_formatter = lambda x: x
        
        self._label_nwk_dst_tool_bar.addWidget(Qt.QLabel('Direccion NWK destino'+": "))
        self._label_nwk_dst_label = Qt.QLabel(str(self._label_nwk_dst_formatter(self.label_nwk_dst)))
        self._label_nwk_dst_tool_bar.addWidget(self._label_nwk_dst_label)
        self.Tab_grid_layout_1 .addWidget(self._label_nwk_dst_tool_bar,  1,2,1,1)
          
        self.ieee802_15_4_oqpsk_phy_0 = ieee802_15_4_oqpsk_phy()
        self._gain_range = Range(1, 100, 1, 30, 200)
        self._gain_win = RangeWidget(self._gain_range, self.set_gain, 'Ganancia TX', "counter_slider", int)
        self.top_grid_layout.addWidget(self._gain_win, 0,0,1,1)
        self._freq_options = [1000000 * (2400 + 5 * (i - 10)) for i in range(11, 27)]
        self._freq_labels = ["11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27"]
        self._freq_tool_bar = Qt.QToolBar(self)
        self._freq_tool_bar.addWidget(Qt.QLabel('Canal'+": "))
        self._freq_combo_box = Qt.QComboBox()
        self._freq_tool_bar.addWidget(self._freq_combo_box)
        for label in self._freq_labels: self._freq_combo_box.addItem(label)
        self._freq_callback = lambda i: Qt.QMetaObject.invokeMethod(self._freq_combo_box, "setCurrentIndex", Qt.Q_ARG("int", self._freq_options.index(i)))
        self._freq_callback(self.freq)
        self._freq_combo_box.currentIndexChanged.connect(
        	lambda i: self.set_freq(self._freq_options[i]))
        self.top_grid_layout.addWidget(self._freq_tool_bar, 0,1,1,1)
        self.foo_wireshark_connector_0 = foo.wireshark_connector(195, False)
        self.foo_packet_pad_0 = foo.packet_pad(False, True, 10, 2000, 2000)
        _enviar_push_button = Qt.QPushButton('Enviar')
        self._enviar_choices = {'Pressed': True, 'Released': False}
        _enviar_push_button.pressed.connect(lambda: self.tfg_Aplication_0.send())
        _enviar_push_button.released.connect(lambda: self.set_enviar(self._enviar_choices['Released']))
        self.Tab_grid_layout_0 .addWidget(_enviar_push_button,  7,0,1,3)
        self.endpoint_src_r = qtgui.edit_box_msg(qtgui.INT, '', '', True, True, "endpoint_src")
        self._endpoint_src_r_win = sip.wrapinstance(self.endpoint_src_r.pyqwidget(), Qt.QWidget)
        self.Tab_grid_layout_1 .addWidget(self._endpoint_src_r_win,  2,1,1,1)
        self._endpoint_src_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._endpoint_src_formatter = None
        else:
          self._endpoint_src_formatter = lambda x: x
        
        self._endpoint_src_tool_bar.addWidget(Qt.QLabel('Enpoint origen'+": "))
        self._endpoint_src_label = Qt.QLabel(str(self._endpoint_src_formatter(self.endpoint_src)))
        self._endpoint_src_tool_bar.addWidget(self._endpoint_src_label)
        self.Tab_grid_layout_1 .addWidget(self._endpoint_src_tool_bar,  2,0,1,1)
          
        self.endpoint_dst_r = qtgui.edit_box_msg(qtgui.INT, '', '', True, True, "endpoint_dst")
        self._endpoint_dst_r_win = sip.wrapinstance(self.endpoint_dst_r.pyqwidget(), Qt.QWidget)
        self.Tab_grid_layout_1 .addWidget(self._endpoint_dst_r_win,  2,3,1,1)
        self._endpoint_dst_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._endpoint_dst_formatter = None
        else:
          self._endpoint_dst_formatter = lambda x: x
        
        self._endpoint_dst_tool_bar.addWidget(Qt.QLabel('Endpoint destino'+": "))
        self._endpoint_dst_label = Qt.QLabel(str(self._endpoint_dst_formatter(self.endpoint_dst)))
        self._endpoint_dst_tool_bar.addWidget(self._endpoint_dst_label)
        self.Tab_grid_layout_1 .addWidget(self._endpoint_dst_tool_bar,  2,2,1,1)
          
        self.cluster_r = qtgui.edit_box_msg(qtgui.INT, '', '', True, True, "cluster")
        self._cluster_r_win = sip.wrapinstance(self.cluster_r.pyqwidget(), Qt.QWidget)
        self.Tab_grid_layout_1 .addWidget(self._cluster_r_win,  3,1,1,1)
        self._clusterID_tool_bar = Qt.QToolBar(self)
        self._clusterID_tool_bar.addWidget(Qt.QLabel("ID de cluster"+": "))
        self._clusterID_line_edit = Qt.QLineEdit(str(self.clusterID))
        self._clusterID_tool_bar.addWidget(self._clusterID_line_edit)
        self._clusterID_line_edit.returnPressed.connect(
        	lambda: self.set_clusterID(int(str(self._clusterID_line_edit.text().toAscii()))))
        self.Tab_grid_layout_0 .addWidget(self._clusterID_tool_bar,  3,0,1,1)
        self._cluster_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._cluster_formatter = None
        else:
          self._cluster_formatter = lambda x: x
        
        self._cluster_tool_bar.addWidget(Qt.QLabel('ID de cluster'+": "))
        self._cluster_label = Qt.QLabel(str(self._cluster_formatter(self.cluster)))
        self._cluster_tool_bar.addWidget(self._cluster_label)
        self.Tab_grid_layout_1 .addWidget(self._cluster_tool_bar,  3,0,1,1)
          
        self.blocks_file_sink_0 = blocks.file_sink(gr.sizeof_char*1, '/tmp/sensor.pcap', False)
        self.blocks_file_sink_0.set_unbuffered(True)
        self.NWK_add_src_r = qtgui.edit_box_msg(qtgui.INT, '', '', True, True, "NWK_add_src")
        self._NWK_add_src_r_win = sip.wrapinstance(self.NWK_add_src_r.pyqwidget(), Qt.QWidget)
        self.Tab_grid_layout_1 .addWidget(self._NWK_add_src_r_win,  1,1,1,1)
        self._NWK_add_src_tool_bar = Qt.QToolBar(self)
        self._NWK_add_src_tool_bar.addWidget(Qt.QLabel("Direccion NWK origen"+": "))
        self._NWK_add_src_line_edit = Qt.QLineEdit(str(self.NWK_add_src))
        self._NWK_add_src_tool_bar.addWidget(self._NWK_add_src_line_edit)
        self._NWK_add_src_line_edit.returnPressed.connect(
        	lambda: self.set_NWK_add_src(int(str(self._NWK_add_src_line_edit.text().toAscii()))))
        self.Tab_grid_layout_0 .addWidget(self._NWK_add_src_tool_bar,  1,0,1,1)
        self.NWK_add_dst_r = qtgui.edit_box_msg(qtgui.INT, '', '', True, True, "NWK_add_dst")
        self._NWK_add_dst_r_win = sip.wrapinstance(self.NWK_add_dst_r.pyqwidget(), Qt.QWidget)
        self.Tab_grid_layout_1 .addWidget(self._NWK_add_dst_r_win,  1,3,1,1)
        self._NWK_add_dst_tool_bar = Qt.QToolBar(self)
        self._NWK_add_dst_tool_bar.addWidget(Qt.QLabel("Direccion NWK destino"+": "))
        self._NWK_add_dst_line_edit = Qt.QLineEdit(str(self.NWK_add_dst))
        self._NWK_add_dst_tool_bar.addWidget(self._NWK_add_dst_line_edit)
        self._NWK_add_dst_line_edit.returnPressed.connect(
        	lambda: self.set_NWK_add_dst(int(str(self._NWK_add_dst_line_edit.text().toAscii()))))
        self.Tab_grid_layout_0 .addWidget(self._NWK_add_dst_tool_bar,  1,2,1,1)
        self._Endpoint_src_tool_bar = Qt.QToolBar(self)
        self._Endpoint_src_tool_bar.addWidget(Qt.QLabel("Endpoint origen"+": "))
        self._Endpoint_src_line_edit = Qt.QLineEdit(str(self.Endpoint_src))
        self._Endpoint_src_tool_bar.addWidget(self._Endpoint_src_line_edit)
        self._Endpoint_src_line_edit.returnPressed.connect(
        	lambda: self.set_Endpoint_src(int(str(self._Endpoint_src_line_edit.text().toAscii()))))
        self.Tab_grid_layout_0 .addWidget(self._Endpoint_src_tool_bar,  2,0,1,1)
        self._Endpoint_dst_tool_bar = Qt.QToolBar(self)
        self._Endpoint_dst_tool_bar.addWidget(Qt.QLabel("Endpoint destino"+": "))
        self._Endpoint_dst_line_edit = Qt.QLineEdit(str(self.Endpoint_dst))
        self._Endpoint_dst_tool_bar.addWidget(self._Endpoint_dst_line_edit)
        self._Endpoint_dst_line_edit.returnPressed.connect(
        	lambda: self.set_Endpoint_dst(int(str(self._Endpoint_dst_line_edit.text().toAscii()))))
        self.Tab_grid_layout_0 .addWidget(self._Endpoint_dst_tool_bar,  2,2,1,1)

        ##################################################
        # Connections
        ##################################################
        self.msg_connect((self.ieee802_15_4_oqpsk_phy_0, 'rxout'), (self.foo_wireshark_connector_0, 'in'))    
        self.msg_connect((self.ieee802_15_4_oqpsk_phy_0, 'rxout'), (self.tfg_MAC_stack_0, 'in(PHY)'))    
        self.msg_connect((self.tfg_APS_stack_0, 'out(ZCL)'), (self.tfg_Aplication_0, 'in'))    
        self.msg_connect((self.tfg_APS_stack_0, 'out(NWK)'), (self.tfg_NWK_stack_0, 'in(APS)'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_add_dst_r, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_add_src_r, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.cluster_r, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.endpoint_dst_r, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.endpoint_src_r, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.nseq_r, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.payload_r, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.perfl_r, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.tfg_APS_stack_0, 'in(ZCL)'))    
        self.msg_connect((self.tfg_MAC_stack_0, 'out(PHY)'), (self.foo_wireshark_connector_0, 'in'))    
        self.msg_connect((self.tfg_MAC_stack_0, 'out(PHY)'), (self.ieee802_15_4_oqpsk_phy_0, 'txin'))    
        self.msg_connect((self.tfg_MAC_stack_0, 'out(NWK)'), (self.tfg_NWK_stack_0, 'in(MAC)'))    
        self.msg_connect((self.tfg_NWK_stack_0, 'out(APS)'), (self.tfg_APS_stack_0, 'in(NWK)'))    
        self.msg_connect((self.tfg_NWK_stack_0, 'out(MAC)'), (self.tfg_MAC_stack_0, 'in(NWK)'))    
        self.connect((self.foo_packet_pad_0, 0), (self.ieee802_15_4_oqpsk_phy_0, 0))    
        self.connect((self.foo_wireshark_connector_0, 0), (self.blocks_file_sink_0, 0))    
        self.connect((self.ieee802_15_4_oqpsk_phy_0, 0), (self.foo_packet_pad_0, 0))    

    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "SDR")
        self.settings.setValue("geometry", self.saveGeometry())
        event.accept()

    def get_profileID(self):
        return self.profileID

    def set_profileID(self, profileID):
        self.profileID = profileID
        Qt.QMetaObject.invokeMethod(self._profileID_line_edit, "setText", Qt.Q_ARG("QString", str(self.profileID)))
        self.tfg_Aplication_0.setProfile(self.profileID)

    def get_profile(self):
        return self.profile

    def set_profile(self, profile):
        self.profile = profile
        Qt.QMetaObject.invokeMethod(self._profile_label, "setText", Qt.Q_ARG("QString", str(self.profile)))

    def get_payload(self):
        return self.payload

    def set_payload(self, payload):
        self.payload = payload
        Qt.QMetaObject.invokeMethod(self._payload_line_edit, "setText", Qt.Q_ARG("QString", str(self.payload)))
        self.tfg_Aplication_0.setPayload(self.payload)

    def get_nseq(self):
        return self.nseq

    def set_nseq(self, nseq):
        self.nseq = nseq
        Qt.QMetaObject.invokeMethod(self._nseq_label, "setText", Qt.Q_ARG("QString", str(self.nseq)))

    def get_label_payload(self):
        return self.label_payload

    def set_label_payload(self, label_payload):
        self.label_payload = label_payload
        Qt.QMetaObject.invokeMethod(self._label_payload_label, "setText", Qt.Q_ARG("QString", str(self.label_payload)))

    def get_label_nwk_src(self):
        return self.label_nwk_src

    def set_label_nwk_src(self, label_nwk_src):
        self.label_nwk_src = label_nwk_src
        Qt.QMetaObject.invokeMethod(self._label_nwk_src_label, "setText", Qt.Q_ARG("QString", str(self.label_nwk_src)))

    def get_label_nwk_dst(self):
        return self.label_nwk_dst

    def set_label_nwk_dst(self, label_nwk_dst):
        self.label_nwk_dst = label_nwk_dst
        Qt.QMetaObject.invokeMethod(self._label_nwk_dst_label, "setText", Qt.Q_ARG("QString", str(self.label_nwk_dst)))

    def get_gain(self):
        return self.gain

    def set_gain(self, gain):
        self.gain = gain

    def get_freq(self):
        return self.freq

    def set_freq(self, freq):
        self.freq = freq
        self._freq_callback(self.freq)

    def get_enviar(self):
        return self.enviar

    def set_enviar(self, enviar):
        self.enviar = enviar

    def get_endpoint_src(self):
        return self.endpoint_src

    def set_endpoint_src(self, endpoint_src):
        self.endpoint_src = endpoint_src
        Qt.QMetaObject.invokeMethod(self._endpoint_src_label, "setText", Qt.Q_ARG("QString", str(self.endpoint_src)))

    def get_endpoint_dst(self):
        return self.endpoint_dst

    def set_endpoint_dst(self, endpoint_dst):
        self.endpoint_dst = endpoint_dst
        Qt.QMetaObject.invokeMethod(self._endpoint_dst_label, "setText", Qt.Q_ARG("QString", str(self.endpoint_dst)))

    def get_clusterID(self):
        return self.clusterID

    def set_clusterID(self, clusterID):
        self.clusterID = clusterID
        Qt.QMetaObject.invokeMethod(self._clusterID_line_edit, "setText", Qt.Q_ARG("QString", str(self.clusterID)))
        self.tfg_Aplication_0.setCluster(self.clusterID)

    def get_cluster(self):
        return self.cluster

    def set_cluster(self, cluster):
        self.cluster = cluster
        Qt.QMetaObject.invokeMethod(self._cluster_label, "setText", Qt.Q_ARG("QString", str(self.cluster)))

    def get_NWK_add_src(self):
        return self.NWK_add_src

    def set_NWK_add_src(self, NWK_add_src):
        self.NWK_add_src = NWK_add_src
        Qt.QMetaObject.invokeMethod(self._NWK_add_src_line_edit, "setText", Qt.Q_ARG("QString", str(self.NWK_add_src)))
        self.tfg_Aplication_0.setNWKSrc(self.NWK_add_src)

    def get_NWK_add_dst(self):
        return self.NWK_add_dst

    def set_NWK_add_dst(self, NWK_add_dst):
        self.NWK_add_dst = NWK_add_dst
        Qt.QMetaObject.invokeMethod(self._NWK_add_dst_line_edit, "setText", Qt.Q_ARG("QString", str(self.NWK_add_dst)))
        self.tfg_Aplication_0.setNWKDst(self.NWK_add_dst)

    def get_Endpoint_src(self):
        return self.Endpoint_src

    def set_Endpoint_src(self, Endpoint_src):
        self.Endpoint_src = Endpoint_src
        Qt.QMetaObject.invokeMethod(self._Endpoint_src_line_edit, "setText", Qt.Q_ARG("QString", str(self.Endpoint_src)))
        self.tfg_Aplication_0.setEndpointSrc(self.Endpoint_src)

    def get_Endpoint_dst(self):
        return self.Endpoint_dst

    def set_Endpoint_dst(self, Endpoint_dst):
        self.Endpoint_dst = Endpoint_dst
        Qt.QMetaObject.invokeMethod(self._Endpoint_dst_line_edit, "setText", Qt.Q_ARG("QString", str(self.Endpoint_dst)))
        self.tfg_Aplication_0.setEndpointDst(self.Endpoint_dst)


def main(top_block_cls=SDR, options=None):
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

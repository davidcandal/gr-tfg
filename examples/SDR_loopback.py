#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: TFG
# Author: David Candal
# Description: SDR ZigBee
# Generated: Sun Sep 25 14:20:27 2016
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


class SDR_loopback(gr.top_block, Qt.QWidget):

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

        self.settings = Qt.QSettings("GNU Radio", "SDR_loopback")
        self.restoreGeometry(self.settings.value("geometry").toByteArray())

        ##################################################
        # Variables
        ##################################################
        self.payload = payload = "Ejemplo"
        self.gain = gain = 30
        self.freq = freq = 2480000000
        self.enviar = enviar = False
        self.NWK_tipoTrama = NWK_tipoTrama = 0
        self.NWK_sourceRoute = NWK_sourceRoute = False
        self.NWK_seguridad = NWK_seguridad = False
        self.NWK_radio = NWK_radio = '7'
        self.NWK_modoMulticast = NWK_modoMulticast = 0
        self.NWK_mcastRadioMax = NWK_mcastRadioMax = '7'
        self.NWK_mcastRadio = NWK_mcastRadio = '7'
        self.NWK_ieeeSrc = NWK_ieeeSrc = False
        self.NWK_ieeeDst = NWK_ieeeDst = False
        self.NWK_etq_tipoTrama = NWK_etq_tipoTrama = ""
        self.NWK_etq_sourceRoute = NWK_etq_sourceRoute = ""
        self.NWK_etq_seguridad = NWK_etq_seguridad = ""
        self.NWK_etq_radio = NWK_etq_radio = ""
        self.NWK_etq_numSeq = NWK_etq_numSeq = ""
        self.NWK_etq_multicast = NWK_etq_multicast = ""
        self.NWK_etq_modomulticast = NWK_etq_modomulticast = ""
        self.NWK_etq_mcastRadioMax = NWK_etq_mcastRadioMax = ""
        self.NWK_etq_mcastRadio = NWK_etq_mcastRadio = ""
        self.NWK_etq_ieeeSrc = NWK_etq_ieeeSrc = ""
        self.NWK_etq_ieeeDst = NWK_etq_ieeeDst = ""
        self.NWK_etq_direccionesSR = NWK_etq_direccionesSR = ""
        self.NWK_etq_dirOrigen = NWK_etq_dirOrigen = ""
        self.NWK_etq_dirIeeeOrg = NWK_etq_dirIeeeOrg = ""
        self.NWK_etq_dirIeeeDst = NWK_etq_dirIeeeDst = ""
        self.NWK_etq_dirDestino = NWK_etq_dirDestino = ""
        self.NWK_etq_descRuta = NWK_etq_descRuta = ""
        self.NWK_direccionesSR = NWK_direccionesSR = '0xDCBA,0XABCD'
        self.NWK_dirOrigen = NWK_dirOrigen = '0x1111'
        self.NWK_dirIEEESrc = NWK_dirIEEESrc = '0x1010101010101010'
        self.NWK_dirIEEEDst = NWK_dirIEEEDst = '0x0101010101010101'
        self.NWK_dirDestino = NWK_dirDestino = '0x2222'
        self.NWK_descRuta = NWK_descRuta = False
        self.NWK_Multicast = NWK_Multicast = False
        self.MAC_tramaPendiente = MAC_tramaPendiente = False
        self.MAC_tipoTrama = MAC_tipoTrama = 1
        self.MAC_seguridad = MAC_seguridad = False
        self.MAC_reqACK = MAC_reqACK = False
        self.MAC_panOrigen = MAC_panOrigen = '0xABCD'
        self.MAC_panDestino = MAC_panDestino = '0xDCBA'
        self.MAC_modoSrc = MAC_modoSrc = 1
        self.MAC_modoDest = MAC_modoDest = 1
        self.MAC_intraPAN = MAC_intraPAN = False
        self.MAC_etq_tramaPendiente = MAC_etq_tramaPendiente = ""
        self.MAC_etq_tipoTrama = MAC_etq_tipoTrama = ""
        self.MAC_etq_seguridad = MAC_etq_seguridad = ""
        self.MAC_etq_reqACK = MAC_etq_reqACK = ""
        self.MAC_etq_payload = MAC_etq_payload = ""
        self.MAC_etq_panOrigen = MAC_etq_panOrigen = ""
        self.MAC_etq_panDestino = MAC_etq_panDestino = ""
        self.MAC_etq_numSeq = MAC_etq_numSeq = ""
        self.MAC_etq_modoSrc = MAC_etq_modoSrc = ""
        self.MAC_etq_modoDest = MAC_etq_modoDest = ""
        self.MAC_etq_intraPAN = MAC_etq_intraPAN = ""
        self.MAC_etq_dirOrigen = MAC_etq_dirOrigen = ""
        self.MAC_etq_dirDestino = MAC_etq_dirDestino = ""
        self.MAC_dirOrigen = MAC_dirOrigen = '0x1010101010101010'
        self.MAC_dirDestino = MAC_dirDestino = '0x0101010101010101'
        self.APS_tipoTrama = APS_tipoTrama = 0
        self.APS_solicitaACK = APS_solicitaACK = False
        self.APS_seguridad = APS_seguridad = False
        self.APS_perfil = APS_perfil = '0xDCBA'
        self.APS_modo = APS_modo = 0
        self.APS_grupo = APS_grupo = '0x1234'
        self.APS_fragmentado = APS_fragmentado = 0
        self.APS_formatoACK = APS_formatoACK = False
        self.APS_etq_tipoTrama = APS_etq_tipoTrama = ""
        self.APS_etq_solicitaACK = APS_etq_solicitaACK = ""
        self.APS_etq_seguridad = APS_etq_seguridad = ""
        self.APS_etq_perfil = APS_etq_perfil = ""
        self.APS_etq_modo = APS_etq_modo = ""
        self.APS_etq_grupo = APS_etq_grupo = ""
        self.APS_etq_fragmentado = APS_etq_fragmentado = ""
        self.APS_etq_formatoACK = APS_etq_formatoACK = ""
        self.APS_etq_endpointOrigen = APS_etq_endpointOrigen = ""
        self.APS_etq_endpointDestino = APS_etq_endpointDestino = ""
        self.APS_etq_counter = APS_etq_counter = ""
        self.APS_etq_cluster = APS_etq_cluster = ""
        self.APS_etq_cabeceraExtendida = APS_etq_cabeceraExtendida = ""
        self.APS_etq_bloque = APS_etq_bloque = ""
        self.APS_etq_ack = APS_etq_ack = ""
        self.APS_endpointOrigen = APS_endpointOrigen = '1'
        self.APS_endpointDestino = APS_endpointDestino = '2'
        self.APS_cluster = APS_cluster = '0XABCD'
        self.APS_cabeceraExtendida = APS_cabeceraExtendida = False
        self.APS_bloque = APS_bloque = '0'
        self.APS_ack = APS_ack = '0x0'

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
        self._payload_tool_bar = Qt.QToolBar(self)
        self._payload_tool_bar.addWidget(Qt.QLabel("Carga"+": "))
        self._payload_line_edit = Qt.QLineEdit(str(self.payload))
        self._payload_tool_bar.addWidget(self._payload_line_edit)
        self._payload_line_edit.returnPressed.connect(
        	lambda: self.set_payload(str(str(self._payload_line_edit.text().toAscii()))))
        self.Tab_grid_layout_0 .addWidget(self._payload_tool_bar,  0,0,1,1)
        self.Tabtx = Qt.QTabWidget()
        self.Tabtx_widget_0 = Qt.QWidget()
        self.Tabtx_layout_0 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.Tabtx_widget_0)
        self.Tabtx_grid_layout_0 = Qt.QGridLayout()
        self.Tabtx_layout_0.addLayout(self.Tabtx_grid_layout_0)
        self.Tabtx.addTab(self.Tabtx_widget_0, 'MAC')
        self.Tabtx_widget_1 = Qt.QWidget()
        self.Tabtx_layout_1 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.Tabtx_widget_1)
        self.Tabtx_grid_layout_1 = Qt.QGridLayout()
        self.Tabtx_layout_1.addLayout(self.Tabtx_grid_layout_1)
        self.Tabtx.addTab(self.Tabtx_widget_1, 'NWK')
        self.Tabtx_widget_2 = Qt.QWidget()
        self.Tabtx_layout_2 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.Tabtx_widget_2)
        self.Tabtx_grid_layout_2 = Qt.QGridLayout()
        self.Tabtx_layout_2.addLayout(self.Tabtx_grid_layout_2)
        self.Tabtx.addTab(self.Tabtx_widget_2, 'APS')
        self.Tab_grid_layout_0 .addWidget(self.Tabtx,  1,0,1,1)
        self.Tabrx = Qt.QTabWidget()
        self.Tabrx_widget_0 = Qt.QWidget()
        self.Tabrx_layout_0 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.Tabrx_widget_0)
        self.Tabrx_grid_layout_0 = Qt.QGridLayout()
        self.Tabrx_layout_0.addLayout(self.Tabrx_grid_layout_0)
        self.Tabrx.addTab(self.Tabrx_widget_0, 'MAC')
        self.Tabrx_widget_1 = Qt.QWidget()
        self.Tabrx_layout_1 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.Tabrx_widget_1)
        self.Tabrx_grid_layout_1 = Qt.QGridLayout()
        self.Tabrx_layout_1.addLayout(self.Tabrx_grid_layout_1)
        self.Tabrx.addTab(self.Tabrx_widget_1, 'NWK')
        self.Tabrx_widget_2 = Qt.QWidget()
        self.Tabrx_layout_2 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.Tabrx_widget_2)
        self.Tabrx_grid_layout_2 = Qt.QGridLayout()
        self.Tabrx_layout_2.addLayout(self.Tabrx_grid_layout_2)
        self.Tabrx.addTab(self.Tabrx_widget_2, 'APS')
        self.Tab_grid_layout_1.addWidget(self.Tabrx,  1,0,1,4)
        self.tfg_NWK_stack_0 = tfg.NWK_stack(True, False)
        self.tfg_MAC_stack_0 = tfg.MAC_stack(True, False)
        self.tfg_Aplication_0 = tfg.Aplication()
        self.tfg_APS_stack_0 = tfg.APS_stack(True, False)
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
        self.Tab_grid_layout_0 .addWidget(_enviar_push_button,  99,0,1,3)
        self.blocks_file_sink_0 = blocks.file_sink(gr.sizeof_char*1, '/tmp/sdr.pcap', False)
        self.blocks_file_sink_0.set_unbuffered(True)
        self._NWK_tipoTrama_options = (0, 1, )
        self._NWK_tipoTrama_labels = ("Datos", "Comando", )
        self._NWK_tipoTrama_tool_bar = Qt.QToolBar(self)
        self._NWK_tipoTrama_tool_bar.addWidget(Qt.QLabel("Tipo de trama"+": "))
        self._NWK_tipoTrama_combo_box = Qt.QComboBox()
        self._NWK_tipoTrama_tool_bar.addWidget(self._NWK_tipoTrama_combo_box)
        for label in self._NWK_tipoTrama_labels: self._NWK_tipoTrama_combo_box.addItem(label)
        self._NWK_tipoTrama_callback = lambda i: Qt.QMetaObject.invokeMethod(self._NWK_tipoTrama_combo_box, "setCurrentIndex", Qt.Q_ARG("int", self._NWK_tipoTrama_options.index(i)))
        self._NWK_tipoTrama_callback(self.NWK_tipoTrama)
        self._NWK_tipoTrama_combo_box.currentIndexChanged.connect(
        	lambda i: self.set_NWK_tipoTrama(self._NWK_tipoTrama_options[i]))
        self.Tabtx_grid_layout_1.addWidget(self._NWK_tipoTrama_tool_bar,  0,0,1,3)
        _NWK_sourceRoute_check_box = Qt.QCheckBox("Source route")
        self._NWK_sourceRoute_choices = {True: True, False: False}
        self._NWK_sourceRoute_choices_inv = dict((v,k) for k,v in self._NWK_sourceRoute_choices.iteritems())
        self._NWK_sourceRoute_callback = lambda i: Qt.QMetaObject.invokeMethod(_NWK_sourceRoute_check_box, "setChecked", Qt.Q_ARG("bool", self._NWK_sourceRoute_choices_inv[i]))
        self._NWK_sourceRoute_callback(self.NWK_sourceRoute)
        _NWK_sourceRoute_check_box.stateChanged.connect(lambda i: self.set_NWK_sourceRoute(self._NWK_sourceRoute_choices[bool(i)]))
        self.Tabtx_grid_layout_1 .addWidget(_NWK_sourceRoute_check_box,  2,0,1,2)
        _NWK_seguridad_check_box = Qt.QCheckBox("Seguridad")
        self._NWK_seguridad_choices = {True: True, False: False}
        self._NWK_seguridad_choices_inv = dict((v,k) for k,v in self._NWK_seguridad_choices.iteritems())
        self._NWK_seguridad_callback = lambda i: Qt.QMetaObject.invokeMethod(_NWK_seguridad_check_box, "setChecked", Qt.Q_ARG("bool", self._NWK_seguridad_choices_inv[i]))
        self._NWK_seguridad_callback(self.NWK_seguridad)
        _NWK_seguridad_check_box.stateChanged.connect(lambda i: self.set_NWK_seguridad(self._NWK_seguridad_choices[bool(i)]))
        self.Tabtx_grid_layout_1 .addWidget(_NWK_seguridad_check_box,  1,4,1,2)
        self._NWK_radio_tool_bar = Qt.QToolBar(self)
        self._NWK_radio_tool_bar.addWidget(Qt.QLabel("Radio"+": "))
        self._NWK_radio_line_edit = Qt.QLineEdit(str(self.NWK_radio))
        self._NWK_radio_tool_bar.addWidget(self._NWK_radio_line_edit)
        self._NWK_radio_line_edit.returnPressed.connect(
        	lambda: self.set_NWK_radio(str(str(self._NWK_radio_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_1 .addWidget(self._NWK_radio_tool_bar,  5,4,1,2)
        self.NWK_msg_tipoTrama = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_tipoTrama')
        self._NWK_msg_tipoTrama_win = sip.wrapinstance(self.NWK_msg_tipoTrama.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_tipoTrama_win,  0,3,1,3)
        self.NWK_msg_sourceRoute = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_sourceRoute')
        self._NWK_msg_sourceRoute_win = sip.wrapinstance(self.NWK_msg_sourceRoute.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_sourceRoute_win,  2,9,1,3)
        self.NWK_msg_seguridad = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_seguridad')
        self._NWK_msg_seguridad_win = sip.wrapinstance(self.NWK_msg_seguridad.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_seguridad_win,  2,3,1,3)
        self.NWK_msg_radio = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_radio')
        self._NWK_msg_radio_win = sip.wrapinstance(self.NWK_msg_radio.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_radio_win,  5,3,1,3)
        self.NWK_msg_numSeq = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_numSeq')
        self._NWK_msg_numSeq_win = sip.wrapinstance(self.NWK_msg_numSeq.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_numSeq_win,  0,9,1,3)
        self.NWK_msg_multicast = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_multicast')
        self._NWK_msg_multicast_win = sip.wrapinstance(self.NWK_msg_multicast.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_multicast_win,  1,9,1,3)
        self.NWK_msg_modomulticast = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_modomulticast')
        self._NWK_msg_modomulticast_win = sip.wrapinstance(self.NWK_msg_modomulticast.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_modomulticast_win,  7,2,1,2)
        self.NWK_msg_mcastRadioMax = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_mcastRadioMax')
        self._NWK_msg_mcastRadioMax_win = sip.wrapinstance(self.NWK_msg_mcastRadioMax.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_mcastRadioMax_win,  7,10,1,2)
        self.NWK_msg_mcastRadio = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_mcastRadio')
        self._NWK_msg_mcastRadio_win = sip.wrapinstance(self.NWK_msg_mcastRadio.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_mcastRadio_win,  7,6,1,2)
        self.NWK_msg_ieeeSrce = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_ieeeSrce')
        self._NWK_msg_ieeeSrce_win = sip.wrapinstance(self.NWK_msg_ieeeSrce.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_ieeeSrce_win,  3,3,1,3)
        self.NWK_msg_ieeeDst = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_ieeeDst')
        self._NWK_msg_ieeeDst_win = sip.wrapinstance(self.NWK_msg_ieeeDst.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_ieeeDst_win,  3,9,1,3)
        self.NWK_msg_direccionesSR = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_direccionesSR')
        self._NWK_msg_direccionesSR_win = sip.wrapinstance(self.NWK_msg_direccionesSR.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_direccionesSR_win,  8,3,1,9)
        self.NWK_msg_dirOrigen = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_dirOrigen')
        self._NWK_msg_dirOrigen_win = sip.wrapinstance(self.NWK_msg_dirOrigen.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_dirOrigen_win,  4,3,1,3)
        self.NWK_msg_dirIeeeOrg = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_dirIeeeOrg')
        self._NWK_msg_dirIeeeOrg_win = sip.wrapinstance(self.NWK_msg_dirIeeeOrg.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_dirIeeeOrg_win,  6,3,1,3)
        self.NWK_msg_dirIeeeDst = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_dirIeeeDst')
        self._NWK_msg_dirIeeeDst_win = sip.wrapinstance(self.NWK_msg_dirIeeeDst.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_dirIeeeDst_win,  6,9,1,3)
        self.NWK_msg_dirDestino = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_dirDestino')
        self._NWK_msg_dirDestino_win = sip.wrapinstance(self.NWK_msg_dirDestino.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_dirDestino_win,  4,9,1,3)
        self.NWK_msg_descRuta = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'nwk_descRuta')
        self._NWK_msg_descRuta_win = sip.wrapinstance(self.NWK_msg_descRuta.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_msg_descRuta_win,  1,3,1,3)
        self._NWK_modoMulticast_options = (0, 1, )
        self._NWK_modoMulticast_labels = ("No miembro", "Miembro", )
        self._NWK_modoMulticast_tool_bar = Qt.QToolBar(self)
        self._NWK_modoMulticast_tool_bar.addWidget(Qt.QLabel("Multicast"+": "))
        self._NWK_modoMulticast_combo_box = Qt.QComboBox()
        self._NWK_modoMulticast_tool_bar.addWidget(self._NWK_modoMulticast_combo_box)
        for label in self._NWK_modoMulticast_labels: self._NWK_modoMulticast_combo_box.addItem(label)
        self._NWK_modoMulticast_callback = lambda i: Qt.QMetaObject.invokeMethod(self._NWK_modoMulticast_combo_box, "setCurrentIndex", Qt.Q_ARG("int", self._NWK_modoMulticast_options.index(i)))
        self._NWK_modoMulticast_callback(self.NWK_modoMulticast)
        self._NWK_modoMulticast_combo_box.currentIndexChanged.connect(
        	lambda i: self.set_NWK_modoMulticast(self._NWK_modoMulticast_options[i]))
        self.Tabtx_grid_layout_1 .addWidget(self._NWK_modoMulticast_tool_bar,  7,0,1,2)
        self._NWK_mcastRadioMax_tool_bar = Qt.QToolBar(self)
        self._NWK_mcastRadioMax_tool_bar.addWidget(Qt.QLabel("Radio mcast max"+": "))
        self._NWK_mcastRadioMax_line_edit = Qt.QLineEdit(str(self.NWK_mcastRadioMax))
        self._NWK_mcastRadioMax_tool_bar.addWidget(self._NWK_mcastRadioMax_line_edit)
        self._NWK_mcastRadioMax_line_edit.returnPressed.connect(
        	lambda: self.set_NWK_mcastRadioMax(str(str(self._NWK_mcastRadioMax_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_1 .addWidget(self._NWK_mcastRadioMax_tool_bar,  7,4,1,2)
        self._NWK_mcastRadio_tool_bar = Qt.QToolBar(self)
        self._NWK_mcastRadio_tool_bar.addWidget(Qt.QLabel("Radio mcast"+": "))
        self._NWK_mcastRadio_line_edit = Qt.QLineEdit(str(self.NWK_mcastRadio))
        self._NWK_mcastRadio_tool_bar.addWidget(self._NWK_mcastRadio_line_edit)
        self._NWK_mcastRadio_line_edit.returnPressed.connect(
        	lambda: self.set_NWK_mcastRadio(str(str(self._NWK_mcastRadio_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_1 .addWidget(self._NWK_mcastRadio_tool_bar,  7,2,1,2)
        _NWK_ieeeSrc_check_box = Qt.QCheckBox("IEEE origen")
        self._NWK_ieeeSrc_choices = {True: True, False: False}
        self._NWK_ieeeSrc_choices_inv = dict((v,k) for k,v in self._NWK_ieeeSrc_choices.iteritems())
        self._NWK_ieeeSrc_callback = lambda i: Qt.QMetaObject.invokeMethod(_NWK_ieeeSrc_check_box, "setChecked", Qt.Q_ARG("bool", self._NWK_ieeeSrc_choices_inv[i]))
        self._NWK_ieeeSrc_callback(self.NWK_ieeeSrc)
        _NWK_ieeeSrc_check_box.stateChanged.connect(lambda i: self.set_NWK_ieeeSrc(self._NWK_ieeeSrc_choices[bool(i)]))
        self.Tabtx_grid_layout_1 .addWidget(_NWK_ieeeSrc_check_box,  2,2,1,2)
        _NWK_ieeeDst_check_box = Qt.QCheckBox("IEEE destino")
        self._NWK_ieeeDst_choices = {True: True, False: False}
        self._NWK_ieeeDst_choices_inv = dict((v,k) for k,v in self._NWK_ieeeDst_choices.iteritems())
        self._NWK_ieeeDst_callback = lambda i: Qt.QMetaObject.invokeMethod(_NWK_ieeeDst_check_box, "setChecked", Qt.Q_ARG("bool", self._NWK_ieeeDst_choices_inv[i]))
        self._NWK_ieeeDst_callback(self.NWK_ieeeDst)
        _NWK_ieeeDst_check_box.stateChanged.connect(lambda i: self.set_NWK_ieeeDst(self._NWK_ieeeDst_choices[bool(i)]))
        self.Tabtx_grid_layout_1 .addWidget(_NWK_ieeeDst_check_box,  2,4,1,2)
        self._NWK_etq_tipoTrama_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_tipoTrama_formatter = None
        else:
          self._NWK_etq_tipoTrama_formatter = lambda x: x
        
        self._NWK_etq_tipoTrama_tool_bar.addWidget(Qt.QLabel("Tipo trama"+": "))
        self._NWK_etq_tipoTrama_label = Qt.QLabel(str(self._NWK_etq_tipoTrama_formatter(self.NWK_etq_tipoTrama)))
        self._NWK_etq_tipoTrama_tool_bar.addWidget(self._NWK_etq_tipoTrama_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_tipoTrama_tool_bar,  0,0,1,3)
          
        self._NWK_etq_sourceRoute_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_sourceRoute_formatter = None
        else:
          self._NWK_etq_sourceRoute_formatter = lambda x: x
        
        self._NWK_etq_sourceRoute_tool_bar.addWidget(Qt.QLabel("Source route"+": "))
        self._NWK_etq_sourceRoute_label = Qt.QLabel(str(self._NWK_etq_sourceRoute_formatter(self.NWK_etq_sourceRoute)))
        self._NWK_etq_sourceRoute_tool_bar.addWidget(self._NWK_etq_sourceRoute_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_sourceRoute_tool_bar,  2,6,1,3)
          
        self._NWK_etq_seguridad_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_seguridad_formatter = None
        else:
          self._NWK_etq_seguridad_formatter = lambda x: x
        
        self._NWK_etq_seguridad_tool_bar.addWidget(Qt.QLabel("Seguridad"+": "))
        self._NWK_etq_seguridad_label = Qt.QLabel(str(self._NWK_etq_seguridad_formatter(self.NWK_etq_seguridad)))
        self._NWK_etq_seguridad_tool_bar.addWidget(self._NWK_etq_seguridad_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_seguridad_tool_bar,  2,0,1,3)
          
        self._NWK_etq_radio_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_radio_formatter = None
        else:
          self._NWK_etq_radio_formatter = lambda x: x
        
        self._NWK_etq_radio_tool_bar.addWidget(Qt.QLabel("Radio"+": "))
        self._NWK_etq_radio_label = Qt.QLabel(str(self._NWK_etq_radio_formatter(self.NWK_etq_radio)))
        self._NWK_etq_radio_tool_bar.addWidget(self._NWK_etq_radio_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_radio_tool_bar,  5,0,1,3)
          
        self._NWK_etq_numSeq_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_numSeq_formatter = None
        else:
          self._NWK_etq_numSeq_formatter = lambda x: x
        
        self._NWK_etq_numSeq_tool_bar.addWidget(Qt.QLabel("Numero de secuecia"+": "))
        self._NWK_etq_numSeq_label = Qt.QLabel(str(self._NWK_etq_numSeq_formatter(self.NWK_etq_numSeq)))
        self._NWK_etq_numSeq_tool_bar.addWidget(self._NWK_etq_numSeq_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_numSeq_tool_bar,  0,6,1,3)
          
        self._NWK_etq_multicast_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_multicast_formatter = None
        else:
          self._NWK_etq_multicast_formatter = lambda x: x
        
        self._NWK_etq_multicast_tool_bar.addWidget(Qt.QLabel("Multicast"+": "))
        self._NWK_etq_multicast_label = Qt.QLabel(str(self._NWK_etq_multicast_formatter(self.NWK_etq_multicast)))
        self._NWK_etq_multicast_tool_bar.addWidget(self._NWK_etq_multicast_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_multicast_tool_bar,  1,6,1,3)
          
        self._NWK_etq_modomulticast_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_modomulticast_formatter = None
        else:
          self._NWK_etq_modomulticast_formatter = lambda x: x
        
        self._NWK_etq_modomulticast_tool_bar.addWidget(Qt.QLabel("Multicast"+": "))
        self._NWK_etq_modomulticast_label = Qt.QLabel(str(self._NWK_etq_modomulticast_formatter(self.NWK_etq_modomulticast)))
        self._NWK_etq_modomulticast_tool_bar.addWidget(self._NWK_etq_modomulticast_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_modomulticast_tool_bar,  7,0,1,2)
          
        self._NWK_etq_mcastRadioMax_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_mcastRadioMax_formatter = None
        else:
          self._NWK_etq_mcastRadioMax_formatter = lambda x: x
        
        self._NWK_etq_mcastRadioMax_tool_bar.addWidget(Qt.QLabel("Radio mcast max"+": "))
        self._NWK_etq_mcastRadioMax_label = Qt.QLabel(str(self._NWK_etq_mcastRadioMax_formatter(self.NWK_etq_mcastRadioMax)))
        self._NWK_etq_mcastRadioMax_tool_bar.addWidget(self._NWK_etq_mcastRadioMax_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_mcastRadioMax_tool_bar,  7,8,1,2)
          
        self._NWK_etq_mcastRadio_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_mcastRadio_formatter = None
        else:
          self._NWK_etq_mcastRadio_formatter = lambda x: x
        
        self._NWK_etq_mcastRadio_tool_bar.addWidget(Qt.QLabel("Radio mcast"+": "))
        self._NWK_etq_mcastRadio_label = Qt.QLabel(str(self._NWK_etq_mcastRadio_formatter(self.NWK_etq_mcastRadio)))
        self._NWK_etq_mcastRadio_tool_bar.addWidget(self._NWK_etq_mcastRadio_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_mcastRadio_tool_bar,  7,4,1,2)
          
        self._NWK_etq_ieeeSrc_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_ieeeSrc_formatter = None
        else:
          self._NWK_etq_ieeeSrc_formatter = lambda x: x
        
        self._NWK_etq_ieeeSrc_tool_bar.addWidget(Qt.QLabel("IEEE origen"+": "))
        self._NWK_etq_ieeeSrc_label = Qt.QLabel(str(self._NWK_etq_ieeeSrc_formatter(self.NWK_etq_ieeeSrc)))
        self._NWK_etq_ieeeSrc_tool_bar.addWidget(self._NWK_etq_ieeeSrc_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_ieeeSrc_tool_bar,  3,0,1,3)
          
        self._NWK_etq_ieeeDst_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_ieeeDst_formatter = None
        else:
          self._NWK_etq_ieeeDst_formatter = lambda x: x
        
        self._NWK_etq_ieeeDst_tool_bar.addWidget(Qt.QLabel("IEEE destino"+": "))
        self._NWK_etq_ieeeDst_label = Qt.QLabel(str(self._NWK_etq_ieeeDst_formatter(self.NWK_etq_ieeeDst)))
        self._NWK_etq_ieeeDst_tool_bar.addWidget(self._NWK_etq_ieeeDst_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_ieeeDst_tool_bar,  3,6,1,3)
          
        self._NWK_etq_direccionesSR_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_direccionesSR_formatter = None
        else:
          self._NWK_etq_direccionesSR_formatter = lambda x: x
        
        self._NWK_etq_direccionesSR_tool_bar.addWidget(Qt.QLabel("Source route"+": "))
        self._NWK_etq_direccionesSR_label = Qt.QLabel(str(self._NWK_etq_direccionesSR_formatter(self.NWK_etq_direccionesSR)))
        self._NWK_etq_direccionesSR_tool_bar.addWidget(self._NWK_etq_direccionesSR_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_direccionesSR_tool_bar,  8,0,1,3)
          
        self._NWK_etq_dirOrigen_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_dirOrigen_formatter = None
        else:
          self._NWK_etq_dirOrigen_formatter = lambda x: x
        
        self._NWK_etq_dirOrigen_tool_bar.addWidget(Qt.QLabel("Direccion origen"+": "))
        self._NWK_etq_dirOrigen_label = Qt.QLabel(str(self._NWK_etq_dirOrigen_formatter(self.NWK_etq_dirOrigen)))
        self._NWK_etq_dirOrigen_tool_bar.addWidget(self._NWK_etq_dirOrigen_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_dirOrigen_tool_bar,  4,0,1,3)
          
        self._NWK_etq_dirIeeeOrg_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_dirIeeeOrg_formatter = None
        else:
          self._NWK_etq_dirIeeeOrg_formatter = lambda x: x
        
        self._NWK_etq_dirIeeeOrg_tool_bar.addWidget(Qt.QLabel("IEEE origen"+": "))
        self._NWK_etq_dirIeeeOrg_label = Qt.QLabel(str(self._NWK_etq_dirIeeeOrg_formatter(self.NWK_etq_dirIeeeOrg)))
        self._NWK_etq_dirIeeeOrg_tool_bar.addWidget(self._NWK_etq_dirIeeeOrg_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_dirIeeeOrg_tool_bar,  6,0,1,3)
          
        self._NWK_etq_dirIeeeDst_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_dirIeeeDst_formatter = None
        else:
          self._NWK_etq_dirIeeeDst_formatter = lambda x: x
        
        self._NWK_etq_dirIeeeDst_tool_bar.addWidget(Qt.QLabel("IEEE destino"+": "))
        self._NWK_etq_dirIeeeDst_label = Qt.QLabel(str(self._NWK_etq_dirIeeeDst_formatter(self.NWK_etq_dirIeeeDst)))
        self._NWK_etq_dirIeeeDst_tool_bar.addWidget(self._NWK_etq_dirIeeeDst_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_dirIeeeDst_tool_bar,  6,6,1,3)
          
        self._NWK_etq_dirDestino_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_dirDestino_formatter = None
        else:
          self._NWK_etq_dirDestino_formatter = lambda x: x
        
        self._NWK_etq_dirDestino_tool_bar.addWidget(Qt.QLabel("Direccion destino"+": "))
        self._NWK_etq_dirDestino_label = Qt.QLabel(str(self._NWK_etq_dirDestino_formatter(self.NWK_etq_dirDestino)))
        self._NWK_etq_dirDestino_tool_bar.addWidget(self._NWK_etq_dirDestino_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_dirDestino_tool_bar,  4,6,1,3)
          
        self._NWK_etq_descRuta_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._NWK_etq_descRuta_formatter = None
        else:
          self._NWK_etq_descRuta_formatter = lambda x: x
        
        self._NWK_etq_descRuta_tool_bar.addWidget(Qt.QLabel("Descubrimiento ruta"+": "))
        self._NWK_etq_descRuta_label = Qt.QLabel(str(self._NWK_etq_descRuta_formatter(self.NWK_etq_descRuta)))
        self._NWK_etq_descRuta_tool_bar.addWidget(self._NWK_etq_descRuta_label)
        self.Tabrx_grid_layout_1 .addWidget(self._NWK_etq_descRuta_tool_bar,  1,0,1,3)
          
        self._NWK_direccionesSR_tool_bar = Qt.QToolBar(self)
        self._NWK_direccionesSR_tool_bar.addWidget(Qt.QLabel("Source route"+": "))
        self._NWK_direccionesSR_line_edit = Qt.QLineEdit(str(self.NWK_direccionesSR))
        self._NWK_direccionesSR_tool_bar.addWidget(self._NWK_direccionesSR_line_edit)
        self._NWK_direccionesSR_line_edit.returnPressed.connect(
        	lambda: self.set_NWK_direccionesSR(str(str(self._NWK_direccionesSR_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_1 .addWidget(self._NWK_direccionesSR_tool_bar,  8,0,1,6)
        self._NWK_dirOrigen_tool_bar = Qt.QToolBar(self)
        self._NWK_dirOrigen_tool_bar.addWidget(Qt.QLabel("Direccion origen"+": "))
        self._NWK_dirOrigen_line_edit = Qt.QLineEdit(str(self.NWK_dirOrigen))
        self._NWK_dirOrigen_tool_bar.addWidget(self._NWK_dirOrigen_line_edit)
        self._NWK_dirOrigen_line_edit.returnPressed.connect(
        	lambda: self.set_NWK_dirOrigen(str(str(self._NWK_dirOrigen_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_1 .addWidget(self._NWK_dirOrigen_tool_bar,  5,0,1,2)
        self._NWK_dirIEEESrc_tool_bar = Qt.QToolBar(self)
        self._NWK_dirIEEESrc_tool_bar.addWidget(Qt.QLabel("IEEE origen"+": "))
        self._NWK_dirIEEESrc_line_edit = Qt.QLineEdit(str(self.NWK_dirIEEESrc))
        self._NWK_dirIEEESrc_tool_bar.addWidget(self._NWK_dirIEEESrc_line_edit)
        self._NWK_dirIEEESrc_line_edit.returnPressed.connect(
        	lambda: self.set_NWK_dirIEEESrc(str(str(self._NWK_dirIEEESrc_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_1 .addWidget(self._NWK_dirIEEESrc_tool_bar,  6,0,1,3)
        self._NWK_dirIEEEDst_tool_bar = Qt.QToolBar(self)
        self._NWK_dirIEEEDst_tool_bar.addWidget(Qt.QLabel("IEEE destino"+": "))
        self._NWK_dirIEEEDst_line_edit = Qt.QLineEdit(str(self.NWK_dirIEEEDst))
        self._NWK_dirIEEEDst_tool_bar.addWidget(self._NWK_dirIEEEDst_line_edit)
        self._NWK_dirIEEEDst_line_edit.returnPressed.connect(
        	lambda: self.set_NWK_dirIEEEDst(str(str(self._NWK_dirIEEEDst_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_1 .addWidget(self._NWK_dirIEEEDst_tool_bar,  6,3,1,3)
        self._NWK_dirDestino_tool_bar = Qt.QToolBar(self)
        self._NWK_dirDestino_tool_bar.addWidget(Qt.QLabel("Direccion destino"+": "))
        self._NWK_dirDestino_line_edit = Qt.QLineEdit(str(self.NWK_dirDestino))
        self._NWK_dirDestino_tool_bar.addWidget(self._NWK_dirDestino_line_edit)
        self._NWK_dirDestino_line_edit.returnPressed.connect(
        	lambda: self.set_NWK_dirDestino(str(str(self._NWK_dirDestino_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_1 .addWidget(self._NWK_dirDestino_tool_bar,  5,2,1,2)
        _NWK_descRuta_check_box = Qt.QCheckBox("Descubrimiento de ruta")
        self._NWK_descRuta_choices = {True: True, False: False}
        self._NWK_descRuta_choices_inv = dict((v,k) for k,v in self._NWK_descRuta_choices.iteritems())
        self._NWK_descRuta_callback = lambda i: Qt.QMetaObject.invokeMethod(_NWK_descRuta_check_box, "setChecked", Qt.Q_ARG("bool", self._NWK_descRuta_choices_inv[i]))
        self._NWK_descRuta_callback(self.NWK_descRuta)
        _NWK_descRuta_check_box.stateChanged.connect(lambda i: self.set_NWK_descRuta(self._NWK_descRuta_choices[bool(i)]))
        self.Tabtx_grid_layout_1 .addWidget(_NWK_descRuta_check_box,  1,0,1,2)
        _NWK_Multicast_check_box = Qt.QCheckBox("Multicast")
        self._NWK_Multicast_choices = {True: True, False: False}
        self._NWK_Multicast_choices_inv = dict((v,k) for k,v in self._NWK_Multicast_choices.iteritems())
        self._NWK_Multicast_callback = lambda i: Qt.QMetaObject.invokeMethod(_NWK_Multicast_check_box, "setChecked", Qt.Q_ARG("bool", self._NWK_Multicast_choices_inv[i]))
        self._NWK_Multicast_callback(self.NWK_Multicast)
        _NWK_Multicast_check_box.stateChanged.connect(lambda i: self.set_NWK_Multicast(self._NWK_Multicast_choices[bool(i)]))
        self.Tabtx_grid_layout_1 .addWidget(_NWK_Multicast_check_box,  1,2,1,2)
        _MAC_tramaPendiente_check_box = Qt.QCheckBox("Trama pendiente")
        self._MAC_tramaPendiente_choices = {True: True, False: False}
        self._MAC_tramaPendiente_choices_inv = dict((v,k) for k,v in self._MAC_tramaPendiente_choices.iteritems())
        self._MAC_tramaPendiente_callback = lambda i: Qt.QMetaObject.invokeMethod(_MAC_tramaPendiente_check_box, "setChecked", Qt.Q_ARG("bool", self._MAC_tramaPendiente_choices_inv[i]))
        self._MAC_tramaPendiente_callback(self.MAC_tramaPendiente)
        _MAC_tramaPendiente_check_box.stateChanged.connect(lambda i: self.set_MAC_tramaPendiente(self._MAC_tramaPendiente_choices[bool(i)]))
        self.Tabtx_grid_layout_0 .addWidget(_MAC_tramaPendiente_check_box,  1,1,1,1)
        self._MAC_tipoTrama_options = (0, 1, 2, 3, )
        self._MAC_tipoTrama_labels = ("Beacon", "Datos", "ACK", "Comando MAC", )
        self._MAC_tipoTrama_tool_bar = Qt.QToolBar(self)
        self._MAC_tipoTrama_tool_bar.addWidget(Qt.QLabel("Tipo de trama"+": "))
        self._MAC_tipoTrama_combo_box = Qt.QComboBox()
        self._MAC_tipoTrama_tool_bar.addWidget(self._MAC_tipoTrama_combo_box)
        for label in self._MAC_tipoTrama_labels: self._MAC_tipoTrama_combo_box.addItem(label)
        self._MAC_tipoTrama_callback = lambda i: Qt.QMetaObject.invokeMethod(self._MAC_tipoTrama_combo_box, "setCurrentIndex", Qt.Q_ARG("int", self._MAC_tipoTrama_options.index(i)))
        self._MAC_tipoTrama_callback(self.MAC_tipoTrama)
        self._MAC_tipoTrama_combo_box.currentIndexChanged.connect(
        	lambda i: self.set_MAC_tipoTrama(self._MAC_tipoTrama_options[i]))
        self.Tabtx_grid_layout_0 .addWidget(self._MAC_tipoTrama_tool_bar,  0,0,1,1)
        _MAC_seguridad_check_box = Qt.QCheckBox("Seguridad")
        self._MAC_seguridad_choices = {True: True, False: False}
        self._MAC_seguridad_choices_inv = dict((v,k) for k,v in self._MAC_seguridad_choices.iteritems())
        self._MAC_seguridad_callback = lambda i: Qt.QMetaObject.invokeMethod(_MAC_seguridad_check_box, "setChecked", Qt.Q_ARG("bool", self._MAC_seguridad_choices_inv[i]))
        self._MAC_seguridad_callback(self.MAC_seguridad)
        _MAC_seguridad_check_box.stateChanged.connect(lambda i: self.set_MAC_seguridad(self._MAC_seguridad_choices[bool(i)]))
        self.Tabtx_grid_layout_0 .addWidget(_MAC_seguridad_check_box,  1,0,1,1)
        _MAC_reqACK_check_box = Qt.QCheckBox("Solicita ACK")
        self._MAC_reqACK_choices = {True: True, False: False}
        self._MAC_reqACK_choices_inv = dict((v,k) for k,v in self._MAC_reqACK_choices.iteritems())
        self._MAC_reqACK_callback = lambda i: Qt.QMetaObject.invokeMethod(_MAC_reqACK_check_box, "setChecked", Qt.Q_ARG("bool", self._MAC_reqACK_choices_inv[i]))
        self._MAC_reqACK_callback(self.MAC_reqACK)
        _MAC_reqACK_check_box.stateChanged.connect(lambda i: self.set_MAC_reqACK(self._MAC_reqACK_choices[bool(i)]))
        self.Tabtx_grid_layout_0 .addWidget(_MAC_reqACK_check_box,  2,0,1,1)
        self._MAC_panOrigen_tool_bar = Qt.QToolBar(self)
        self._MAC_panOrigen_tool_bar.addWidget(Qt.QLabel("PAN origen"+": "))
        self._MAC_panOrigen_line_edit = Qt.QLineEdit(str(self.MAC_panOrigen))
        self._MAC_panOrigen_tool_bar.addWidget(self._MAC_panOrigen_line_edit)
        self._MAC_panOrigen_line_edit.returnPressed.connect(
        	lambda: self.set_MAC_panOrigen(str(str(self._MAC_panOrigen_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_0 .addWidget(self._MAC_panOrigen_tool_bar,  4,0,1,1)
        self._MAC_panDestino_tool_bar = Qt.QToolBar(self)
        self._MAC_panDestino_tool_bar.addWidget(Qt.QLabel("PAN destino"+": "))
        self._MAC_panDestino_line_edit = Qt.QLineEdit(str(self.MAC_panDestino))
        self._MAC_panDestino_tool_bar.addWidget(self._MAC_panDestino_line_edit)
        self._MAC_panDestino_line_edit.returnPressed.connect(
        	lambda: self.set_MAC_panDestino(str(str(self._MAC_panDestino_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_0 .addWidget(self._MAC_panDestino_tool_bar,  4,1,1,1)
        self.MAC_msg_tramaPendiente = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_tramaPendiente')
        self._MAC_msg_tramaPendiente_win = sip.wrapinstance(self.MAC_msg_tramaPendiente.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_tramaPendiente_win,  1,3,1,1)
        self.MAC_msg_tipoTrama = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_tipoTrama')
        self._MAC_msg_tipoTrama_win = sip.wrapinstance(self.MAC_msg_tipoTrama.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_tipoTrama_win,  0,1,1,1)
        self.MAC_msg_seguridad = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_seguridad')
        self._MAC_msg_seguridad_win = sip.wrapinstance(self.MAC_msg_seguridad.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_seguridad_win,  1,1,1,1)
        self.MAC_msg_reqACK = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_reqACK')
        self._MAC_msg_reqACK_win = sip.wrapinstance(self.MAC_msg_reqACK.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_reqACK_win,  2,1,1,1)
        self.MAC_msg_payload = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'payload')
        self._MAC_msg_payload_win = sip.wrapinstance(self.MAC_msg_payload.pyqwidget(), Qt.QWidget)
        self.Tab_grid_layout_1 .addWidget(self._MAC_msg_payload_win,  0,1,1,3)
        self.MAC_msg_panOrigen = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_panOrigen')
        self._MAC_msg_panOrigen_win = sip.wrapinstance(self.MAC_msg_panOrigen.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_panOrigen_win,  4,1,1,1)
        self.MAC_msg_panDestino = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_panDestino')
        self._MAC_msg_panDestino_win = sip.wrapinstance(self.MAC_msg_panDestino.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_panDestino_win,  4,3,1,1)
        self.MAC_msg_numSeq = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_numSeq')
        self._MAC_msg_numSeq_win = sip.wrapinstance(self.MAC_msg_numSeq.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_numSeq_win,  0,3,1,1)
        self.MAC_msg_modoSrc = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_modoSrc')
        self._MAC_msg_modoSrc_win = sip.wrapinstance(self.MAC_msg_modoSrc.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_modoSrc_win,  3,1,1,1)
        self.MAC_msg_modoDest = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_modoDest')
        self._MAC_msg_modoDest_win = sip.wrapinstance(self.MAC_msg_modoDest.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_modoDest_win,  3,3,1,1)
        self.MAC_msg_intraPAN = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_intrapan')
        self._MAC_msg_intraPAN_win = sip.wrapinstance(self.MAC_msg_intraPAN.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_intraPAN_win,  2,3,1,1)
        self.MAC_msg_dirOrigen = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_dirOrigen')
        self._MAC_msg_dirOrigen_win = sip.wrapinstance(self.MAC_msg_dirOrigen.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_dirOrigen_win,  5,1,1,1)
        self.MAC_msg_dirDestino = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'mac_dirDestino')
        self._MAC_msg_dirDestino_win = sip.wrapinstance(self.MAC_msg_dirDestino.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_msg_dirDestino_win,  5,3,1,1)
        self._MAC_modoSrc_options = (0, 1, 2, )
        self._MAC_modoSrc_labels = ("Desactivada", "Direccion corta", "Direccion larga", )
        self._MAC_modoSrc_tool_bar = Qt.QToolBar(self)
        self._MAC_modoSrc_tool_bar.addWidget(Qt.QLabel("Modo direc origen"+": "))
        self._MAC_modoSrc_combo_box = Qt.QComboBox()
        self._MAC_modoSrc_tool_bar.addWidget(self._MAC_modoSrc_combo_box)
        for label in self._MAC_modoSrc_labels: self._MAC_modoSrc_combo_box.addItem(label)
        self._MAC_modoSrc_callback = lambda i: Qt.QMetaObject.invokeMethod(self._MAC_modoSrc_combo_box, "setCurrentIndex", Qt.Q_ARG("int", self._MAC_modoSrc_options.index(i)))
        self._MAC_modoSrc_callback(self.MAC_modoSrc)
        self._MAC_modoSrc_combo_box.currentIndexChanged.connect(
        	lambda i: self.set_MAC_modoSrc(self._MAC_modoSrc_options[i]))
        self.Tabtx_grid_layout_0 .addWidget(self._MAC_modoSrc_tool_bar,  3,0,1,1)
        self._MAC_modoDest_options = (0, 1, 2, )
        self._MAC_modoDest_labels = ("Desactivada", "Direccion corta", "Direccion larga", )
        self._MAC_modoDest_tool_bar = Qt.QToolBar(self)
        self._MAC_modoDest_tool_bar.addWidget(Qt.QLabel("Modo direc destino"+": "))
        self._MAC_modoDest_combo_box = Qt.QComboBox()
        self._MAC_modoDest_tool_bar.addWidget(self._MAC_modoDest_combo_box)
        for label in self._MAC_modoDest_labels: self._MAC_modoDest_combo_box.addItem(label)
        self._MAC_modoDest_callback = lambda i: Qt.QMetaObject.invokeMethod(self._MAC_modoDest_combo_box, "setCurrentIndex", Qt.Q_ARG("int", self._MAC_modoDest_options.index(i)))
        self._MAC_modoDest_callback(self.MAC_modoDest)
        self._MAC_modoDest_combo_box.currentIndexChanged.connect(
        	lambda i: self.set_MAC_modoDest(self._MAC_modoDest_options[i]))
        self.Tabtx_grid_layout_0 .addWidget(self._MAC_modoDest_tool_bar,  3,1,1,1)
        _MAC_intraPAN_check_box = Qt.QCheckBox("IntraPAN")
        self._MAC_intraPAN_choices = {True: True, False: False}
        self._MAC_intraPAN_choices_inv = dict((v,k) for k,v in self._MAC_intraPAN_choices.iteritems())
        self._MAC_intraPAN_callback = lambda i: Qt.QMetaObject.invokeMethod(_MAC_intraPAN_check_box, "setChecked", Qt.Q_ARG("bool", self._MAC_intraPAN_choices_inv[i]))
        self._MAC_intraPAN_callback(self.MAC_intraPAN)
        _MAC_intraPAN_check_box.stateChanged.connect(lambda i: self.set_MAC_intraPAN(self._MAC_intraPAN_choices[bool(i)]))
        self.Tabtx_grid_layout_0 .addWidget(_MAC_intraPAN_check_box,  2,1,1,1)
        self._MAC_etq_tramaPendiente_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_tramaPendiente_formatter = None
        else:
          self._MAC_etq_tramaPendiente_formatter = lambda x: x
        
        self._MAC_etq_tramaPendiente_tool_bar.addWidget(Qt.QLabel("Trama pendiente"+": "))
        self._MAC_etq_tramaPendiente_label = Qt.QLabel(str(self._MAC_etq_tramaPendiente_formatter(self.MAC_etq_tramaPendiente)))
        self._MAC_etq_tramaPendiente_tool_bar.addWidget(self._MAC_etq_tramaPendiente_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_tramaPendiente_tool_bar,  1,2,1,1)
          
        self._MAC_etq_tipoTrama_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_tipoTrama_formatter = None
        else:
          self._MAC_etq_tipoTrama_formatter = lambda x: x
        
        self._MAC_etq_tipoTrama_tool_bar.addWidget(Qt.QLabel("Tipo de trama"+": "))
        self._MAC_etq_tipoTrama_label = Qt.QLabel(str(self._MAC_etq_tipoTrama_formatter(self.MAC_etq_tipoTrama)))
        self._MAC_etq_tipoTrama_tool_bar.addWidget(self._MAC_etq_tipoTrama_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_tipoTrama_tool_bar,  0,0,1,1)
          
        self._MAC_etq_seguridad_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_seguridad_formatter = None
        else:
          self._MAC_etq_seguridad_formatter = lambda x: x
        
        self._MAC_etq_seguridad_tool_bar.addWidget(Qt.QLabel("Seguridad"+": "))
        self._MAC_etq_seguridad_label = Qt.QLabel(str(self._MAC_etq_seguridad_formatter(self.MAC_etq_seguridad)))
        self._MAC_etq_seguridad_tool_bar.addWidget(self._MAC_etq_seguridad_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_seguridad_tool_bar,  1,0,1,1)
          
        self._MAC_etq_reqACK_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_reqACK_formatter = None
        else:
          self._MAC_etq_reqACK_formatter = lambda x: x
        
        self._MAC_etq_reqACK_tool_bar.addWidget(Qt.QLabel("Solicita ACK"+": "))
        self._MAC_etq_reqACK_label = Qt.QLabel(str(self._MAC_etq_reqACK_formatter(self.MAC_etq_reqACK)))
        self._MAC_etq_reqACK_tool_bar.addWidget(self._MAC_etq_reqACK_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_reqACK_tool_bar,  2,0,1,1)
          
        self._MAC_etq_payload_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_payload_formatter = None
        else:
          self._MAC_etq_payload_formatter = lambda x: x
        
        self._MAC_etq_payload_tool_bar.addWidget(Qt.QLabel("Carga"+": "))
        self._MAC_etq_payload_label = Qt.QLabel(str(self._MAC_etq_payload_formatter(self.MAC_etq_payload)))
        self._MAC_etq_payload_tool_bar.addWidget(self._MAC_etq_payload_label)
        self.Tab_grid_layout_1 .addWidget(self._MAC_etq_payload_tool_bar,  0,0,1,1)
          
        self._MAC_etq_panOrigen_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_panOrigen_formatter = None
        else:
          self._MAC_etq_panOrigen_formatter = lambda x: x
        
        self._MAC_etq_panOrigen_tool_bar.addWidget(Qt.QLabel("PAN origen"+": "))
        self._MAC_etq_panOrigen_label = Qt.QLabel(str(self._MAC_etq_panOrigen_formatter(self.MAC_etq_panOrigen)))
        self._MAC_etq_panOrigen_tool_bar.addWidget(self._MAC_etq_panOrigen_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_panOrigen_tool_bar,  4,0,1,1)
          
        self._MAC_etq_panDestino_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_panDestino_formatter = None
        else:
          self._MAC_etq_panDestino_formatter = lambda x: x
        
        self._MAC_etq_panDestino_tool_bar.addWidget(Qt.QLabel("PAN destino"+": "))
        self._MAC_etq_panDestino_label = Qt.QLabel(str(self._MAC_etq_panDestino_formatter(self.MAC_etq_panDestino)))
        self._MAC_etq_panDestino_tool_bar.addWidget(self._MAC_etq_panDestino_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_panDestino_tool_bar,  4,2,1,1)
          
        self._MAC_etq_numSeq_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_numSeq_formatter = None
        else:
          self._MAC_etq_numSeq_formatter = lambda x: x
        
        self._MAC_etq_numSeq_tool_bar.addWidget(Qt.QLabel("Num de secuencia"+": "))
        self._MAC_etq_numSeq_label = Qt.QLabel(str(self._MAC_etq_numSeq_formatter(self.MAC_etq_numSeq)))
        self._MAC_etq_numSeq_tool_bar.addWidget(self._MAC_etq_numSeq_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_numSeq_tool_bar,  0,2,1,1)
          
        self._MAC_etq_modoSrc_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_modoSrc_formatter = None
        else:
          self._MAC_etq_modoSrc_formatter = lambda x: x
        
        self._MAC_etq_modoSrc_tool_bar.addWidget(Qt.QLabel("Modo (origen)"+": "))
        self._MAC_etq_modoSrc_label = Qt.QLabel(str(self._MAC_etq_modoSrc_formatter(self.MAC_etq_modoSrc)))
        self._MAC_etq_modoSrc_tool_bar.addWidget(self._MAC_etq_modoSrc_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_modoSrc_tool_bar,  3,0,1,1)
          
        self._MAC_etq_modoDest_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_modoDest_formatter = None
        else:
          self._MAC_etq_modoDest_formatter = lambda x: x
        
        self._MAC_etq_modoDest_tool_bar.addWidget(Qt.QLabel("Modo (destino)"+": "))
        self._MAC_etq_modoDest_label = Qt.QLabel(str(self._MAC_etq_modoDest_formatter(self.MAC_etq_modoDest)))
        self._MAC_etq_modoDest_tool_bar.addWidget(self._MAC_etq_modoDest_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_modoDest_tool_bar,  3,2,1,1)
          
        self._MAC_etq_intraPAN_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_intraPAN_formatter = None
        else:
          self._MAC_etq_intraPAN_formatter = lambda x: x
        
        self._MAC_etq_intraPAN_tool_bar.addWidget(Qt.QLabel("IntraPAN"+": "))
        self._MAC_etq_intraPAN_label = Qt.QLabel(str(self._MAC_etq_intraPAN_formatter(self.MAC_etq_intraPAN)))
        self._MAC_etq_intraPAN_tool_bar.addWidget(self._MAC_etq_intraPAN_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_intraPAN_tool_bar,  2,2,1,1)
          
        self._MAC_etq_dirOrigen_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_dirOrigen_formatter = None
        else:
          self._MAC_etq_dirOrigen_formatter = lambda x: x
        
        self._MAC_etq_dirOrigen_tool_bar.addWidget(Qt.QLabel("Direccion origen"+": "))
        self._MAC_etq_dirOrigen_label = Qt.QLabel(str(self._MAC_etq_dirOrigen_formatter(self.MAC_etq_dirOrigen)))
        self._MAC_etq_dirOrigen_tool_bar.addWidget(self._MAC_etq_dirOrigen_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_dirOrigen_tool_bar,  5,0,1,1)
          
        self._MAC_etq_dirDestino_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._MAC_etq_dirDestino_formatter = None
        else:
          self._MAC_etq_dirDestino_formatter = lambda x: x
        
        self._MAC_etq_dirDestino_tool_bar.addWidget(Qt.QLabel("Direccion destino"+": "))
        self._MAC_etq_dirDestino_label = Qt.QLabel(str(self._MAC_etq_dirDestino_formatter(self.MAC_etq_dirDestino)))
        self._MAC_etq_dirDestino_tool_bar.addWidget(self._MAC_etq_dirDestino_label)
        self.Tabrx_grid_layout_0 .addWidget(self._MAC_etq_dirDestino_tool_bar,  5,2,1,1)
          
        self._MAC_dirOrigen_tool_bar = Qt.QToolBar(self)
        self._MAC_dirOrigen_tool_bar.addWidget(Qt.QLabel("Direccion origen"+": "))
        self._MAC_dirOrigen_line_edit = Qt.QLineEdit(str(self.MAC_dirOrigen))
        self._MAC_dirOrigen_tool_bar.addWidget(self._MAC_dirOrigen_line_edit)
        self._MAC_dirOrigen_line_edit.returnPressed.connect(
        	lambda: self.set_MAC_dirOrigen(str(str(self._MAC_dirOrigen_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_0 .addWidget(self._MAC_dirOrigen_tool_bar,  5,0,1,1)
        self._MAC_dirDestino_tool_bar = Qt.QToolBar(self)
        self._MAC_dirDestino_tool_bar.addWidget(Qt.QLabel("Direccion destino"+": "))
        self._MAC_dirDestino_line_edit = Qt.QLineEdit(str(self.MAC_dirDestino))
        self._MAC_dirDestino_tool_bar.addWidget(self._MAC_dirDestino_line_edit)
        self._MAC_dirDestino_line_edit.returnPressed.connect(
        	lambda: self.set_MAC_dirDestino(str(str(self._MAC_dirDestino_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_0 .addWidget(self._MAC_dirDestino_tool_bar,  5,1,1,1)
        self._APS_tipoTrama_options = (0, 1, 2, )
        self._APS_tipoTrama_labels = ("Datos", "Comando", "ACK", )
        self._APS_tipoTrama_tool_bar = Qt.QToolBar(self)
        self._APS_tipoTrama_tool_bar.addWidget(Qt.QLabel("Tipo de trama"+": "))
        self._APS_tipoTrama_combo_box = Qt.QComboBox()
        self._APS_tipoTrama_tool_bar.addWidget(self._APS_tipoTrama_combo_box)
        for label in self._APS_tipoTrama_labels: self._APS_tipoTrama_combo_box.addItem(label)
        self._APS_tipoTrama_callback = lambda i: Qt.QMetaObject.invokeMethod(self._APS_tipoTrama_combo_box, "setCurrentIndex", Qt.Q_ARG("int", self._APS_tipoTrama_options.index(i)))
        self._APS_tipoTrama_callback(self.APS_tipoTrama)
        self._APS_tipoTrama_combo_box.currentIndexChanged.connect(
        	lambda i: self.set_APS_tipoTrama(self._APS_tipoTrama_options[i]))
        self.Tabtx_grid_layout_2.addWidget(self._APS_tipoTrama_tool_bar,  0,0,1,4)
        _APS_solicitaACK_check_box = Qt.QCheckBox("Solicita ACK")
        self._APS_solicitaACK_choices = {True: True, False: False}
        self._APS_solicitaACK_choices_inv = dict((v,k) for k,v in self._APS_solicitaACK_choices.iteritems())
        self._APS_solicitaACK_callback = lambda i: Qt.QMetaObject.invokeMethod(_APS_solicitaACK_check_box, "setChecked", Qt.Q_ARG("bool", self._APS_solicitaACK_choices_inv[i]))
        self._APS_solicitaACK_callback(self.APS_solicitaACK)
        _APS_solicitaACK_check_box.stateChanged.connect(lambda i: self.set_APS_solicitaACK(self._APS_solicitaACK_choices[bool(i)]))
        self.Tabtx_grid_layout_2 .addWidget(_APS_solicitaACK_check_box,  2,2,1,1)
        _APS_seguridad_check_box = Qt.QCheckBox("Seguridad")
        self._APS_seguridad_choices = {True: True, False: False}
        self._APS_seguridad_choices_inv = dict((v,k) for k,v in self._APS_seguridad_choices.iteritems())
        self._APS_seguridad_callback = lambda i: Qt.QMetaObject.invokeMethod(_APS_seguridad_check_box, "setChecked", Qt.Q_ARG("bool", self._APS_seguridad_choices_inv[i]))
        self._APS_seguridad_callback(self.APS_seguridad)
        _APS_seguridad_check_box.stateChanged.connect(lambda i: self.set_APS_seguridad(self._APS_seguridad_choices[bool(i)]))
        self.Tabtx_grid_layout_2 .addWidget(_APS_seguridad_check_box,  1,5,1,1)
        self._APS_perfil_tool_bar = Qt.QToolBar(self)
        self._APS_perfil_tool_bar.addWidget(Qt.QLabel("ID perfil"+": "))
        self._APS_perfil_line_edit = Qt.QLineEdit(str(self.APS_perfil))
        self._APS_perfil_tool_bar.addWidget(self._APS_perfil_line_edit)
        self._APS_perfil_line_edit.returnPressed.connect(
        	lambda: self.set_APS_perfil(str(str(self._APS_perfil_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_2 .addWidget(self._APS_perfil_tool_bar,  4,3,1,3)
        self.APS_msg_tipoTrama = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_tipoTrama')
        self._APS_msg_tipoTrama_win = sip.wrapinstance(self.APS_msg_tipoTrama.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_tipoTrama_win,  0,3,1,3)
        self.APS_msg_solicitaACK = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_solicitaACK')
        self._APS_msg_solicitaACK_win = sip.wrapinstance(self.APS_msg_solicitaACK.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_solicitaACK_win,  2,3,1,3)
        self.APS_msg_seguridad = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_seguridad')
        self._APS_msg_seguridad_win = sip.wrapinstance(self.APS_msg_seguridad.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_seguridad_win,  1,9,1,3)
        self.APS_msg_perfil = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_perfil')
        self._APS_msg_perfil_win = sip.wrapinstance(self.APS_msg_perfil.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_perfil_win,  4,9,1,3)
        self.APS_msg_modo = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_modo')
        self._APS_msg_modo_win = sip.wrapinstance(self.APS_msg_modo.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_modo_win,  0,9,1,3)
        self.APS_msg_grupo = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_grupo')
        self._APS_msg_grupo_win = sip.wrapinstance(self.APS_msg_grupo.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_grupo_win,  5,9,1,3)
        self.APS_msg_fragmentado = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_fragmentado')
        self._APS_msg_fragmentado_win = sip.wrapinstance(self.APS_msg_fragmentado.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_fragmentado_win,  6,2,1,2)
        self.APS_msg_formatoACK = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_formatoACK')
        self._APS_msg_formatoACK_win = sip.wrapinstance(self.APS_msg_formatoACK.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_formatoACK_win,  1,3,1,3)
        self.APS_msg_endpointOrigen = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_endpointOrigen')
        self._APS_msg_endpointOrigen_win = sip.wrapinstance(self.APS_msg_endpointOrigen.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_endpointOrigen_win,  3,3,1,3)
        self.APS_msg_endpointDestino = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_endpointDestino')
        self._APS_msg_endpointDestino_win = sip.wrapinstance(self.APS_msg_endpointDestino.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_endpointDestino_win,  3,9,1,3)
        self.APS_msg_counter = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_counter')
        self._APS_msg_counter_win = sip.wrapinstance(self.APS_msg_counter.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_counter_win,  5,3,1,3)
        self.APS_msg_cluster = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_cluster')
        self._APS_msg_cluster_win = sip.wrapinstance(self.APS_msg_cluster.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_cluster_win,  4,3,1,3)
        self.APS_msg_cabeceraExtendida = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_cabeceraExtendida')
        self._APS_msg_cabeceraExtendida_win = sip.wrapinstance(self.APS_msg_cabeceraExtendida.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_cabeceraExtendida_win,  2,9,1,3)
        self.APS_msg_bloque = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_bloque')
        self._APS_msg_bloque_win = sip.wrapinstance(self.APS_msg_bloque.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_bloque_win,  6,6,1,2)
        self.APS_msg_ack = qtgui.edit_box_msg(qtgui.STRING, '', '', True, True, 'aps_ack')
        self._APS_msg_ack_win = sip.wrapinstance(self.APS_msg_ack.pyqwidget(), Qt.QWidget)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_msg_ack_win,  6,10,1,2)
        self._APS_modo_options = (0, 1, 2, 3, )
        self._APS_modo_labels = ("Unicast", "Unicast indirecto", "Broadcast", "Grupo", )
        self._APS_modo_tool_bar = Qt.QToolBar(self)
        self._APS_modo_tool_bar.addWidget(Qt.QLabel("Modo de entrega"+": "))
        self._APS_modo_combo_box = Qt.QComboBox()
        self._APS_modo_tool_bar.addWidget(self._APS_modo_combo_box)
        for label in self._APS_modo_labels: self._APS_modo_combo_box.addItem(label)
        self._APS_modo_callback = lambda i: Qt.QMetaObject.invokeMethod(self._APS_modo_combo_box, "setCurrentIndex", Qt.Q_ARG("int", self._APS_modo_options.index(i)))
        self._APS_modo_callback(self.APS_modo)
        self._APS_modo_combo_box.currentIndexChanged.connect(
        	lambda i: self.set_APS_modo(self._APS_modo_options[i]))
        self.Tabtx_grid_layout_2.addWidget(self._APS_modo_tool_bar,  0,4,1,4)
        self._APS_grupo_tool_bar = Qt.QToolBar(self)
        self._APS_grupo_tool_bar.addWidget(Qt.QLabel("Direccion grupo"+": "))
        self._APS_grupo_line_edit = Qt.QLineEdit(str(self.APS_grupo))
        self._APS_grupo_tool_bar.addWidget(self._APS_grupo_line_edit)
        self._APS_grupo_line_edit.returnPressed.connect(
        	lambda: self.set_APS_grupo(str(str(self._APS_grupo_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_2 .addWidget(self._APS_grupo_tool_bar,  3,6,1,3)
        self._APS_fragmentado_options = (0, 1, 2, )
        self._APS_fragmentado_labels = ("Sin fragmentar", "1er fragmento", "Fragmentado", )
        self._APS_fragmentado_tool_bar = Qt.QToolBar(self)
        self._APS_fragmentado_tool_bar.addWidget(Qt.QLabel("C extendida"+": "))
        self._APS_fragmentado_combo_box = Qt.QComboBox()
        self._APS_fragmentado_tool_bar.addWidget(self._APS_fragmentado_combo_box)
        for label in self._APS_fragmentado_labels: self._APS_fragmentado_combo_box.addItem(label)
        self._APS_fragmentado_callback = lambda i: Qt.QMetaObject.invokeMethod(self._APS_fragmentado_combo_box, "setCurrentIndex", Qt.Q_ARG("int", self._APS_fragmentado_options.index(i)))
        self._APS_fragmentado_callback(self.APS_fragmentado)
        self._APS_fragmentado_combo_box.currentIndexChanged.connect(
        	lambda i: self.set_APS_fragmentado(self._APS_fragmentado_options[i]))
        self.Tabtx_grid_layout_2 .addWidget(self._APS_fragmentado_tool_bar,  5,0,1,5)
        _APS_formatoACK_check_box = Qt.QCheckBox("Formato ACK")
        self._APS_formatoACK_choices = {True: True, False: False}
        self._APS_formatoACK_choices_inv = dict((v,k) for k,v in self._APS_formatoACK_choices.iteritems())
        self._APS_formatoACK_callback = lambda i: Qt.QMetaObject.invokeMethod(_APS_formatoACK_check_box, "setChecked", Qt.Q_ARG("bool", self._APS_formatoACK_choices_inv[i]))
        self._APS_formatoACK_callback(self.APS_formatoACK)
        _APS_formatoACK_check_box.stateChanged.connect(lambda i: self.set_APS_formatoACK(self._APS_formatoACK_choices[bool(i)]))
        self.Tabtx_grid_layout_2 .addWidget(_APS_formatoACK_check_box,  1,2,1,1)
        self._APS_etq_tipoTrama_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_tipoTrama_formatter = None
        else:
          self._APS_etq_tipoTrama_formatter = lambda x: x
        
        self._APS_etq_tipoTrama_tool_bar.addWidget(Qt.QLabel("Tipo de trama"+": "))
        self._APS_etq_tipoTrama_label = Qt.QLabel(str(self._APS_etq_tipoTrama_formatter(self.APS_etq_tipoTrama)))
        self._APS_etq_tipoTrama_tool_bar.addWidget(self._APS_etq_tipoTrama_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_tipoTrama_tool_bar,  0,0,1,3)
          
        self._APS_etq_solicitaACK_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_solicitaACK_formatter = None
        else:
          self._APS_etq_solicitaACK_formatter = lambda x: x
        
        self._APS_etq_solicitaACK_tool_bar.addWidget(Qt.QLabel("Solicita ACK"+": "))
        self._APS_etq_solicitaACK_label = Qt.QLabel(str(self._APS_etq_solicitaACK_formatter(self.APS_etq_solicitaACK)))
        self._APS_etq_solicitaACK_tool_bar.addWidget(self._APS_etq_solicitaACK_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_solicitaACK_tool_bar,  2,0,1,3)
          
        self._APS_etq_seguridad_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_seguridad_formatter = None
        else:
          self._APS_etq_seguridad_formatter = lambda x: x
        
        self._APS_etq_seguridad_tool_bar.addWidget(Qt.QLabel("Seguridad"+": "))
        self._APS_etq_seguridad_label = Qt.QLabel(str(self._APS_etq_seguridad_formatter(self.APS_etq_seguridad)))
        self._APS_etq_seguridad_tool_bar.addWidget(self._APS_etq_seguridad_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_seguridad_tool_bar,  1,6,1,3)
          
        self._APS_etq_perfil_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_perfil_formatter = None
        else:
          self._APS_etq_perfil_formatter = lambda x: x
        
        self._APS_etq_perfil_tool_bar.addWidget(Qt.QLabel("ID perfil"+": "))
        self._APS_etq_perfil_label = Qt.QLabel(str(self._APS_etq_perfil_formatter(self.APS_etq_perfil)))
        self._APS_etq_perfil_tool_bar.addWidget(self._APS_etq_perfil_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_perfil_tool_bar,  4,6,1,3)
          
        self._APS_etq_modo_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_modo_formatter = None
        else:
          self._APS_etq_modo_formatter = lambda x: x
        
        self._APS_etq_modo_tool_bar.addWidget(Qt.QLabel("Modo de entrega"+": "))
        self._APS_etq_modo_label = Qt.QLabel(str(self._APS_etq_modo_formatter(self.APS_etq_modo)))
        self._APS_etq_modo_tool_bar.addWidget(self._APS_etq_modo_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_modo_tool_bar,  0,6,1,3)
          
        self._APS_etq_grupo_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_grupo_formatter = None
        else:
          self._APS_etq_grupo_formatter = lambda x: x
        
        self._APS_etq_grupo_tool_bar.addWidget(Qt.QLabel("Direccion grupo"+": "))
        self._APS_etq_grupo_label = Qt.QLabel(str(self._APS_etq_grupo_formatter(self.APS_etq_grupo)))
        self._APS_etq_grupo_tool_bar.addWidget(self._APS_etq_grupo_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_grupo_tool_bar,  5,6,1,3)
          
        self._APS_etq_fragmentado_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_fragmentado_formatter = None
        else:
          self._APS_etq_fragmentado_formatter = lambda x: x
        
        self._APS_etq_fragmentado_tool_bar.addWidget(Qt.QLabel("C extendida"+": "))
        self._APS_etq_fragmentado_label = Qt.QLabel(str(self._APS_etq_fragmentado_formatter(self.APS_etq_fragmentado)))
        self._APS_etq_fragmentado_tool_bar.addWidget(self._APS_etq_fragmentado_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_fragmentado_tool_bar,  6,0,1,2)
          
        self._APS_etq_formatoACK_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_formatoACK_formatter = None
        else:
          self._APS_etq_formatoACK_formatter = lambda x: x
        
        self._APS_etq_formatoACK_tool_bar.addWidget(Qt.QLabel("Formato ACK"+": "))
        self._APS_etq_formatoACK_label = Qt.QLabel(str(self._APS_etq_formatoACK_formatter(self.APS_etq_formatoACK)))
        self._APS_etq_formatoACK_tool_bar.addWidget(self._APS_etq_formatoACK_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_formatoACK_tool_bar,  1,0,1,3)
          
        self._APS_etq_endpointOrigen_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_endpointOrigen_formatter = None
        else:
          self._APS_etq_endpointOrigen_formatter = lambda x: x
        
        self._APS_etq_endpointOrigen_tool_bar.addWidget(Qt.QLabel("Endpoint origen"+": "))
        self._APS_etq_endpointOrigen_label = Qt.QLabel(str(self._APS_etq_endpointOrigen_formatter(self.APS_etq_endpointOrigen)))
        self._APS_etq_endpointOrigen_tool_bar.addWidget(self._APS_etq_endpointOrigen_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_endpointOrigen_tool_bar,  3,0,1,3)
          
        self._APS_etq_endpointDestino_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_endpointDestino_formatter = None
        else:
          self._APS_etq_endpointDestino_formatter = lambda x: x
        
        self._APS_etq_endpointDestino_tool_bar.addWidget(Qt.QLabel("Endpoint destino"+": "))
        self._APS_etq_endpointDestino_label = Qt.QLabel(str(self._APS_etq_endpointDestino_formatter(self.APS_etq_endpointDestino)))
        self._APS_etq_endpointDestino_tool_bar.addWidget(self._APS_etq_endpointDestino_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_endpointDestino_tool_bar,  3,6,1,3)
          
        self._APS_etq_counter_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_counter_formatter = None
        else:
          self._APS_etq_counter_formatter = lambda x: x
        
        self._APS_etq_counter_tool_bar.addWidget(Qt.QLabel("Contador"+": "))
        self._APS_etq_counter_label = Qt.QLabel(str(self._APS_etq_counter_formatter(self.APS_etq_counter)))
        self._APS_etq_counter_tool_bar.addWidget(self._APS_etq_counter_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_counter_tool_bar,  5,0,1,3)
          
        self._APS_etq_cluster_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_cluster_formatter = None
        else:
          self._APS_etq_cluster_formatter = lambda x: x
        
        self._APS_etq_cluster_tool_bar.addWidget(Qt.QLabel("ID cluster"+": "))
        self._APS_etq_cluster_label = Qt.QLabel(str(self._APS_etq_cluster_formatter(self.APS_etq_cluster)))
        self._APS_etq_cluster_tool_bar.addWidget(self._APS_etq_cluster_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_cluster_tool_bar,  4,0,1,3)
          
        self._APS_etq_cabeceraExtendida_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_cabeceraExtendida_formatter = None
        else:
          self._APS_etq_cabeceraExtendida_formatter = lambda x: x
        
        self._APS_etq_cabeceraExtendida_tool_bar.addWidget(Qt.QLabel("Cab extendida"+": "))
        self._APS_etq_cabeceraExtendida_label = Qt.QLabel(str(self._APS_etq_cabeceraExtendida_formatter(self.APS_etq_cabeceraExtendida)))
        self._APS_etq_cabeceraExtendida_tool_bar.addWidget(self._APS_etq_cabeceraExtendida_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_cabeceraExtendida_tool_bar,  2,6,1,3)
          
        self._APS_etq_bloque_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_bloque_formatter = None
        else:
          self._APS_etq_bloque_formatter = lambda x: x
        
        self._APS_etq_bloque_tool_bar.addWidget(Qt.QLabel("No bloque"+": "))
        self._APS_etq_bloque_label = Qt.QLabel(str(self._APS_etq_bloque_formatter(self.APS_etq_bloque)))
        self._APS_etq_bloque_tool_bar.addWidget(self._APS_etq_bloque_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_bloque_tool_bar,  6,4,1,2)
          
        self._APS_etq_ack_tool_bar = Qt.QToolBar(self)
        
        if None:
          self._APS_etq_ack_formatter = None
        else:
          self._APS_etq_ack_formatter = lambda x: x
        
        self._APS_etq_ack_tool_bar.addWidget(Qt.QLabel("Campo ACK"+": "))
        self._APS_etq_ack_label = Qt.QLabel(str(self._APS_etq_ack_formatter(self.APS_etq_ack)))
        self._APS_etq_ack_tool_bar.addWidget(self._APS_etq_ack_label)
        self.Tabrx_grid_layout_2 .addWidget(self._APS_etq_ack_tool_bar,  6,8,1,2)
          
        self._APS_endpointOrigen_tool_bar = Qt.QToolBar(self)
        self._APS_endpointOrigen_tool_bar.addWidget(Qt.QLabel("Endpoint origen"+": "))
        self._APS_endpointOrigen_line_edit = Qt.QLineEdit(str(self.APS_endpointOrigen))
        self._APS_endpointOrigen_tool_bar.addWidget(self._APS_endpointOrigen_line_edit)
        self._APS_endpointOrigen_line_edit.returnPressed.connect(
        	lambda: self.set_APS_endpointOrigen(str(str(self._APS_endpointOrigen_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_2 .addWidget(self._APS_endpointOrigen_tool_bar,  3,0,1,3)
        self._APS_endpointDestino_tool_bar = Qt.QToolBar(self)
        self._APS_endpointDestino_tool_bar.addWidget(Qt.QLabel("Endpoint destino"+": "))
        self._APS_endpointDestino_line_edit = Qt.QLineEdit(str(self.APS_endpointDestino))
        self._APS_endpointDestino_tool_bar.addWidget(self._APS_endpointDestino_line_edit)
        self._APS_endpointDestino_line_edit.returnPressed.connect(
        	lambda: self.set_APS_endpointDestino(str(str(self._APS_endpointDestino_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_2 .addWidget(self._APS_endpointDestino_tool_bar,  3,3,1,3)
        self._APS_cluster_tool_bar = Qt.QToolBar(self)
        self._APS_cluster_tool_bar.addWidget(Qt.QLabel("ID cluster"+": "))
        self._APS_cluster_line_edit = Qt.QLineEdit(str(self.APS_cluster))
        self._APS_cluster_tool_bar.addWidget(self._APS_cluster_line_edit)
        self._APS_cluster_line_edit.returnPressed.connect(
        	lambda: self.set_APS_cluster(str(str(self._APS_cluster_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_2 .addWidget(self._APS_cluster_tool_bar,  4,0,1,3)
        _APS_cabeceraExtendida_check_box = Qt.QCheckBox("Cab extendida")
        self._APS_cabeceraExtendida_choices = {True: True, False: False}
        self._APS_cabeceraExtendida_choices_inv = dict((v,k) for k,v in self._APS_cabeceraExtendida_choices.iteritems())
        self._APS_cabeceraExtendida_callback = lambda i: Qt.QMetaObject.invokeMethod(_APS_cabeceraExtendida_check_box, "setChecked", Qt.Q_ARG("bool", self._APS_cabeceraExtendida_choices_inv[i]))
        self._APS_cabeceraExtendida_callback(self.APS_cabeceraExtendida)
        _APS_cabeceraExtendida_check_box.stateChanged.connect(lambda i: self.set_APS_cabeceraExtendida(self._APS_cabeceraExtendida_choices[bool(i)]))
        self.Tabtx_grid_layout_2 .addWidget(_APS_cabeceraExtendida_check_box,  2,5,1,1)
        self._APS_bloque_tool_bar = Qt.QToolBar(self)
        self._APS_bloque_tool_bar.addWidget(Qt.QLabel("No bloque"+": "))
        self._APS_bloque_line_edit = Qt.QLineEdit(str(self.APS_bloque))
        self._APS_bloque_tool_bar.addWidget(self._APS_bloque_line_edit)
        self._APS_bloque_line_edit.returnPressed.connect(
        	lambda: self.set_APS_bloque(str(str(self._APS_bloque_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_2 .addWidget(self._APS_bloque_tool_bar,  5,5,1,2)
        self._APS_ack_tool_bar = Qt.QToolBar(self)
        self._APS_ack_tool_bar.addWidget(Qt.QLabel("Campo ACK"+": "))
        self._APS_ack_line_edit = Qt.QLineEdit(str(self.APS_ack))
        self._APS_ack_tool_bar.addWidget(self._APS_ack_line_edit)
        self._APS_ack_line_edit.returnPressed.connect(
        	lambda: self.set_APS_ack(str(str(self._APS_ack_line_edit.text().toAscii()))))
        self.Tabtx_grid_layout_2 .addWidget(self._APS_ack_tool_bar,  5,7,1,2)

        ##################################################
        # Connections
        ##################################################
        self.msg_connect((self.ieee802_15_4_oqpsk_phy_0, 'rxout'), (self.foo_wireshark_connector_0, 'in'))    
        self.msg_connect((self.ieee802_15_4_oqpsk_phy_0, 'rxout'), (self.tfg_MAC_stack_0, 'in(PHY)'))    
        self.msg_connect((self.tfg_APS_stack_0, 'out(ZCL)'), (self.tfg_Aplication_0, 'in'))    
        self.msg_connect((self.tfg_APS_stack_0, 'out(NWK)'), (self.tfg_NWK_stack_0, 'in(APS)'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_ack, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_bloque, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_cabeceraExtendida, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_cluster, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_counter, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_endpointDestino, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_endpointOrigen, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_formatoACK, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_fragmentado, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_grupo, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_modo, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_perfil, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_seguridad, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_solicitaACK, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.APS_msg_tipoTrama, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_dirDestino, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_dirOrigen, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_intraPAN, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_modoDest, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_modoSrc, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_numSeq, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_panDestino, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_panOrigen, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_payload, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_reqACK, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_seguridad, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_tipoTrama, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.MAC_msg_tramaPendiente, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_descRuta, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_dirDestino, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_dirIeeeDst, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_dirIeeeOrg, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_dirOrigen, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_direccionesSR, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_ieeeDst, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_ieeeSrce, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_mcastRadio, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_mcastRadioMax, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_modomulticast, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_multicast, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_numSeq, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_radio, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_seguridad, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_sourceRoute, 'val'))    
        self.msg_connect((self.tfg_Aplication_0, 'out'), (self.NWK_msg_tipoTrama, 'val'))    
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
        self.settings = Qt.QSettings("GNU Radio", "SDR_loopback")
        self.settings.setValue("geometry", self.saveGeometry())
        event.accept()

    def get_payload(self):
        return self.payload

    def set_payload(self, payload):
        self.payload = payload
        Qt.QMetaObject.invokeMethod(self._payload_line_edit, "setText", Qt.Q_ARG("QString", str(self.payload)))
        self.tfg_Aplication_0.setPayload(str(self.payload))

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

    def get_NWK_tipoTrama(self):
        return self.NWK_tipoTrama

    def set_NWK_tipoTrama(self, NWK_tipoTrama):
        self.NWK_tipoTrama = NWK_tipoTrama
        self._NWK_tipoTrama_callback(self.NWK_tipoTrama)
        self.tfg_Aplication_0.setNWK_frameType(self.NWK_tipoTrama) 

    def get_NWK_sourceRoute(self):
        return self.NWK_sourceRoute

    def set_NWK_sourceRoute(self, NWK_sourceRoute):
        self.NWK_sourceRoute = NWK_sourceRoute
        self._NWK_sourceRoute_callback(self.NWK_sourceRoute)
        self.tfg_Aplication_0.setNWK_sourceRoute(self.NWK_sourceRoute)

    def get_NWK_seguridad(self):
        return self.NWK_seguridad

    def set_NWK_seguridad(self, NWK_seguridad):
        self.NWK_seguridad = NWK_seguridad
        self._NWK_seguridad_callback(self.NWK_seguridad)
        self.tfg_Aplication_0.setNWK_security(self.NWK_seguridad)

    def get_NWK_radio(self):
        return self.NWK_radio

    def set_NWK_radio(self, NWK_radio):
        self.NWK_radio = NWK_radio
        Qt.QMetaObject.invokeMethod(self._NWK_radio_line_edit, "setText", Qt.Q_ARG("QString", str(self.NWK_radio)))
        self.tfg_Aplication_0.setNWK_radius(str(self.NWK_radio))

    def get_NWK_modoMulticast(self):
        return self.NWK_modoMulticast

    def set_NWK_modoMulticast(self, NWK_modoMulticast):
        self.NWK_modoMulticast = NWK_modoMulticast
        self._NWK_modoMulticast_callback(self.NWK_modoMulticast)
        self.tfg_Aplication_0.setNWK_multicastMember(self.NWK_modoMulticast)

    def get_NWK_mcastRadioMax(self):
        return self.NWK_mcastRadioMax

    def set_NWK_mcastRadioMax(self, NWK_mcastRadioMax):
        self.NWK_mcastRadioMax = NWK_mcastRadioMax
        Qt.QMetaObject.invokeMethod(self._NWK_mcastRadioMax_line_edit, "setText", Qt.Q_ARG("QString", str(self.NWK_mcastRadioMax)))
        self.tfg_Aplication_0.setNWK_multicastMaxRadius(str(self.NWK_mcastRadioMax))

    def get_NWK_mcastRadio(self):
        return self.NWK_mcastRadio

    def set_NWK_mcastRadio(self, NWK_mcastRadio):
        self.NWK_mcastRadio = NWK_mcastRadio
        Qt.QMetaObject.invokeMethod(self._NWK_mcastRadio_line_edit, "setText", Qt.Q_ARG("QString", str(self.NWK_mcastRadio)))
        self.tfg_Aplication_0.setNWK_multicastRadius(str(self.NWK_mcastRadio))

    def get_NWK_ieeeSrc(self):
        return self.NWK_ieeeSrc

    def set_NWK_ieeeSrc(self, NWK_ieeeSrc):
        self.NWK_ieeeSrc = NWK_ieeeSrc
        self._NWK_ieeeSrc_callback(self.NWK_ieeeSrc)
        self.tfg_Aplication_0.setNWK_hasSrcIEEE(self.NWK_ieeeSrc)

    def get_NWK_ieeeDst(self):
        return self.NWK_ieeeDst

    def set_NWK_ieeeDst(self, NWK_ieeeDst):
        self.NWK_ieeeDst = NWK_ieeeDst
        self._NWK_ieeeDst_callback(self.NWK_ieeeDst)
        self.tfg_Aplication_0.setNWK_hasDestIEEE(self.NWK_ieeeDst)

    def get_NWK_etq_tipoTrama(self):
        return self.NWK_etq_tipoTrama

    def set_NWK_etq_tipoTrama(self, NWK_etq_tipoTrama):
        self.NWK_etq_tipoTrama = NWK_etq_tipoTrama
        Qt.QMetaObject.invokeMethod(self._NWK_etq_tipoTrama_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_tipoTrama)))

    def get_NWK_etq_sourceRoute(self):
        return self.NWK_etq_sourceRoute

    def set_NWK_etq_sourceRoute(self, NWK_etq_sourceRoute):
        self.NWK_etq_sourceRoute = NWK_etq_sourceRoute
        Qt.QMetaObject.invokeMethod(self._NWK_etq_sourceRoute_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_sourceRoute)))

    def get_NWK_etq_seguridad(self):
        return self.NWK_etq_seguridad

    def set_NWK_etq_seguridad(self, NWK_etq_seguridad):
        self.NWK_etq_seguridad = NWK_etq_seguridad
        Qt.QMetaObject.invokeMethod(self._NWK_etq_seguridad_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_seguridad)))

    def get_NWK_etq_radio(self):
        return self.NWK_etq_radio

    def set_NWK_etq_radio(self, NWK_etq_radio):
        self.NWK_etq_radio = NWK_etq_radio
        Qt.QMetaObject.invokeMethod(self._NWK_etq_radio_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_radio)))

    def get_NWK_etq_numSeq(self):
        return self.NWK_etq_numSeq

    def set_NWK_etq_numSeq(self, NWK_etq_numSeq):
        self.NWK_etq_numSeq = NWK_etq_numSeq
        Qt.QMetaObject.invokeMethod(self._NWK_etq_numSeq_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_numSeq)))

    def get_NWK_etq_multicast(self):
        return self.NWK_etq_multicast

    def set_NWK_etq_multicast(self, NWK_etq_multicast):
        self.NWK_etq_multicast = NWK_etq_multicast
        Qt.QMetaObject.invokeMethod(self._NWK_etq_multicast_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_multicast)))

    def get_NWK_etq_modomulticast(self):
        return self.NWK_etq_modomulticast

    def set_NWK_etq_modomulticast(self, NWK_etq_modomulticast):
        self.NWK_etq_modomulticast = NWK_etq_modomulticast
        Qt.QMetaObject.invokeMethod(self._NWK_etq_modomulticast_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_modomulticast)))

    def get_NWK_etq_mcastRadioMax(self):
        return self.NWK_etq_mcastRadioMax

    def set_NWK_etq_mcastRadioMax(self, NWK_etq_mcastRadioMax):
        self.NWK_etq_mcastRadioMax = NWK_etq_mcastRadioMax
        Qt.QMetaObject.invokeMethod(self._NWK_etq_mcastRadioMax_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_mcastRadioMax)))

    def get_NWK_etq_mcastRadio(self):
        return self.NWK_etq_mcastRadio

    def set_NWK_etq_mcastRadio(self, NWK_etq_mcastRadio):
        self.NWK_etq_mcastRadio = NWK_etq_mcastRadio
        Qt.QMetaObject.invokeMethod(self._NWK_etq_mcastRadio_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_mcastRadio)))

    def get_NWK_etq_ieeeSrc(self):
        return self.NWK_etq_ieeeSrc

    def set_NWK_etq_ieeeSrc(self, NWK_etq_ieeeSrc):
        self.NWK_etq_ieeeSrc = NWK_etq_ieeeSrc
        Qt.QMetaObject.invokeMethod(self._NWK_etq_ieeeSrc_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_ieeeSrc)))

    def get_NWK_etq_ieeeDst(self):
        return self.NWK_etq_ieeeDst

    def set_NWK_etq_ieeeDst(self, NWK_etq_ieeeDst):
        self.NWK_etq_ieeeDst = NWK_etq_ieeeDst
        Qt.QMetaObject.invokeMethod(self._NWK_etq_ieeeDst_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_ieeeDst)))

    def get_NWK_etq_direccionesSR(self):
        return self.NWK_etq_direccionesSR

    def set_NWK_etq_direccionesSR(self, NWK_etq_direccionesSR):
        self.NWK_etq_direccionesSR = NWK_etq_direccionesSR
        Qt.QMetaObject.invokeMethod(self._NWK_etq_direccionesSR_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_direccionesSR)))

    def get_NWK_etq_dirOrigen(self):
        return self.NWK_etq_dirOrigen

    def set_NWK_etq_dirOrigen(self, NWK_etq_dirOrigen):
        self.NWK_etq_dirOrigen = NWK_etq_dirOrigen
        Qt.QMetaObject.invokeMethod(self._NWK_etq_dirOrigen_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_dirOrigen)))

    def get_NWK_etq_dirIeeeOrg(self):
        return self.NWK_etq_dirIeeeOrg

    def set_NWK_etq_dirIeeeOrg(self, NWK_etq_dirIeeeOrg):
        self.NWK_etq_dirIeeeOrg = NWK_etq_dirIeeeOrg
        Qt.QMetaObject.invokeMethod(self._NWK_etq_dirIeeeOrg_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_dirIeeeOrg)))

    def get_NWK_etq_dirIeeeDst(self):
        return self.NWK_etq_dirIeeeDst

    def set_NWK_etq_dirIeeeDst(self, NWK_etq_dirIeeeDst):
        self.NWK_etq_dirIeeeDst = NWK_etq_dirIeeeDst
        Qt.QMetaObject.invokeMethod(self._NWK_etq_dirIeeeDst_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_dirIeeeDst)))

    def get_NWK_etq_dirDestino(self):
        return self.NWK_etq_dirDestino

    def set_NWK_etq_dirDestino(self, NWK_etq_dirDestino):
        self.NWK_etq_dirDestino = NWK_etq_dirDestino
        Qt.QMetaObject.invokeMethod(self._NWK_etq_dirDestino_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_dirDestino)))

    def get_NWK_etq_descRuta(self):
        return self.NWK_etq_descRuta

    def set_NWK_etq_descRuta(self, NWK_etq_descRuta):
        self.NWK_etq_descRuta = NWK_etq_descRuta
        Qt.QMetaObject.invokeMethod(self._NWK_etq_descRuta_label, "setText", Qt.Q_ARG("QString", str(self.NWK_etq_descRuta)))

    def get_NWK_direccionesSR(self):
        return self.NWK_direccionesSR

    def set_NWK_direccionesSR(self, NWK_direccionesSR):
        self.NWK_direccionesSR = NWK_direccionesSR
        Qt.QMetaObject.invokeMethod(self._NWK_direccionesSR_line_edit, "setText", Qt.Q_ARG("QString", str(self.NWK_direccionesSR)))
        self.tfg_Aplication_0.setNWK_SourceRoute(str(self.NWK_direccionesSR)) 

    def get_NWK_dirOrigen(self):
        return self.NWK_dirOrigen

    def set_NWK_dirOrigen(self, NWK_dirOrigen):
        self.NWK_dirOrigen = NWK_dirOrigen
        Qt.QMetaObject.invokeMethod(self._NWK_dirOrigen_line_edit, "setText", Qt.Q_ARG("QString", str(self.NWK_dirOrigen)))
	self.tfg_Aplication_0.setNWK_sourceAdd(str(self.NWK_dirOrigen))

    def get_NWK_dirIEEESrc(self):
        return self.NWK_dirIEEESrc

    def set_NWK_dirIEEESrc(self, NWK_dirIEEESrc):
        self.NWK_dirIEEESrc = NWK_dirIEEESrc
        Qt.QMetaObject.invokeMethod(self._NWK_dirIEEESrc_line_edit, "setText", Qt.Q_ARG("QString", str(self.NWK_dirIEEESrc)))
	self.tfg_Aplication_0.setNWK_sourceIEEE(str(self.NWK_dirIEEESrc))

    def get_NWK_dirIEEEDst(self):
        return self.NWK_dirIEEEDst

    def set_NWK_dirIEEEDst(self, NWK_dirIEEEDst):
        self.NWK_dirIEEEDst = NWK_dirIEEEDst
        Qt.QMetaObject.invokeMethod(self._NWK_dirIEEEDst_line_edit, "setText", Qt.Q_ARG("QString", str(self.NWK_dirIEEEDst)))
	self.tfg_Aplication_0.setNWK_destinationIEEE(str(self.NWK_dirIEEEDst))

    def get_NWK_dirDestino(self):
        return self.NWK_dirDestino

    def set_NWK_dirDestino(self, NWK_dirDestino):
        self.NWK_dirDestino = NWK_dirDestino
        Qt.QMetaObject.invokeMethod(self._NWK_dirDestino_line_edit, "setText", Qt.Q_ARG("QString", str(self.NWK_dirDestino)))
        self.tfg_Aplication_0.setNWK_destinationAdd(str(self.NWK_dirDestino)) 

    def get_NWK_descRuta(self):
        return self.NWK_descRuta

    def set_NWK_descRuta(self, NWK_descRuta):
        self.NWK_descRuta = NWK_descRuta
        self._NWK_descRuta_callback(self.NWK_descRuta)
        self.tfg_Aplication_0.setNWK_discoverRoute(self.NWK_descRuta)

    def get_NWK_Multicast(self):
        return self.NWK_Multicast

    def set_NWK_Multicast(self, NWK_Multicast):
        self.NWK_Multicast = NWK_Multicast
        self._NWK_Multicast_callback(self.NWK_Multicast)
        self.tfg_Aplication_0.setNWK_multicastFlag(self.NWK_Multicast)

    def get_MAC_tramaPendiente(self):
        return self.MAC_tramaPendiente

    def set_MAC_tramaPendiente(self, MAC_tramaPendiente):
        self.MAC_tramaPendiente = MAC_tramaPendiente
        self._MAC_tramaPendiente_callback(self.MAC_tramaPendiente)
        self.tfg_Aplication_0.setMAC_framePending(self.MAC_tramaPendiente)

    def get_MAC_tipoTrama(self):
        return self.MAC_tipoTrama

    def set_MAC_tipoTrama(self, MAC_tipoTrama):
        self.MAC_tipoTrama = MAC_tipoTrama
        self._MAC_tipoTrama_callback(self.MAC_tipoTrama)
        self.tfg_Aplication_0.setMAC_frameType(self.MAC_tipoTrama)

    def get_MAC_seguridad(self):
        return self.MAC_seguridad

    def set_MAC_seguridad(self, MAC_seguridad):
        self.MAC_seguridad = MAC_seguridad
        self._MAC_seguridad_callback(self.MAC_seguridad)
        self.tfg_Aplication_0.setMAC_security(self.MAC_seguridad)

    def get_MAC_reqACK(self):
        return self.MAC_reqACK

    def set_MAC_reqACK(self, MAC_reqACK):
        self.MAC_reqACK = MAC_reqACK
        self._MAC_reqACK_callback(self.MAC_reqACK)
        self.tfg_Aplication_0.setMAC_ackRequest(self.MAC_reqACK)

    def get_MAC_panOrigen(self):
        return self.MAC_panOrigen

    def set_MAC_panOrigen(self, MAC_panOrigen):
        self.MAC_panOrigen = MAC_panOrigen
        Qt.QMetaObject.invokeMethod(self._MAC_panOrigen_line_edit, "setText", Qt.Q_ARG("QString", str(self.MAC_panOrigen)))
        self.tfg_Aplication_0.setMAC_srcPAN(str(self.MAC_panOrigen))

    def get_MAC_panDestino(self):
        return self.MAC_panDestino

    def set_MAC_panDestino(self, MAC_panDestino):
        self.MAC_panDestino = MAC_panDestino
        Qt.QMetaObject.invokeMethod(self._MAC_panDestino_line_edit, "setText", Qt.Q_ARG("QString", str(self.MAC_panDestino)))
        self.tfg_Aplication_0.setMAC_destPAN(str(self.MAC_panDestino))

    def get_MAC_modoSrc(self):
        return self.MAC_modoSrc

    def set_MAC_modoSrc(self, MAC_modoSrc):
        self.MAC_modoSrc = MAC_modoSrc
        self._MAC_modoSrc_callback(self.MAC_modoSrc)
        self.tfg_Aplication_0.setMAC_srcMode(self.MAC_modoSrc)

    def get_MAC_modoDest(self):
        return self.MAC_modoDest

    def set_MAC_modoDest(self, MAC_modoDest):
        self.MAC_modoDest = MAC_modoDest
        self._MAC_modoDest_callback(self.MAC_modoDest)
        self.tfg_Aplication_0.setMAC_destMode(self.MAC_modoDest)

    def get_MAC_intraPAN(self):
        return self.MAC_intraPAN

    def set_MAC_intraPAN(self, MAC_intraPAN):
        self.MAC_intraPAN = MAC_intraPAN
        self._MAC_intraPAN_callback(self.MAC_intraPAN)
        self.tfg_Aplication_0.setMAC_intraPAN(self.MAC_intraPAN)

    def get_MAC_etq_tramaPendiente(self):
        return self.MAC_etq_tramaPendiente

    def set_MAC_etq_tramaPendiente(self, MAC_etq_tramaPendiente):
        self.MAC_etq_tramaPendiente = MAC_etq_tramaPendiente
        Qt.QMetaObject.invokeMethod(self._MAC_etq_tramaPendiente_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_tramaPendiente)))

    def get_MAC_etq_tipoTrama(self):
        return self.MAC_etq_tipoTrama

    def set_MAC_etq_tipoTrama(self, MAC_etq_tipoTrama):
        self.MAC_etq_tipoTrama = MAC_etq_tipoTrama
        Qt.QMetaObject.invokeMethod(self._MAC_etq_tipoTrama_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_tipoTrama)))

    def get_MAC_etq_seguridad(self):
        return self.MAC_etq_seguridad

    def set_MAC_etq_seguridad(self, MAC_etq_seguridad):
        self.MAC_etq_seguridad = MAC_etq_seguridad
        Qt.QMetaObject.invokeMethod(self._MAC_etq_seguridad_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_seguridad)))

    def get_MAC_etq_reqACK(self):
        return self.MAC_etq_reqACK

    def set_MAC_etq_reqACK(self, MAC_etq_reqACK):
        self.MAC_etq_reqACK = MAC_etq_reqACK
        Qt.QMetaObject.invokeMethod(self._MAC_etq_reqACK_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_reqACK)))

    def get_MAC_etq_payload(self):
        return self.MAC_etq_payload

    def set_MAC_etq_payload(self, MAC_etq_payload):
        self.MAC_etq_payload = MAC_etq_payload
        Qt.QMetaObject.invokeMethod(self._MAC_etq_payload_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_payload)))

    def get_MAC_etq_panOrigen(self):
        return self.MAC_etq_panOrigen

    def set_MAC_etq_panOrigen(self, MAC_etq_panOrigen):
        self.MAC_etq_panOrigen = MAC_etq_panOrigen
        Qt.QMetaObject.invokeMethod(self._MAC_etq_panOrigen_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_panOrigen)))

    def get_MAC_etq_panDestino(self):
        return self.MAC_etq_panDestino

    def set_MAC_etq_panDestino(self, MAC_etq_panDestino):
        self.MAC_etq_panDestino = MAC_etq_panDestino
        Qt.QMetaObject.invokeMethod(self._MAC_etq_panDestino_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_panDestino)))

    def get_MAC_etq_numSeq(self):
        return self.MAC_etq_numSeq

    def set_MAC_etq_numSeq(self, MAC_etq_numSeq):
        self.MAC_etq_numSeq = MAC_etq_numSeq
        Qt.QMetaObject.invokeMethod(self._MAC_etq_numSeq_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_numSeq)))

    def get_MAC_etq_modoSrc(self):
        return self.MAC_etq_modoSrc

    def set_MAC_etq_modoSrc(self, MAC_etq_modoSrc):
        self.MAC_etq_modoSrc = MAC_etq_modoSrc
        Qt.QMetaObject.invokeMethod(self._MAC_etq_modoSrc_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_modoSrc)))

    def get_MAC_etq_modoDest(self):
        return self.MAC_etq_modoDest

    def set_MAC_etq_modoDest(self, MAC_etq_modoDest):
        self.MAC_etq_modoDest = MAC_etq_modoDest
        Qt.QMetaObject.invokeMethod(self._MAC_etq_modoDest_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_modoDest)))

    def get_MAC_etq_intraPAN(self):
        return self.MAC_etq_intraPAN

    def set_MAC_etq_intraPAN(self, MAC_etq_intraPAN):
        self.MAC_etq_intraPAN = MAC_etq_intraPAN
        Qt.QMetaObject.invokeMethod(self._MAC_etq_intraPAN_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_intraPAN)))

    def get_MAC_etq_dirOrigen(self):
        return self.MAC_etq_dirOrigen

    def set_MAC_etq_dirOrigen(self, MAC_etq_dirOrigen):
        self.MAC_etq_dirOrigen = MAC_etq_dirOrigen
        Qt.QMetaObject.invokeMethod(self._MAC_etq_dirOrigen_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_dirOrigen)))

    def get_MAC_etq_dirDestino(self):
        return self.MAC_etq_dirDestino

    def set_MAC_etq_dirDestino(self, MAC_etq_dirDestino):
        self.MAC_etq_dirDestino = MAC_etq_dirDestino
        Qt.QMetaObject.invokeMethod(self._MAC_etq_dirDestino_label, "setText", Qt.Q_ARG("QString", str(self.MAC_etq_dirDestino)))

    def get_MAC_dirOrigen(self):
        return self.MAC_dirOrigen

    def set_MAC_dirOrigen(self, MAC_dirOrigen):
        self.MAC_dirOrigen = MAC_dirOrigen
        Qt.QMetaObject.invokeMethod(self._MAC_dirOrigen_line_edit, "setText", Qt.Q_ARG("QString", str(self.MAC_dirOrigen)))
        self.tfg_Aplication_0.setMAC_srcAddress(str(self.MAC_dirOrigen))

    def get_MAC_dirDestino(self):
        return self.MAC_dirDestino

    def set_MAC_dirDestino(self, MAC_dirDestino):
        self.MAC_dirDestino = MAC_dirDestino
        Qt.QMetaObject.invokeMethod(self._MAC_dirDestino_line_edit, "setText", Qt.Q_ARG("QString", str(self.MAC_dirDestino)))
        self.tfg_Aplication_0.setMAC_destAddress(str(self.MAC_dirDestino))

    def get_APS_tipoTrama(self):
        return self.APS_tipoTrama

    def set_APS_tipoTrama(self, APS_tipoTrama):
        self.APS_tipoTrama = APS_tipoTrama
        self._APS_tipoTrama_callback(self.APS_tipoTrama)
        self.tfg_Aplication_0.setAPS_frameType(self.APS_tipoTrama)

    def get_APS_solicitaACK(self):
        return self.APS_solicitaACK

    def set_APS_solicitaACK(self, APS_solicitaACK):
        self.APS_solicitaACK = APS_solicitaACK
        self._APS_solicitaACK_callback(self.APS_solicitaACK)
        self.tfg_Aplication_0.setAPS_ackRequest(self.APS_solicitaACK)

    def get_APS_seguridad(self):
        return self.APS_seguridad

    def set_APS_seguridad(self, APS_seguridad):
        self.APS_seguridad = APS_seguridad
        self._APS_seguridad_callback(self.APS_seguridad)
        self.tfg_Aplication_0.setAPS_security(self.APS_seguridad)

    def get_APS_perfil(self):
        return self.APS_perfil

    def set_APS_perfil(self, APS_perfil):
        self.APS_perfil = APS_perfil
        Qt.QMetaObject.invokeMethod(self._APS_perfil_line_edit, "setText", Qt.Q_ARG("QString", str(self.APS_perfil)))
        self.tfg_Aplication_0.setAPS_profileID(str(self.APS_perfil))

    def get_APS_modo(self):
        return self.APS_modo

    def set_APS_modo(self, APS_modo):
        self.APS_modo = APS_modo
        self._APS_modo_callback(self.APS_modo)
        self.tfg_Aplication_0.setAPS_deliveryMode(self.APS_modo)

    def get_APS_grupo(self):
        return self.APS_grupo

    def set_APS_grupo(self, APS_grupo):
        self.APS_grupo = APS_grupo
        Qt.QMetaObject.invokeMethod(self._APS_grupo_line_edit, "setText", Qt.Q_ARG("QString", str(self.APS_grupo)))
        self.tfg_Aplication_0.setAPS_groupAdd(str(self.APS_grupo))

    def get_APS_fragmentado(self):
        return self.APS_fragmentado

    def set_APS_fragmentado(self, APS_fragmentado):
        self.APS_fragmentado = APS_fragmentado
        self._APS_fragmentado_callback(self.APS_fragmentado)
        self.tfg_Aplication_0.setAPS_fragmentation(self.APS_fragmentado)

    def get_APS_formatoACK(self):
        return self.APS_formatoACK

    def set_APS_formatoACK(self, APS_formatoACK):
        self.APS_formatoACK = APS_formatoACK
        self._APS_formatoACK_callback(self.APS_formatoACK)
        self.tfg_Aplication_0.setAPS_ackFormat(self.APS_formatoACK)

    def get_APS_etq_tipoTrama(self):
        return self.APS_etq_tipoTrama

    def set_APS_etq_tipoTrama(self, APS_etq_tipoTrama):
        self.APS_etq_tipoTrama = APS_etq_tipoTrama
        Qt.QMetaObject.invokeMethod(self._APS_etq_tipoTrama_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_tipoTrama)))

    def get_APS_etq_solicitaACK(self):
        return self.APS_etq_solicitaACK

    def set_APS_etq_solicitaACK(self, APS_etq_solicitaACK):
        self.APS_etq_solicitaACK = APS_etq_solicitaACK
        Qt.QMetaObject.invokeMethod(self._APS_etq_solicitaACK_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_solicitaACK)))

    def get_APS_etq_seguridad(self):
        return self.APS_etq_seguridad

    def set_APS_etq_seguridad(self, APS_etq_seguridad):
        self.APS_etq_seguridad = APS_etq_seguridad
        Qt.QMetaObject.invokeMethod(self._APS_etq_seguridad_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_seguridad)))

    def get_APS_etq_perfil(self):
        return self.APS_etq_perfil

    def set_APS_etq_perfil(self, APS_etq_perfil):
        self.APS_etq_perfil = APS_etq_perfil
        Qt.QMetaObject.invokeMethod(self._APS_etq_perfil_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_perfil)))

    def get_APS_etq_modo(self):
        return self.APS_etq_modo

    def set_APS_etq_modo(self, APS_etq_modo):
        self.APS_etq_modo = APS_etq_modo
        Qt.QMetaObject.invokeMethod(self._APS_etq_modo_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_modo)))

    def get_APS_etq_grupo(self):
        return self.APS_etq_grupo

    def set_APS_etq_grupo(self, APS_etq_grupo):
        self.APS_etq_grupo = APS_etq_grupo
        Qt.QMetaObject.invokeMethod(self._APS_etq_grupo_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_grupo)))

    def get_APS_etq_fragmentado(self):
        return self.APS_etq_fragmentado

    def set_APS_etq_fragmentado(self, APS_etq_fragmentado):
        self.APS_etq_fragmentado = APS_etq_fragmentado
        Qt.QMetaObject.invokeMethod(self._APS_etq_fragmentado_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_fragmentado)))

    def get_APS_etq_formatoACK(self):
        return self.APS_etq_formatoACK

    def set_APS_etq_formatoACK(self, APS_etq_formatoACK):
        self.APS_etq_formatoACK = APS_etq_formatoACK
        Qt.QMetaObject.invokeMethod(self._APS_etq_formatoACK_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_formatoACK)))

    def get_APS_etq_endpointOrigen(self):
        return self.APS_etq_endpointOrigen

    def set_APS_etq_endpointOrigen(self, APS_etq_endpointOrigen):
        self.APS_etq_endpointOrigen = APS_etq_endpointOrigen
        Qt.QMetaObject.invokeMethod(self._APS_etq_endpointOrigen_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_endpointOrigen)))

    def get_APS_etq_endpointDestino(self):
        return self.APS_etq_endpointDestino

    def set_APS_etq_endpointDestino(self, APS_etq_endpointDestino):
        self.APS_etq_endpointDestino = APS_etq_endpointDestino
        Qt.QMetaObject.invokeMethod(self._APS_etq_endpointDestino_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_endpointDestino)))

    def get_APS_etq_counter(self):
        return self.APS_etq_counter

    def set_APS_etq_counter(self, APS_etq_counter):
        self.APS_etq_counter = APS_etq_counter
        Qt.QMetaObject.invokeMethod(self._APS_etq_counter_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_counter)))

    def get_APS_etq_cluster(self):
        return self.APS_etq_cluster

    def set_APS_etq_cluster(self, APS_etq_cluster):
        self.APS_etq_cluster = APS_etq_cluster
        Qt.QMetaObject.invokeMethod(self._APS_etq_cluster_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_cluster)))

    def get_APS_etq_cabeceraExtendida(self):
        return self.APS_etq_cabeceraExtendida

    def set_APS_etq_cabeceraExtendida(self, APS_etq_cabeceraExtendida):
        self.APS_etq_cabeceraExtendida = APS_etq_cabeceraExtendida
        Qt.QMetaObject.invokeMethod(self._APS_etq_cabeceraExtendida_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_cabeceraExtendida)))

    def get_APS_etq_bloque(self):
        return self.APS_etq_bloque

    def set_APS_etq_bloque(self, APS_etq_bloque):
        self.APS_etq_bloque = APS_etq_bloque
        Qt.QMetaObject.invokeMethod(self._APS_etq_bloque_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_bloque)))

    def get_APS_etq_ack(self):
        return self.APS_etq_ack

    def set_APS_etq_ack(self, APS_etq_ack):
        self.APS_etq_ack = APS_etq_ack
        Qt.QMetaObject.invokeMethod(self._APS_etq_ack_label, "setText", Qt.Q_ARG("QString", str(self.APS_etq_ack)))

    def get_APS_endpointOrigen(self):
        return self.APS_endpointOrigen

    def set_APS_endpointOrigen(self, APS_endpointOrigen):
        self.APS_endpointOrigen = APS_endpointOrigen
        Qt.QMetaObject.invokeMethod(self._APS_endpointOrigen_line_edit, "setText", Qt.Q_ARG("QString", str(self.APS_endpointOrigen)))
        self.tfg_Aplication_0.setAPS_sourceEndpoint(str(self.APS_endpointOrigen))

    def get_APS_endpointDestino(self):
        return self.APS_endpointDestino

    def set_APS_endpointDestino(self, APS_endpointDestino):
        self.APS_endpointDestino = APS_endpointDestino
        Qt.QMetaObject.invokeMethod(self._APS_endpointDestino_line_edit, "setText", Qt.Q_ARG("QString", str(self.APS_endpointDestino)))
        self.tfg_Aplication_0.setAPS_destinationEndpoint(str(self.APS_endpointDestino))

    def get_APS_cluster(self):
        return self.APS_cluster

    def set_APS_cluster(self, APS_cluster):
        self.APS_cluster = APS_cluster
        Qt.QMetaObject.invokeMethod(self._APS_cluster_line_edit, "setText", Qt.Q_ARG("QString", str(self.APS_cluster)))
        self.tfg_Aplication_0.setAPS_clusterID(str(self.APS_cluster))

    def get_APS_cabeceraExtendida(self):
        return self.APS_cabeceraExtendida

    def set_APS_cabeceraExtendida(self, APS_cabeceraExtendida):
        self.APS_cabeceraExtendida = APS_cabeceraExtendida
        self._APS_cabeceraExtendida_callback(self.APS_cabeceraExtendida)
        self.tfg_Aplication_0.setAPS_extHeaderPresent(self.APS_cabeceraExtendida)

    def get_APS_bloque(self):
        return self.APS_bloque

    def set_APS_bloque(self, APS_bloque):
        self.APS_bloque = APS_bloque
        Qt.QMetaObject.invokeMethod(self._APS_bloque_line_edit, "setText", Qt.Q_ARG("QString", str(self.APS_bloque)))
        self.tfg_Aplication_0.setAPS_blockNumber(str(self.APS_bloque))

    def get_APS_ack(self):
        return self.APS_ack

    def set_APS_ack(self, APS_ack):
        self.APS_ack = APS_ack
        Qt.QMetaObject.invokeMethod(self._APS_ack_line_edit, "setText", Qt.Q_ARG("QString", str(self.APS_ack)))
        self.tfg_Aplication_0.setAPS_ackBitfield(str(self.APS_ack))


def main(top_block_cls=SDR_loopback, options=None):
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

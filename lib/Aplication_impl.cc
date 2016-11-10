/* -*- c++ -*- */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include <stdlib.h>
#include <ctype.h>
#include "Aplication_impl.h"
#include "libAPS.h"
#include "libNWK.h"
#include "libMAC.h"
#include "bytes.h"
#include <iostream>
#include <stdint.h>
#include <string.h>
#include <algorithm>
#include <sstream>



namespace gr {
  namespace tfg {

    Aplication::sptr Aplication::make() {
      return gnuradio::get_initial_sptr (new Aplication_impl());
    }

    
    Aplication_impl::Aplication_impl()
      : gr::block("Aplication",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)), payload("Ejemplo"), ledCount(0),
						MAC_frameType(libMAC::Consts::FrameC::FrameType_Data),
						MAC_security(false),
						MAC_framePending(false),
						MAC_ackRequest(false),
						MAC_intraPAN(false),
						MAC_destMode(libMAC::Consts::FrameC::DestAdd_Mode_ShortAdd),
						MAC_srcMode(libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd),
						MAC_destPAN(0xDCBA),
						MAC_shortDestAddress(0x01010101),
						MAC_longDestAddress(0x0101010101010101),
						MAC_srcPAN(0xABCD),
						MAC_shortSrcAddress(0x10101010),
						MAC_longSrcAddress(0x1010101010101010),

						NWK_frameType(libNWK::Consts::FrameC::FrameType_Data),
						NWK_discoverRoute(false),
						NWK_multicastFlag(false),
						NWK_security(false),
						NWK_sourceRoute(false),
						NWK_hasDestIEEE(false),
						NWK_hasSrcIEEE(false),
						NWK_destinationAdd(0x2222),
						NWK_sourceAdd(0x1111),
						NWK_radius(7),
						NWK_destinationIEEE(0x0101010101010101),
						NWK_sourceIEEE(0x1010101010101010),
						NWK_multicastMember(0),
						NWK_multicastRadius(7),
						NWK_multicastMaxRadius(7),
						NWK_countSourceRoute(2),
						NWK_indexSourceRoute(1),

						APS_frameType(libAPS::Consts::FrameC::FrameType_Data),
						APS_deliveryMode(libAPS::Consts::FrameC::Mode_Unicast),
						APS_ackFormat(false),
						APS_security(false),
						APS_ackRequest(false),
						APS_extHeaderPresent(false),
						APS_destinationEndpoint(1),
						APS_groupAdd(0x1234),
						APS_clusterID(0XABCD),
						APS_profileID(0xDCBA),
						APS_sourceEndpoint(2),
						APS_fragmentation(0),
						APS_blockNumber(0),
						APS_ackBitfield(0),
						APS_commandID(0) {

		    this->NWK_listSourceRoute = std::vector<uint16_t>();
		    this->NWK_listSourceRoute.clear();
		    this->NWK_listSourceRoute.push_back(0xDCBA);
		    this->NWK_listSourceRoute.push_back(0xABCD);

                    message_port_register_out(pmt::mp("out"));
                    message_port_register_in(pmt::mp("in"));
                    set_msg_handler(pmt::mp("in"), boost::bind(&Aplication_impl::msg_handler, this, _1));
            }

    Aplication_impl::~Aplication_impl() {}

    void Aplication_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required) {}

    int Aplication_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items) {
        
      return noutput_items;
    }

    
    void Aplication_impl::msg_handler(pmt::pmt_t msg) {


        size_t msg_len;
	const uint8_t *entrada = pmt::u8vector_elements(msg, msg_len);
        std::vector<uint8_t> frame (entrada, entrada + msg_len);
	std::vector<uint8_t> p;


	//MAC
        libMAC::FieldsMAC mac;
        mac.fromBytes(frame);

        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_tipoTrama"), pmt::intern(toDecString(mac.framecontrol.frameType))));
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_numSeq"), pmt::intern(toDecString(static_cast<unsigned int>(mac.seqNumber)))));
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_seguridad"), pmt::intern(toDecString(mac.framecontrol.security))));
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_tramaPendiente"), pmt::intern(toDecString(mac.framecontrol.framePending))));
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_reqACK"), pmt::intern(toDecString(mac.framecontrol.ackRequest))));
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_intrapan"), pmt::intern(toDecString(mac.framecontrol.intraPAN))));
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_modoSrc"), pmt::intern(toDecString(mac.framecontrol.srcMode))));
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_modoDest"), pmt::intern(toDecString(mac.framecontrol.destMode))));
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_panOrigen"), pmt::intern(toHexString(mac.srcPAN))));
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_panDestino"), pmt::intern(toHexString(mac.destPAN))));
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_dirOrigen"), pmt::intern(toHexString((mac.longSrcAddress > mac.shortSrcAddress) ? mac.longSrcAddress : mac.shortSrcAddress))));
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("mac_dirDestino"), pmt::intern(toHexString((mac.longDestAddress > mac.shortDestAddress) ? mac.longDestAddress : mac.shortDestAddress))));



	//NWK
	if(mac.framecontrol.frameType == libMAC::Consts::FrameC::FrameType_Data && (mac.payload.size() > 7)) {

		libNWK::FieldsNWK nwk;
	        nwk.fromBytes(mac.payload);


		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_tipoTrama"), pmt::intern(toDecString(nwk.framecontrol.frameType))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_numSeq"), pmt::intern(toDecString(static_cast<unsigned int>((nwk.sequenceNumber))))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_descRuta"), pmt::intern(toDecString(nwk.framecontrol.discoverRoute))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_multicast"), pmt::intern(toDecString(nwk.framecontrol.multicastFlag))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_seguridad"), pmt::intern(toDecString(nwk.framecontrol.security))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_sourceRoute"), pmt::intern(toDecString(nwk.framecontrol.sourceRoute))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_ieeeSrce"), pmt::intern(toDecString(nwk.framecontrol.sourceIEEE))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_ieeeDst"), pmt::intern(toDecString(nwk.framecontrol.destinationIEEE))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_dirOrigen"), pmt::intern(toHexString(nwk.sourceAdd))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_dirDestino"), pmt::intern(toHexString(nwk.destinationAdd))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_radio"), pmt::intern(toDecString(static_cast<unsigned int>(nwk.radius)))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_dirIeeeOrg"), pmt::intern(toHexString(nwk.sourceIEEE))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_dirIeeeDst"), pmt::intern(toHexString(nwk.destinationIEEE))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_modomulticast"), pmt::intern(toDecString(nwk.multicastMember))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_mcastRadio"), pmt::intern(toDecString(nwk.multicastRadius))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_mcastRadioMax"), pmt::intern(toDecString(nwk.multicastMaxRadius))));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_direccionesSR"), pmt::intern(sourceRoute2String(nwk.countSourceRoute, nwk.listSourceRoute))));




		if(nwk.framecontrol.frameType == libNWK::Consts::FrameC::FrameType_Data && (nwk.payload.size() > 3)) {

			libAPS::FieldsAPS aps;
        		aps.fromBytes(nwk.payload, nwk.isNWK);


			message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_tipoTrama"), pmt::intern(toDecString(aps.framecontrol.frameType))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_modo"), pmt::intern(toDecString(aps.framecontrol.deliveryMode))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_formatoACK"), pmt::intern(toDecString(aps.framecontrol.ackFormat))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_seguridad"), pmt::intern(toDecString(aps.framecontrol.security))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_solicitaACK"), pmt::intern(toDecString(aps.framecontrol.ackRequest))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_cabeceraExtendida"), pmt::intern(toDecString(aps.framecontrol.extHeaderPresent))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_endpointOrigen"), pmt::intern(toDecString(static_cast<unsigned int>(aps.sourceEndpoint)))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_endpointDestino"), pmt::intern(toDecString(static_cast<unsigned int>(aps.destinationEndpoint)))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_cluster"), pmt::intern(toHexString(aps.clusterID))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_perfil"), pmt::intern(toHexString(aps.profileID))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_counter"), pmt::intern(toDecString(static_cast<unsigned int>(aps.apsCounter)))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_grupo"), pmt::intern(toHexString(aps.groupAdd))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_fragmentado"), pmt::intern(toDecString(aps.fragmentation))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_bloque"), pmt::intern(toDecString(static_cast<unsigned int>(aps.blockNumber)))));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_ack"), pmt::intern(toHexString(static_cast<unsigned int>(aps.ackBitfield)))));

			p = aps.payload;
		}

		else {
			message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_tipoTrama"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_modo"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_formatoACK"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_seguridad"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_solicitaACK"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_cabeceraExtendida"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_endpointOrigen"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_endpointDestino"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_cluster"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_perfil"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_counter"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_grupo"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_fragmentado"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_bloque"), pmt::intern("")));
        		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_ack"), pmt::intern("")));

			p = nwk.payload;
		}
	}

	else {
		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_tipoTrama"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_numSeq"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_descRuta"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_multicast"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_seguridad"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_sourceRoute"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_ieeeSrce"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_ieeeDst"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_dirOrigen"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_dirDestino"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_radio"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_dirIeeeOrg"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_dirIeeeDst"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_modomulticast"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_mcastRadio"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_mcastRadioMax"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("nwk_direccionesSR"), pmt::intern("")));

		message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_tipoTrama"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_modo"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_formatoACK"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_seguridad"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_solicitaACK"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_cabeceraExtendida"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_endpointOrigen"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_endpointDestino"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_cluster"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_perfil"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_counter"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_grupo"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_fragmentado"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_bloque"), pmt::intern("")));
        	message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("aps_ack"), pmt::intern("")));

		p = mac.payload;


		//SENSOR
		if(mac.framecontrol.frameType == libMAC::Consts::FrameC::FrameType_Data && mac.destPAN == 0x0022 && mac.shortSrcAddress == 0x0001 && mac.shortDestAddress == 0xFFFF && mac.payload.size() == 4) {
			double aux = (mac.payload[2] << 8) + mac.payload[3];
			aux/=10.24;
			
			std::stringstream stream;
			stream << std::fixed << std::setprecision(2) << aux << std::setprecision(6);
			std::string sensStr = stream.str();

			message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("sensor"), pmt::intern(sensStr + "%")));
		}
        }


	//Payload
        std::string str(p.begin(), p.end()); 
        message_port_pub (pmt::mp("out"), pmt::cons(pmt::intern("payload"), pmt::intern(str)));

        
        
        if(true)
            std::cout << "(Aplicacion) Se ha recibido: '" << str << "'" << std::endl;
        
    }


    void Aplication_impl::send() {
        
        
        std::vector<uint8_t> p(this->payload.begin(), this->payload.end());
        
        
        libMAC::FieldsMAC mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(this->MAC_frameType,this->MAC_security,this->MAC_framePending,this->MAC_ackRequest,this->MAC_intraPAN,this->MAC_destMode, this->MAC_srcMode),
                                                        -1,
                                                        this->MAC_destPAN,
                                                        this->MAC_shortDestAddress,
                                                        this->MAC_longDestAddress,
                                                        this->MAC_srcPAN,
                                                        this->MAC_shortSrcAddress,
                                                        this->MAC_longSrcAddress,
                                                        std::vector<uint8_t>());

        
        libNWK::FieldsNWK nwk = libNWK::FieldsNWK(libNWK::FrameControl(this->NWK_frameType,this->NWK_discoverRoute,this->NWK_multicastFlag,this->NWK_security,this->NWK_sourceRoute,this->NWK_hasDestIEEE,this->NWK_hasSrcIEEE),
                                                        this->NWK_destinationAdd,
                                                        this->NWK_sourceAdd,
                                                        this->NWK_radius,
                                                        0,
                                                        this->NWK_destinationIEEE,
                                                        this->NWK_sourceIEEE,
                                                        this->NWK_multicastMember,
                                                        this->NWK_multicastRadius,
                                                        this->NWK_multicastMaxRadius,
                                                        this->NWK_countSourceRoute,
                                                        this->NWK_indexSourceRoute,
                                                        this->NWK_listSourceRoute,
                                                        std::vector<uint8_t>(),
                                                        mac);

        
        libAPS::FieldsAPS aps = libAPS::FieldsAPS(libAPS::FrameControl(this->APS_frameType,
                                                        this->APS_deliveryMode,
                                                        this->APS_ackFormat,this->APS_security,this->APS_ackRequest,this->APS_extHeaderPresent),
                                                    	this->APS_destinationEndpoint,
                                                    	this->APS_groupAdd,
                                                    	this->APS_clusterID,
                                                    	this->APS_profileID,
                                                    	this->APS_sourceEndpoint,
                                                    	static_cast<unsigned uint8_t>(0),
						    	this->APS_fragmentation,
                                                    	this->APS_blockNumber,
                                                    	this->APS_ackBitfield,
                                                    	this->APS_commandID,
                                                    	p,
                                                    	nwk);



	if(nwk.framecontrol.frameType == libNWK::Consts::FrameC::FrameType_Data && (aps.toBytes().size() > 3))
		nwk.setPayload(aps.toBytes());
	else
		nwk.setPayload(p);

	if(mac.framecontrol.frameType == libMAC::Consts::FrameC::FrameType_Data && (nwk.toBytes().size() > 7))
		mac.setPayload(nwk.toBytes());
	else
		mac.setPayload(p);


        std::vector<uint8_t> frame = mac.toBytes();
        
        pmt::pmt_t blob = pmt::init_u8vector(frame.size(), &frame[0]);
        message_port_pub (pmt::mp("out"), blob);
        sleep(1);
    }
    
    
    
    
    
    
    
    // Payload
    
    void Aplication_impl::setPayload(std::string payload){
        std::cout << "(Aplicacion) Cambiando el valor de la carga a '" << payload << "'." << std::endl << std::endl;
        this->payload = payload;
    }

    
    // MAC

    void Aplication_impl::setMAC_frameType(int MAC_frameType){
        std::cout << "(Aplicacion) Cambiando el valor del tipo de trama MAC a '" << MAC_frameType << "'." << std::endl << std::endl;
        this->MAC_frameType = MAC_frameType;
    }

    void Aplication_impl::setMAC_security(bool MAC_security){
        std::cout << "(Aplicacion) Cambiando el valor de 'seguridad (MAC)' a '" << MAC_security << "'." << std::endl << std::endl;
        this->MAC_security = MAC_security;
    }

    void Aplication_impl::setMAC_framePending(bool MAC_framePending){
        std::cout << "(Aplicacion) Cambiando el valor de 'trama pendiente (MAC)' a '" << MAC_framePending << "'." << std::endl << std::endl;
        this->MAC_framePending = MAC_framePending;
    }

    void Aplication_impl::setMAC_ackRequest(bool MAC_ackRequest){
        std::cout << "(Aplicacion) Cambiando el valor de 'solicita ACK (MAC)' a '" << MAC_ackRequest << "'." << std::endl << std::endl;
        this->MAC_ackRequest = MAC_ackRequest;
    }

    void Aplication_impl::setMAC_intraPAN(bool MAC_intraPAN){
        std::cout << "(Aplicacion) Cambiando el valor de 'intraPAN (MAC)' a '" << MAC_intraPAN << "'." << std::endl << std::endl;
        this->MAC_intraPAN = MAC_intraPAN;
    }

    void Aplication_impl::setMAC_destMode(int MAC_destMode){
        std::cout << "(Aplicacion) Cambiando el modo de dirección destino (MAC) a '" << MAC_destMode << "'." << std::endl << std::endl;
        this->MAC_destMode = MAC_destMode;
    }

    void Aplication_impl::setMAC_srcMode(int MAC_srcMode){
        std::cout << "(Aplicacion) Cambiando el modo de dirección origen (MAC) a '" << MAC_srcMode << "'." << std::endl << std::endl;
        this->MAC_srcMode = MAC_srcMode;
    }
    
    void Aplication_impl::setMAC_destPAN(std::string MAC_destPAN){
        
        bool result = false;
        uint64_t aux = strtoint(MAC_destPAN, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor de la PAN destino (MAC) a '" << MAC_destPAN << "'." << std::endl << std::endl;
            this->MAC_destPAN = aux;
        }

    }
    
    void Aplication_impl::setMAC_destAddress(std::string MAC_destAddress){
        
        bool result = false;
        uint64_t aux = strtoint(MAC_destAddress, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor de la dirección MAC destino a '" << MAC_destAddress << "'." << std::endl << std::endl;
            this->MAC_shortDestAddress = aux;
            this->MAC_longDestAddress = aux;
        }

    }
    
    void Aplication_impl::setMAC_srcPAN(std::string MAC_srcPAN){
        
        bool result = false;
        uint64_t aux = strtoint(MAC_srcPAN, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor de la PAN origen (MAC) a '" << MAC_srcPAN << "'." << std::endl << std::endl;
            this->MAC_srcPAN = aux;
        }

    }
    
    void Aplication_impl::setMAC_srcAddress(std::string MAC_srcAddress){
        
        bool result = false;
        uint64_t aux = strtoint(MAC_srcAddress, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor de la dirección MAC origen a '" << MAC_srcAddress << "'." << std::endl << std::endl;
            this->MAC_shortSrcAddress = aux;
            this->MAC_longSrcAddress = aux;
        }

    }

    
    // NWK

    void Aplication_impl::setNWK_frameType(int NWK_frameType){
        std::cout << "(Aplicacion) Cambiando el valor del tipo de trama NWK a '" << NWK_frameType << "'." << std::endl << std::endl;
        this->NWK_frameType = NWK_frameType;
    }

    void Aplication_impl::setNWK_discoverRoute(bool NWK_discoverRoute){
        std::cout << "(Aplicacion) Cambiando el valor de 'descubrimiento de ruta (NWK)' a '" << NWK_discoverRoute << "'." << std::endl << std::endl;
        this->NWK_discoverRoute = NWK_discoverRoute;
    }

    void Aplication_impl::setNWK_multicastFlag(bool NWK_multicastFlag){
        std::cout << "(Aplicacion) Cambiando multicast (NWK) a '" << NWK_multicastFlag << "'." << std::endl << std::endl;
        this->NWK_multicastFlag = NWK_multicastFlag;
    }

    void Aplication_impl::setNWK_security(bool NWK_security){
        std::cout << "(Aplicacion) Cambiando el valor de 'seguidad' (NWK) a '" << NWK_security << "'." << std::endl << std::endl;
        this->NWK_security = NWK_security;
    }

    void Aplication_impl::setNWK_sourceRoute(bool NWK_sourceRoute){
        std::cout << "(Aplicacion) Cambiando el valor de 'source route' (NWK) a '" << NWK_sourceRoute << "'." << std::endl << std::endl;
        this->NWK_sourceRoute = NWK_sourceRoute;
    }

    void Aplication_impl::setNWK_hasDestIEEE(bool NWK_hasDestIEEE){
        std::cout << "(Aplicacion) Cambiando el valor de 'incluye dirección IEEE destino' (NWK) a '" << NWK_hasDestIEEE << "'." << std::endl << std::endl;
        this->NWK_hasDestIEEE = NWK_hasDestIEEE;
    }

    void Aplication_impl::setNWK_hasSrcIEEE(bool NWK_hasSrcIEEE){
        std::cout << "(Aplicacion) Cambiando el valor de 'incluye dirección IEEE origen' (NWK) a '" << NWK_hasSrcIEEE << "'." << std::endl << std::endl;
        this->NWK_hasSrcIEEE = NWK_hasSrcIEEE;
    }
    
    void Aplication_impl::setNWK_destinationAdd(std::string NWK_destinationAdd){
        
        bool result = false;
        uint64_t aux = strtoint(NWK_destinationAdd, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor de la dirección destino (NWK) a '" << NWK_destinationAdd << "'." << std::endl << std::endl;
            this->NWK_destinationAdd = aux;
        }

    }
    
    void Aplication_impl::setNWK_sourceAdd(std::string NWK_sourceAdd){
        
        bool result = false;
        uint64_t aux = strtoint(NWK_sourceAdd, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor de la dirección MAC origen a '" << NWK_sourceAdd << "'." << std::endl << std::endl;
            this->NWK_sourceAdd = aux;
        }

    }
    
    void Aplication_impl::setNWK_radius(std::string NWK_radius){
        
        bool result = false;
        uint64_t aux = strtoint(NWK_radius, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor del radio (NWK) a '" << NWK_radius << "'." << std::endl << std::endl;
            this->NWK_radius = aux;
        }

    }
    
    void Aplication_impl::setNWK_destinationIEEE(std::string NWK_destinationIEEE){
        
        bool result = false;
        uint64_t aux = strtoint(NWK_destinationIEEE, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor de la dirección MAC destino (NWK) a '" << NWK_destinationIEEE << "'." << std::endl << std::endl;
            this->NWK_destinationIEEE = aux;
        }

    }
    
    void Aplication_impl::setNWK_sourceIEEE(std::string NWK_sourceIEEE){
        
        bool result = false;
        uint64_t aux = strtoint(NWK_sourceIEEE, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor de la dirección MAC origen (NWK) a '" << NWK_sourceIEEE << "'." << std::endl << std::endl;
            this->NWK_sourceIEEE = aux;
        }

    }

    void Aplication_impl::setNWK_multicastMember(bool NWK_multicastMember){
        std::cout << "(Aplicacion) Cambiando el valor de 'miembro multicast' (NWK) a '" << NWK_multicastMember << "'." << std::endl << std::endl;
        this->NWK_multicastMember = NWK_multicastMember;
    }
    
    void Aplication_impl::setNWK_multicastRadius(std::string NWK_multicastRadius){
        
        bool result = false;
        uint64_t aux = strtoint(NWK_multicastRadius, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor inicial de radio multicast (NWK) a '" << NWK_multicastRadius << "'." << std::endl << std::endl;
            this->NWK_multicastRadius = aux;
        }

    }
    
    void Aplication_impl::setNWK_multicastMaxRadius(std::string NWK_multicastMaxRadius){
        
        bool result = false;
        uint64_t aux = strtoint(NWK_multicastMaxRadius, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor máximo de radio multicast (NWK) a '" << NWK_multicastMaxRadius << "'." << std::endl << std::endl;
            this->NWK_multicastMaxRadius = aux;
        }

    }
    
    void Aplication_impl::setNWK_SourceRoute(std::string sourceRoute){
        
        std::vector<std::string> routers = split(sourceRoute, ',');
        uint8_t NWK_countSourceRoute;
        std::vector<uint16_t> NWK_listSourceRoute;
        
        for(int i = 0; i <routers.size(); i++){
            bool result = false;
            uint16_t aux = strtoint(routers[i], &result);
            if(result){
                NWK_listSourceRoute.push_back(static_cast<unsigned uint16_t>(aux));
                NWK_countSourceRoute++;
            }
        }
        
        if(NWK_listSourceRoute.size() > 0){
            std::cout << "(Aplicacion) Cambiando el vector de enrutado de 'source route' (NWK) a";
            for(int i = 0; i<NWK_listSourceRoute.size(); i++){
                std::cout << " 0x" << std::hex << std::uppercase << NWK_listSourceRoute[i] << std::nouppercase << std::dec;
            }
            std::cout << "." << std::endl;
        }
        
        this->NWK_countSourceRoute = NWK_countSourceRoute;
        this->NWK_indexSourceRoute = ((NWK_countSourceRoute - 1) > 0) ? (NWK_countSourceRoute - 1) : 0;
        this->NWK_listSourceRoute = NWK_listSourceRoute;

    }
    
    
    // APS

    void Aplication_impl::setAPS_frameType(int APS_frameType){
        std::cout << "(Aplicacion) Cambiando el valor del tipo de trama APS a '" << APS_frameType << "'." << std::endl << std::endl;
        this->APS_frameType = APS_frameType;
    }

    void Aplication_impl::setAPS_deliveryMode(int APS_deliveryMode){
        std::cout << "(Aplicacion) Cambiando el valor del modo de entraga APS a '" << APS_deliveryMode << "'." << std::endl << std::endl;
        this->APS_deliveryMode = APS_deliveryMode;
    }

    void Aplication_impl::setAPS_ackFormat(bool APS_ackFormat){
        std::cout << "(Aplicacion) Cambiando el valor del formato del ACK APS a '" << APS_ackFormat << "'." << std::endl << std::endl;
        this->APS_ackFormat = APS_ackFormat;
    }

    void Aplication_impl::setAPS_security(bool APS_security){
        std::cout << "(Aplicacion) Cambiando el valor de 'seguridad' (APS) a '" << APS_security << "'." << std::endl << std::endl;
        this->APS_security = APS_security;
    }

    void Aplication_impl::setAPS_ackRequest(bool APS_ackRequest){
        std::cout << "(Aplicacion) Cambiando el valor de 'solicita ACK' (APS) a '" << APS_ackRequest << "'." << std::endl << std::endl;
        this->APS_ackRequest = APS_ackRequest;
    }

    void Aplication_impl::setAPS_extHeaderPresent(bool APS_extHeaderPresent){
        std::cout << "(Aplicacion) Cambiando el valor de 'incluye cabecera extendida' (APS) a '" << APS_extHeaderPresent << "'." << std::endl << std::endl;
        this->APS_extHeaderPresent = APS_extHeaderPresent;
    }
    
    void Aplication_impl::setAPS_destinationEndpoint(std::string APS_destinationEndpoint){
        
        bool result = false;
        uint64_t aux = strtoint(APS_destinationEndpoint, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor del endpoint destino (APS) a '" << APS_destinationEndpoint << "'." << std::endl << std::endl;
            this->APS_destinationEndpoint = aux;
        }

    }
    
    void Aplication_impl::setAPS_groupAdd(std::string APS_groupAdd){
        
        bool result = false;
        uint64_t aux = strtoint(APS_groupAdd, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor de la dirección de grupo (APS) a '" << APS_groupAdd << "'." << std::endl << std::endl;
            this->APS_groupAdd = aux;
        }

    }
    
    void Aplication_impl::setAPS_clusterID(std::string APS_clusterID){
        
        bool result = false;
        uint64_t aux = strtoint(APS_clusterID, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor del identificador de clúster (APS) a '" << APS_clusterID << "'." << std::endl << std::endl;
            this->APS_clusterID = aux;
        }

    }
    
    void Aplication_impl::setAPS_profileID(std::string APS_profileID){
        
        bool result = false;
        uint64_t aux = strtoint(APS_profileID, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor del idetificador de perfil (APS) a '" << APS_profileID << "'." << std::endl << std::endl;
            this->APS_profileID = aux;
        }

    }
    
    void Aplication_impl::setAPS_sourceEndpoint(std::string APS_sourceEndpoint){
        
        bool result = false;
        uint64_t aux = strtoint(APS_sourceEndpoint, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor del endpoint origen (APS) a '" << APS_sourceEndpoint << "'." << std::endl << std::endl;
            this->APS_sourceEndpoint = aux;
        }

    }

    void Aplication_impl::setAPS_fragmentation(int APS_fragmentation){
        std::cout << "(Aplicacion) Cambiando el valor de 'fragmentación' (c.ext, APS) a '" << APS_fragmentation << "'." << std::endl << std::endl;
        this->APS_fragmentation = APS_fragmentation;
    }
    
    void Aplication_impl::setAPS_blockNumber(std::string APS_blockNumber){
        
        bool result = false;
        uint64_t aux = strtoint(APS_blockNumber, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor del número de bloque (c.ext, APS) a '" << APS_blockNumber << "'." << std::endl << std::endl;
            this->APS_blockNumber = aux;
        }

    }
    
    void Aplication_impl::setAPS_ackBitfield(std::string APS_ackBitfield){
        
        bool result = false;
        uint64_t aux = strtoint(APS_ackBitfield, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor del campo ACK (c.ext, APS) a '" << APS_ackBitfield << "'." << std::endl << std::endl;
            this->APS_ackBitfield = aux;
        }

    }
    
    void Aplication_impl::setAPS_commandID(std::string APS_commandID){
        
        bool result = false;
        uint64_t aux = strtoint(APS_commandID, &result);
        
        if(result){
            std::cout << "(Aplicacion) Cambiando el valor del comando APS a '" << APS_commandID << "'." << std::endl << std::endl;
            this->APS_commandID = aux;
        }

    }
    

    void Aplication_impl::toggleRedLed() {

	std::vector<uint8_t> leds;
	ledCount = ledCount ^ 1;
	leds = appendInt(leds, 0x00063F, 3);
	leds = appendInt(leds, ledCount, 1);

	libMAC::FieldsMAC msg = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Data,false,false,false,true,libMAC::Consts::FrameC::DestAdd_Mode_ShortAdd, libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd),
                                                        -1,
                                                        0x0022,
                                                        0xFFFF,
                                                        0x0000,
                                                        0x0022,
                                                        0x0001,
                                                        0x0000,
                                                        leds);

	std::vector<uint8_t> frame = msg.toBytes();
	message_port_pub (pmt::mp("out"), pmt::init_u8vector(frame.size(), &frame[0]));
    }

    void Aplication_impl::toggleGreenLed() {

	std::vector<uint8_t> leds;
	ledCount = ledCount ^ 2;
	leds = appendInt(leds, 0x00063F, 3);
	leds = appendInt(leds, ledCount, 1);

	libMAC::FieldsMAC msg = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Data,false,false,false,true,libMAC::Consts::FrameC::DestAdd_Mode_ShortAdd, libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd),
                                                        -1,
                                                        0x0022,
                                                        0xFFFF,
                                                        0x0000,
                                                        0x0022,
                                                        0x0001,
                                                        0x0000,
                                                        leds);

	std::vector<uint8_t> frame = msg.toBytes();
	message_port_pub (pmt::mp("out"), pmt::init_u8vector(frame.size(), &frame[0]));
    }

    void Aplication_impl::toggleYellowLed() {

	std::vector<uint8_t> leds;
	ledCount = ledCount ^ 4;
	leds = appendInt(leds, 0x00063F, 3);
	leds = appendInt(leds, ledCount, 1);

	libMAC::FieldsMAC msg = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Data,false,false,false,true,libMAC::Consts::FrameC::DestAdd_Mode_ShortAdd, libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd),
                                                        -1,
                                                        0x0022,
                                                        0xFFFF,
                                                        0x0000,
                                                        0x0022,
                                                        0x0001,
                                                        0x0000,
                                                        leds);

	std::vector<uint8_t> frame = msg.toBytes();
	message_port_pub (pmt::mp("out"), pmt::init_u8vector(frame.size(), &frame[0]));
    }




    
    
    
    
    
    
    
    

    uint64_t strtoint(std::string num, bool *resultado){
        
        if(num == ""){
            *resultado = false;
            return 0;
        }

        std::transform(num.begin(), num.end(), num.begin(), ::toupper);
            
            if(strncmp(num.c_str(), "0X", 2) == 0){
                for(int i=2; i<num.size(); i++){
                    if(!(isxdigit(num[i]))){
                        *resultado = false;
                        return 0;
                    }
                }
                *resultado = true;
                return strtoull(num.c_str(), NULL, 16);
            }
            else{
                for(int i=0; i<num.size(); i++){
                    if(!(isdigit(num[i]))){
                        *resultado = false;
                        return 0;
                    }
                }
                *resultado = true;
                return strtoull(num.c_str(), NULL, 10);
            }
            
            *resultado = false;
            return 0;
    }


    template <typename T> std::string toHexString(const T t){
        std::ostringstream ss;
        ss << std::hex << "0X" << std::uppercase << t << std::nouppercase << std::dec;
        return ss.str();
    }
    
    template <typename T> std::string toDecString(const T t){
        
        std::ostringstream ss;
        ss << t;
        return ss.str();
    }

    std::vector<std::string> split(std::string str, char delimiter) {
        std::vector<std::string> internal;
        std::stringstream ss(str); // Turn the string into a stream.
        std::string tok;
        
        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }
        
        return internal;
    }

    std::string sourceRoute2String(uint8_t countSourceRoute, std::vector<uint16_t> listSourceRoute) {

	std::ostringstream ss;

	for(std::vector<uint16_t>::iterator i=listSourceRoute.begin(); (i!=listSourceRoute.end() && countSourceRoute>0); ++i){
            ss << toHexString(static_cast<unsigned int>(*i));
	    countSourceRoute--;
	    if(i!=listSourceRoute.end() && countSourceRoute>0) ss << ", ";
        }

	return ss.str();
    }
    
  } /* namespace tfg */
} /* namespace gr */

/* -*- c++ -*- */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "motecontrol_impl.h"
#include "libAPS.h"
#include "libNWK.h"
#include "libMAC.h"
#include <stdlib.h>
#include <ctype.h>
#include "bytes.h"
#include <iostream>
#include <stdint.h>
#include <string.h>
#include <algorithm>
#include <sstream>

namespace gr {
  namespace tfg {

    motecontrol::sptr
    motecontrol::make()
    {
      return gnuradio::get_initial_sptr
        (new motecontrol_impl());
    }

    /*
     * The private constructor
     */
    motecontrol_impl::motecontrol_impl()
      : gr::block("motecontrol",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)), nextAdd(100) {

                  message_port_register_in(pmt::mp("in"));
		  message_port_register_in(pmt::mp("beacon"));
                  message_port_register_out(pmt::mp("out"));
                    
                  set_msg_handler(pmt::mp("in"), boost::bind(&motecontrol_impl::msg_handler, this, _1));
                  set_msg_handler(pmt::mp("beacon"), boost::bind(&motecontrol_impl::sendBeacon, this, _1));
    }

    /*
     * Our virtual destructor.
     */
    motecontrol_impl::~motecontrol_impl()
    {
    }

    void
    motecontrol_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    motecontrol_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      return noutput_items;
    }

    
    void motecontrol_impl::sendBeacon(pmt::pmt_t msg) {
        
	std::vector<uint8_t> payload;

	//Superframe
	payload = appendInt(payload, 0xcf48, 2);

	//GTS
	payload = appendInt(payload, 0x00, 1);

	//Pending
	//std::vector<uint8_t> aux = motecontrol_impl::pending();
	//payload.insert(payload.end(), aux.begin(), aux.end());
	payload = appendInt(payload, 0x00, 1);
	motecontrol_impl::pending();

	//Data
	payload = appendInt(payload, 0x00000001, 4);


	libMAC::FieldsMAC mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Beacon,false,false,false,false,libMAC::Consts::FrameC::DestAdd_Mode_Disabled, libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd),
                                                        -1,
                                                        0x0000,
                                                        0x0000,
                                                        0x0000,
                                                        0x123F,
                                                        0x0000,
                                                        0x0000,
                                                        payload);
	
        std::vector<uint8_t> frame = mac.toBytes();
        
        message_port_pub (pmt::mp("out"), pmt::init_u8vector(frame.size(), &frame[0]));

    }

    
    void motecontrol_impl::msg_handler(pmt::pmt_t msg) {

        size_t msg_len;
	const uint8_t *entrada = pmt::u8vector_elements(msg, msg_len);
        std::vector<uint8_t> frame (entrada, entrada + msg_len);

        libMAC::FieldsMAC request;
        request.fromBytes(frame);



	if(request.shortDestAddress == 0x0000 && request.framecontrol.frameType == 3 && request.destPAN == 0x123F) {

		libMAC::FieldsMAC ack;
		request.printMACFields();
		int comando = request.payload.at(0);

		std::vector<uint8_t> frame;

		//ASOCIATION REQ
		if(comando == 1) {
			ack = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_ACK,false,true,false,false,libMAC::Consts::FrameC::DestAdd_Mode_Disabled, libMAC::Consts::FrameC::SrcAdd_Mode_Disabled),
                                                        request.seqNumber,
                                                        0x0000,
                                                        0x0000,
                                                        0x0000,
                                                        0x0000,
                                                        0x0000,
                                                        0x0000,
                                                        std::vector<uint8_t>());

			frame = ack.toBytes();
			message_port_pub (pmt::mp("out"), pmt::init_u8vector(frame.size(), &frame[0]));

			pendingLong.push_back(request.longSrcAddress);
		}
		//DATA REQ
		if(comando == 4) {
			ack = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_ACK,false,true,false,false,libMAC::Consts::FrameC::DestAdd_Mode_Disabled, libMAC::Consts::FrameC::SrcAdd_Mode_Disabled),
                                                        request.seqNumber,
                                                        0x0000,
                                                        0x0000,
                                                        0x0000,
                                                        0x0000,
                                                        0x0000,
                                                        0x0000,
                                                        std::vector<uint8_t>());

			frame = ack.toBytes();
			message_port_pub (pmt::mp("out"), pmt::init_u8vector(frame.size(), &frame[0]));

			pendingLong.erase(std::remove(pendingLong.begin(), pendingLong.end(), request.longSrcAddress), pendingLong.end());


			std::vector<uint8_t> asr;
			//Comand asociation response
			asr = appendInt(asr, 0x02, 1);
			//Direction asociated
			asr = appendInt(asr, nextAdd, 1);
			nextAdd++;
			//Status
			asr = appendInt(asr, 0x00, 1);
			

			libMAC::FieldsMAC asRequest = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Command,false,false,true,true,libMAC::Consts::FrameC::DestAdd_Mode_LongAdd, libMAC::Consts::FrameC::SrcAdd_Mode_LongAdd),
                                                        (request.seqNumber + 1),
                                                        0x123F,
                                                        0x0000,
                                                        request.longSrcAddress,
                                                        0x0000,
                                                        0x0000,
                                                        request.longSrcAddress,
                                                        asr);

			std::vector<uint8_t> frame2 = ack.toBytes();
			message_port_pub (pmt::mp("out"), pmt::init_u8vector(frame2.size(), &frame2[0]));

		}

		moteStates[request.longSrcAddress] = comando;
		
		std::cout << "Comando " << moteStates[request.longSrcAddress] << std::endl;
	}

    }

    std::vector<uint8_t> motecontrol_impl::pending() {

	std::vector<uint8_t> frame;

	int pshort = (pendingShort.size() & 0xFFFF);
	int plong = (pendingLong.size() & 0xFFFF) + (pshort << 4);
        frame = appendInt(frame, plong, 1);

	for(std::vector<uint8_t>::iterator i=pendingShort.begin(); i!=pendingShort.end(); ++i){
		frame = appendInt(frame, (*i), 2);
        }

	for(std::vector<uint64_t>::iterator i=pendingLong.begin(); i!=pendingLong.end(); ++i){
		frame = append64Int(frame, (*i), 8);
        }
	return frame;
	
    }
    void motecontrol_impl::toggleRed() {
	std::cout << "(Mota) Led rojo" << std::endl;
    }

    void motecontrol_impl::toggleGreen() {
	std::cout << "(Mota) Led verde" << std::endl;
    }

    void motecontrol_impl::toggleYellow() {
	std::cout << "(Mota) Led amarillo" << std::endl;
    }

  } /* namespace tfg */
} /* namespace gr */

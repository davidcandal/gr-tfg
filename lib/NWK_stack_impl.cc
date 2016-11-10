/* -*- c++ -*- */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "NWK_stack_impl.h"
#include "libNWK.h"
#include "libMAC.h"
#include "bytes.h"


namespace gr {
  namespace tfg {

    NWK_stack::sptr NWK_stack::make(bool debugInput, bool debugOutput) {
      return gnuradio::get_initial_sptr (new NWK_stack_impl(debugInput, debugOutput));
    }

    NWK_stack_impl::NWK_stack_impl(bool debugInput, bool debugOutput)
      : gr::block("NWK_stack",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)), debugInput(debugInput), debugOutput(debugOutput), sequenceNumber(0) {

                  message_port_register_in(pmt::mp("in(APS)"));
                  message_port_register_out(pmt::mp("out(MAC)"));
                    
                  set_msg_handler(pmt::mp("in(APS)"), boost::bind(&NWK_stack_impl::msg_from_APS, this, _1));

                  message_port_register_in(pmt::mp("in(MAC)"));
                  message_port_register_out(pmt::mp("out(APS)"));
                    
                  set_msg_handler(pmt::mp("in(MAC)"), boost::bind(&NWK_stack_impl::msg_from_MAC, this, _1));
    }

    NWK_stack_impl::~NWK_stack_impl() {}

    void NWK_stack_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required) {}

    int NWK_stack_impl::general_work (int noutput_items, gr_vector_int &ninput_items, gr_vector_const_void_star &input_items, gr_vector_void_star &output_items) {
      return noutput_items;
    }




    void NWK_stack_impl::msg_from_APS(pmt::pmt_t msg) {
            
        size_t msg_len;
	const uint8_t *entrada = pmt::u8vector_elements(msg, msg_len);
        std::vector<uint8_t> frame (entrada, entrada + msg_len);

        libMAC::FieldsMAC mac;
        mac.fromBytes(frame);


	if(mac.framecontrol.frameType == libMAC::Consts::FrameC::FrameType_Data && (mac.payload.size() > 7)) {

		libNWK::FieldsNWK nwk;
	        nwk.fromBytes(mac.payload);
	        nwk.setSequenceNumber(sequenceNumber);
	        mac.setPayload(nwk.toBytes());
	        frame = mac.toBytes();
        
	        if(this->debugOutput){
	            std::cout << std::endl << "(NWK) Se ha enviado:" << std::endl;
	            nwk.printNWKFields();
	        }
	}
        
        
        message_port_pub (pmt::mp("out(MAC)"), pmt::init_u8vector(frame.size(), &frame[0]));
        
        sequenceNumber++;
    }
    
    void NWK_stack_impl::msg_from_MAC(pmt::pmt_t msg) {

        size_t msg_len;
	const uint8_t *entrada = pmt::u8vector_elements(msg, msg_len);
        std::vector<uint8_t> frame (entrada, entrada + msg_len);

        libMAC::FieldsMAC mac;
        mac.fromBytes(frame);


	if(mac.framecontrol.frameType == libMAC::Consts::FrameC::FrameType_Data && (mac.payload.size() > 7)) {

		libNWK::FieldsNWK nwk;
        	nwk.fromBytes(mac.payload);
        
        	if(this->debugInput){
            		std::cout << std::endl << "(NWK) Se ha recibido:" << std::endl;
            		nwk.printNWKFields();
        	}
	}
        
        message_port_pub (pmt::mp("out(APS)"), msg);
    }

  } /* namespace tfg */
} /* namespace gr */

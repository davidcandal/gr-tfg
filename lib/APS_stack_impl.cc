/* -*- c++ -*- */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "APS_stack_impl.h"
#include "libAPS.h"
#include "libNWK.h"
#include "libMAC.h"
#include "bytes.h"


namespace gr {
  namespace tfg {

    APS_stack::sptr APS_stack::make(bool debugInput, bool debugOutput) {
      return gnuradio::get_initial_sptr (new APS_stack_impl(debugInput, debugOutput));
    }

    APS_stack_impl::APS_stack_impl(bool debugInput, bool debugOutput)
      : gr::block("APS_stack",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)), debugInput(debugInput), debugOutput(debugOutput), counter(0) {

                  message_port_register_in(pmt::mp("in(ZCL)"));
                  message_port_register_out(pmt::mp("out(NWK)"));
                    
                  set_msg_handler(pmt::mp("in(ZCL)"), boost::bind(&APS_stack_impl::msg_from_ZCL, this, _1));

                  message_port_register_in(pmt::mp("in(NWK)"));
                  message_port_register_out(pmt::mp("out(ZCL)"));
                    
                  set_msg_handler(pmt::mp("in(NWK)"), boost::bind(&APS_stack_impl::msg_from_NWK, this, _1));
    }

                  
    APS_stack_impl::~APS_stack_impl() {}

    
    void APS_stack_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required) {}

    int  APS_stack_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items) {

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }




    void APS_stack_impl::msg_from_ZCL(pmt::pmt_t msg) {

        if(pmt::is_u8vector(msg)){
            
            size_t msg_len;
            const uint8_t *entrada = pmt::u8vector_elements(msg, msg_len);
            std::vector<uint8_t> frame (entrada, entrada + msg_len);

            libMAC::FieldsMAC mac;
            mac.fromBytes(frame);


		if(mac.framecontrol.frameType == libMAC::Consts::FrameC::FrameType_Data && (mac.payload.size() > 7)) {

			libNWK::FieldsNWK nwk;
		        nwk.fromBytes(mac.payload);

			if(nwk.framecontrol.frameType == libNWK::Consts::FrameC::FrameType_Data && (nwk.payload.size() > 3)) {

				libAPS::FieldsAPS aps;
	        		aps.fromBytes(nwk.payload, nwk.isNWK);
            			aps.setApsCounter(counter);
            			nwk.setPayload(aps.toBytes());
            			mac.setPayload(nwk.toBytes());
            			frame = mac.toBytes();
            
            			if(this->debugOutput){
            		    		std::cout << std::endl << "(APS) Se ha enviado:" << std::endl;
            		    		aps.printAPSFields();
            			}
				counter++;
			}
		}

            pmt::pmt_t blob = pmt::init_u8vector(frame.size(), &frame[0]);
            message_port_pub (pmt::mp("out(NWK)"), blob);
        }
    }
    
    void APS_stack_impl::msg_from_NWK(pmt::pmt_t msg) {
            
        size_t msg_len;
	const uint8_t *entrada = pmt::u8vector_elements(msg, msg_len);
        std::vector<uint8_t> frame (entrada, entrada + msg_len);

        libMAC::FieldsMAC mac;
        mac.fromBytes(frame);


	if(mac.framecontrol.frameType == libMAC::Consts::FrameC::FrameType_Data && (mac.payload.size() > 7)) {

		libNWK::FieldsNWK nwk;
	        nwk.fromBytes(mac.payload);

		if(nwk.framecontrol.frameType == libNWK::Consts::FrameC::FrameType_Data && (nwk.payload.size() > 3)) {

			libAPS::FieldsAPS aps;
        		aps.fromBytes(nwk.payload, nwk.isNWK);
        
        		if(this->debugInput){
            			std::cout << std::endl << "(APS) Se ha recibido:" << std::endl;
            			aps.printAPSFields();
        		}
		}
	}
        
        
        message_port_pub (pmt::mp("out(ZCL)"), msg);
    }

  } /* namespace tfg */
} /* namespace gr */


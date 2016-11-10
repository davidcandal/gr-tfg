/* -*- c++ -*- */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "MAC_stack_impl.h"
#include "libMAC.h"
#include "bytes.h"


namespace gr {
  namespace tfg {

    MAC_stack::sptr MAC_stack::make(bool debugInput, bool debugOutput) {
      return gnuradio::get_initial_sptr (new MAC_stack_impl(debugInput, debugOutput));
    }

    
    MAC_stack_impl::MAC_stack_impl(bool debugInput, bool debugOutput)
      : gr::block("MAC_stack",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)), debugInput(debugInput), debugOutput(debugOutput), sequenceNumber(0), packet_errors(0), packets_received(0) {

                  message_port_register_in(pmt::mp("in(NWK)"));
                  message_port_register_out(pmt::mp("out(PHY)"));
                    
                  set_msg_handler(pmt::mp("in(NWK)"), boost::bind(&MAC_stack_impl::msg_from_NWK, this, _1));

                  message_port_register_in(pmt::mp("in(PHY)"));
                  message_port_register_out(pmt::mp("out(NWK)"));
                    
                  set_msg_handler(pmt::mp("in(PHY)"), boost::bind(&MAC_stack_impl::msg_from_PHY, this, _1));
    }

    MAC_stack_impl::~MAC_stack_impl() {}

    void MAC_stack_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required) {}

    int MAC_stack_impl::general_work (int noutput_items, gr_vector_int &ninput_items, gr_vector_const_void_star &input_items, gr_vector_void_star &output_items) {
      return noutput_items;
    }




    void MAC_stack_impl::msg_from_NWK(pmt::pmt_t msg) {
        
        size_t msg_len;
	const uint8_t *entrada = pmt::u8vector_elements(msg, msg_len);
        std::vector<uint8_t> frame (entrada, entrada + msg_len);
        
        libMAC::FieldsMAC mac;
        mac.fromBytes(frame);
        
	if(mac.seqNumber == 255) mac.setSeqNumber(sequenceNumber);
        frame = mac.toBytes();
        
        if(this->debugOutput){
            //std::cout << std::endl << "(MAC) Se ha enviado:" << std::endl;
            mac.printMACFields();
        }
        
        pmt::pmt_t blob = pmt::make_blob(&frame[0], frame.size());
        message_port_pub (pmt::mp("out(PHY)"), pmt::cons(pmt::PMT_NIL, blob));
        
        sequenceNumber++;
    }
    
    void MAC_stack_impl::msg_from_PHY(pmt::pmt_t msg) {

        pmt::pmt_t blob;

        if(pmt::is_pair(msg))
            blob = pmt::cdr(msg);
        else
            assert(false);
        

        size_t lenght = pmt::blob_length(blob);
        if(lenght < 5) {
            //std::cout << "(MAC) Trama recibida mal formada." << std::endl;
            return;
        }

        uint16_t fcs = libMAC::FieldsMAC::makeFCS((uint8_t*)pmt::blob_data(blob), lenght);
        packets_received++;
        
        if(fcs){
            packet_errors++;
            std::cout << "(MAC) El FCS de la trama recibida no es correcto." << std::endl;
            return;
        }

        unsigned char buf[256];
        size_t msg_len = pmt::blob_length(blob);
        std::memcpy(buf, pmt::blob_data(blob), msg_len);
        std::vector<uint8_t> frame (buf, buf + msg_len);
        
        libMAC::FieldsMAC mac;
        mac.fromBytes(frame);
        
        if(this->debugInput){
            std::cout << std::endl << "(MAC) Se ha recibido:" << std::endl;
            mac.printMACFields();
        }
        
        message_port_pub (pmt::mp("out(NWK)"), pmt::init_u8vector(frame.size(), &frame[0]));
    }

  } /* namespace tfg */
} /* namespace gr */


/* -*- c++ -*- */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "translation_block_impl.h"

namespace gr {
  namespace tfg {

    translation_block::sptr translation_block::make() {
      return gnuradio::get_initial_sptr (new translation_block_impl());
    }

    
    translation_block_impl::translation_block_impl()
      : gr::block("translation_block",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)) {

                  message_port_register_in(pmt::mp("in(david)"));
                  message_port_register_out(pmt::mp("out(david)"));
                    
                  set_msg_handler(pmt::mp("in(david)"), boost::bind(&translation_block_impl::msg_from_NWK, this, _1));

                  message_port_register_in(pmt::mp("in(bastibl)"));
                  message_port_register_out(pmt::mp("out(bastibl)"));
                    
                  set_msg_handler(pmt::mp("in(bastibl)"), boost::bind(&translation_block_impl::msg_from_MAC, this, _1));
    }

    
    translation_block_impl::~translation_block_impl() {}

    void translation_block_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required) {}

    int translation_block_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items) {

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }
    
    
    
    void translation_block_impl::msg_from_NWK(pmt::pmt_t msg) {
        
        size_t msg_len;
        const uint8_t *entrada = pmt::u8vector_elements(msg, msg_len);
        pmt::pmt_t blob = pmt::make_blob(entrada, msg_len);
        message_port_pub (pmt::mp("out(bastibl)"), pmt::cons(pmt::PMT_NIL, blob));
    }
    
    void translation_block_impl::msg_from_MAC(pmt::pmt_t msg) {

        pmt::pmt_t blob;
        if(pmt::is_eof_object(msg)) {
            return;
        } else if(pmt::is_pair(msg)) {
            blob = pmt::cdr(msg);
        } else {
            assert(false);
        }
        
        unsigned char buf[256];
        size_t msg_len = pmt::blob_length(blob);
        std::memcpy(buf, pmt::blob_data(blob), msg_len);
        std::vector<uint8_t> frame (buf, buf + msg_len);
        
        pmt::pmt_t blob2 = pmt::init_u8vector(frame.size(), &frame[0]);
        message_port_pub (pmt::mp("out(david)"), blob2);
    }

  } /* namespace tfg */
} /* namespace gr */


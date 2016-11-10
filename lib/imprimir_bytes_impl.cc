/* -*- c++ -*- */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "imprimir_bytes_impl.h"
#include <stdio.h>
#include <string.h>
#include "bytes.h"

namespace gr {
  namespace tfg {

    imprimir_bytes::sptr imprimir_bytes::make() {
      return gnuradio::get_initial_sptr (new imprimir_bytes_impl());
    }

    imprimir_bytes_impl::imprimir_bytes_impl()
      : gr::block("imprimir_bytes",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)) {
                    message_port_register_in(pmt::mp("entrada"));
                    set_msg_handler(pmt::mp("entrada"), boost::bind(&imprimir_bytes_impl::msg_handler, this, _1));
    }

    imprimir_bytes_impl::~imprimir_bytes_impl() {}

    void imprimir_bytes_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required) {}

    int imprimir_bytes_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items) {
      return noutput_items;
    }
    
    
    
    

    
    void imprimir_bytes_impl::msg_handler(pmt::pmt_t msg){
        
        size_t msg_len;
	const uint8_t *entrada = pmt::u8vector_elements(msg, msg_len);
        std::vector<uint8_t> vector (entrada, entrada + msg_len);
        
        printVectorHexaValue(vector);
    }

  } /* namespace tfg */
} /* namespace gr */


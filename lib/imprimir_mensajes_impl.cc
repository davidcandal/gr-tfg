/* -*- c++ -*- */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "imprimir_mensajes_impl.h"
#include <stdio.h>
#include <string.h>

namespace gr {
  namespace tfg {

    imprimir_mensajes::sptr
    imprimir_mensajes::make() {
      return gnuradio::get_initial_sptr(new imprimir_mensajes_impl());
    }

    /*
     * The private constructor
     */
    imprimir_mensajes_impl::imprimir_mensajes_impl()
      : gr::block("imprimir_mensajes",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)){

                    message_port_register_in(pmt::mp("entrada"));
                    set_msg_handler(pmt::mp("entrada"), boost::bind(&imprimir_mensajes_impl::msg_handler, this, _1));
            }

    imprimir_mensajes_impl::~imprimir_mensajes_impl() {}

    
    void imprimir_mensajes_impl::msg_handler(pmt::pmt_t msg) {
        
        std::string str = pmt::symbol_to_string(msg);
        std::cout << "En el bloque 'imprimir_mensajes': Recibido = '" << str << "'" << std::endl << std::endl << std::endl;
    }

    void imprimir_mensajes_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required) {}

    int imprimir_mensajes_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items) {
      return noutput_items;
    }

  } /* namespace tfg */
} /* namespace gr */


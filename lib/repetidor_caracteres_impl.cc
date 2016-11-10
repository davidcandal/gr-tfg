/* -*- c++ -*- */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "repetidor_caracteres_impl.h"
#include <stdio.h>
#include <string.h>

namespace gr {
  namespace tfg {

    repetidor_caracteres::sptr
    repetidor_caracteres::make(int repeticiones) {
      return gnuradio::get_initial_sptr (new repetidor_caracteres_impl(repeticiones));
    }

    /*
     * The private constructor
     */
    repetidor_caracteres_impl::repetidor_caracteres_impl(int repeticiones)
      : gr::block("repetidor_caracteres",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)),
              repeticiones(repeticiones) {

                    message_port_register_in(pmt::mp("entrada"));
                    message_port_register_out(pmt::mp("salida"));
                    
                    set_msg_handler(pmt::mp("entrada"), boost::bind(&repetidor_caracteres_impl::msg_handler, this, _1));
            }

    /*
     * Our virtual destructor.
     */
    repetidor_caracteres_impl::~repetidor_caracteres_impl() {}

    
    void repetidor_caracteres_impl::msg_handler(pmt::pmt_t msg) {
        
        std::string str = pmt::symbol_to_string(msg);
        std::cout << "En el bloque 'repetidor_caracteres': Recibido = '" << str;
        
        int longitud = str.length();
        for(int i=longitud; i > 0; i--){
            str.insert(i, repeticiones-1, str.at(i-1));
        }
        
        std::cout << "' Transmitido: '" << str << "'" << std::endl;
        
        pmt::pmt_t mensaje = pmt::string_to_symbol(str);
        message_port_pub (pmt::mp("salida"), mensaje);
    }

    void repetidor_caracteres_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required) {}

    int repetidor_caracteres_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items) {
      return noutput_items;
    }
    

  } /* namespace tfg */
} /* namespace gr */


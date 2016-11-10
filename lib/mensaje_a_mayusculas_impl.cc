/* -*- c++ -*- */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "mensaje_a_mayusculas_impl.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>



namespace gr {
  namespace tfg {

    mensaje_a_mayusculas::sptr
    mensaje_a_mayusculas::make()
    {
      return gnuradio::get_initial_sptr
        (new mensaje_a_mayusculas_impl());
    }

    /*
     * The private constructor
     */
    mensaje_a_mayusculas_impl::mensaje_a_mayusculas_impl()
      : gr::block("mensaje_a_mayusculas",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(0, 0, 0)){

                    message_port_register_in(pmt::mp("entrada"));
                    message_port_register_out(pmt::mp("salida"));
                    
                    set_msg_handler(pmt::mp("entrada"), boost::bind(&mensaje_a_mayusculas_impl::msg_handler, this, _1));
            }

    /*
     * Our virtual destructor.
     */
    mensaje_a_mayusculas_impl::~mensaje_a_mayusculas_impl()
    {
    }

    
    void mensaje_a_mayusculas_impl::msg_handler(pmt::pmt_t msg){
        
        std::string str = pmt::symbol_to_string(msg);
        std::cout << "En el bloque 'mensaje_a_mayusculas': Recibido = '" << str;
        
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        std::cout << "' Transmitido: '" << str << "'" << std::endl;
        
        pmt::pmt_t mensaje = pmt::string_to_symbol(str);
        message_port_pub (pmt::mp("salida"), mensaje);
    }
    
    
    void
    mensaje_a_mayusculas_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    mensaje_a_mayusculas_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
    }

  } /* namespace tfg */
} /* namespace gr */


/* -*- c++ -*- */


#ifndef INCLUDED_INTERCAMBIO_BYTES_IMPRIMIR_MENSAJES_IMPL_H
#define INCLUDED_INTERCAMBIO_BYTES_IMPRIMIR_MENSAJES_IMPL_H

#include <tfg/imprimir_mensajes.h>

namespace gr {
  namespace tfg {

    class imprimir_mensajes_impl : public imprimir_mensajes {

     private:
      void msg_handler(pmt::pmt_t msg);

     public:
      imprimir_mensajes_impl();
      ~imprimir_mensajes_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_INTERCAMBIO_BYTES_IMPRIMIR_MENSAJES_IMPL_H */


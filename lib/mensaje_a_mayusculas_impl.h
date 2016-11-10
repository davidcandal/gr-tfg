/* -*- c++ -*- */


#ifndef INCLUDED_INTERCAMBIO_BYTES_MENSAJE_A_MAYUSCULAS_IMPL_H
#define INCLUDED_INTERCAMBIO_BYTES_MENSAJE_A_MAYUSCULAS_IMPL_H

#include <tfg/mensaje_a_mayusculas.h>

namespace gr {
  namespace tfg {

    class mensaje_a_mayusculas_impl : public mensaje_a_mayusculas {

     private:
         void msg_handler(pmt::pmt_t msg);

     public:
      mensaje_a_mayusculas_impl();
      ~mensaje_a_mayusculas_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_INTERCAMBIO_BYTES_MENSAJE_A_MAYUSCULAS_IMPL_H */


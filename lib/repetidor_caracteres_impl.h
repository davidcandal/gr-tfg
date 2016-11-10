/* -*- c++ -*- */


#ifndef INCLUDED_INTERCAMBIO_BYTES_REPETIDOR_CARACTERES_IMPL_H
#define INCLUDED_INTERCAMBIO_BYTES_REPETIDOR_CARACTERES_IMPL_H

#include <tfg/repetidor_caracteres.h>

namespace gr {
  namespace tfg {

    class repetidor_caracteres_impl : public repetidor_caracteres {
        
     private:
      int repeticiones;
      void msg_handler(pmt::pmt_t msg);

     public:
      repetidor_caracteres_impl(int repeticiones);
      ~repetidor_caracteres_impl();

      
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_INTERCAMBIO_BYTES_REPETIDOR_CARACTERES_IMPL_H */


/* -*- c++ -*- */


#ifndef INCLUDED_TFG_IMPRIMIR_BYTES_IMPL_H
#define INCLUDED_TFG_IMPRIMIR_BYTES_IMPL_H

#include <tfg/imprimir_bytes.h>

namespace gr {
  namespace tfg {

    class imprimir_bytes_impl : public imprimir_bytes {

     private:
      void msg_handler(pmt::pmt_t msg);

     public:
      imprimir_bytes_impl();
      ~imprimir_bytes_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_TFG_IMPRIMIR_BYTES_IMPL_H */


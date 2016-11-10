/* -*- c++ -*- */


#ifndef INCLUDED_TFG_TEST_MAC_IMPL_H
#define INCLUDED_TFG_TEST_MAC_IMPL_H

#include <tfg/test_mac.h>
#include "libMAC.h"

namespace gr {
  namespace tfg {

    class test_mac_impl : public test_mac {

     private:
      void msg_handler(pmt::pmt_t msg);
      bool hecho;

     public:
      test_mac_impl();
      ~test_mac_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_TFG_TEST_MAC_IMPL_H */


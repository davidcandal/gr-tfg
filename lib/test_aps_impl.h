/* -*- c++ -*- */


#ifndef INCLUDED_TFG_TEST_APS_IMPL_H
#define INCLUDED_TFG_TEST_APS_IMPL_H

#include <tfg/test_aps.h>
#include "libAPS.h"

namespace gr {
  namespace tfg {

    class test_aps_impl : public test_aps {

     private:
      void msg_handler(pmt::pmt_t msg);
      bool hecho;

     public:
      test_aps_impl();
      ~test_aps_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_TFG_TEST_APS_IMPL_H */


/* -*- c++ -*- */


#ifndef INCLUDED_TFG_NWK_STACK_IMPL_H
#define INCLUDED_TFG_NWK_STACK_IMPL_H

#include <tfg/NWK_stack.h>

namespace gr {
  namespace tfg {

    class NWK_stack_impl : public NWK_stack {

     private:
      bool debugInput;
      bool debugOutput;
      int sequenceNumber;

     public:
      NWK_stack_impl(bool debugInput, bool debugOutput);
      ~NWK_stack_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items, gr_vector_int &ninput_items, gr_vector_const_void_star &input_items, gr_vector_void_star &output_items);
      
      void msg_from_APS(pmt::pmt_t msg);
      void msg_from_MAC(pmt::pmt_t msg);
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_TFG_NWK_STACK_IMPL_H */


/* -*- c++ -*- */


#ifndef INCLUDED_TFG_APS_STACK_IMPL_H
#define INCLUDED_TFG_APS_STACK_IMPL_H

#include <tfg/APS_stack.h>

namespace gr {
  namespace tfg {

    class APS_stack_impl : public APS_stack {
        
     private:
      bool debugInput;
      bool debugOutput;
      int counter;

     public:
      APS_stack_impl(bool debugInput, bool debugOutput);
      ~APS_stack_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items, gr_vector_int &ninput_items, gr_vector_const_void_star &input_items, gr_vector_void_star &output_items);
      
      void msg_from_ZCL(pmt::pmt_t msg);
      void msg_from_NWK(pmt::pmt_t msg);
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_TFG_APS_STACK_IMPL_H */


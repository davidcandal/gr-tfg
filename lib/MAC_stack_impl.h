/* -*- c++ -*- */


#ifndef INCLUDED_TFG_MAC_STACK_IMPL_H
#define INCLUDED_TFG_MAC_STACK_IMPL_H

#include <tfg/MAC_stack.h>

namespace gr {
  namespace tfg {

    class MAC_stack_impl : public MAC_stack {
        
     private:
      bool debugInput;
      bool debugOutput;
      int sequenceNumber;
      int packet_errors;
      int packets_received;

     public:
      MAC_stack_impl(bool debugInput, bool debugOutput);
      ~MAC_stack_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items, gr_vector_int &ninput_items, gr_vector_const_void_star &input_items, gr_vector_void_star &output_items);
      
      void msg_from_PHY(pmt::pmt_t msg);
      void msg_from_NWK(pmt::pmt_t msg);
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_TFG_MAC_STACK_IMPL_H */


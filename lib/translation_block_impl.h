/* -*- c++ -*- */


#ifndef INCLUDED_TFG_TRANSLATION_BLOCK_IMPL_H
#define INCLUDED_TFG_TRANSLATION_BLOCK_IMPL_H

#include <tfg/translation_block.h>

namespace gr {
  namespace tfg {

    class translation_block_impl : public translation_block
    {
     private:
      // Nothing to declare in this block.

     public:
      translation_block_impl();
      ~translation_block_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
      
      void msg_from_NWK(pmt::pmt_t msg);
      void msg_from_MAC(pmt::pmt_t msg);
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_TFG_TRANSLATION_BLOCK_IMPL_H */


/* -*- c++ -*- */


#ifndef INCLUDED_TFG_MOTECONTROL_IMPL_H
#define INCLUDED_TFG_MOTECONTROL_IMPL_H

#include <tfg/motecontrol.h>
#include <string.h>

namespace gr {
  namespace tfg {

    class motecontrol_impl : public motecontrol
    {
     private:
      void msg_handler(pmt::pmt_t msg);
      void sendBeacon(pmt::pmt_t msg);
      std::map<uint64_t, int> moteStates;
      uint16_t nextAdd;
      std::vector<uint8_t> pendingShort;
      std::vector<uint64_t> pendingLong;
      std::vector<uint8_t> pending();

     public:
      motecontrol_impl();
      ~motecontrol_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);

      virtual void toggleRed();
      virtual void toggleGreen();
      virtual void toggleYellow();
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_TFG_MOTECONTROL_IMPL_H */


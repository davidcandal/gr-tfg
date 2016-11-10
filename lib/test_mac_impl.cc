/* -*- c++ -*- */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "test_mac_impl.h"
#include "bytes.h"

namespace gr {
  namespace tfg {

    test_mac::sptr
    test_mac::make()
    {
      return gnuradio::get_initial_sptr
        (new test_mac_impl());
    }

    /*
     * The private constructor
     */
    test_mac_impl::test_mac_impl()
      : gr::block("test_mac",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)), hecho(false) {

                    message_port_register_in(pmt::mp("entrada"));
                    message_port_register_out(pmt::mp("salida"));
                    
                    set_msg_handler(pmt::mp("entrada"), boost::bind(&test_mac_impl::msg_handler, this, _1));
    }

    /*
     * Our virtual destructor.
     */
    test_mac_impl::~test_mac_impl()
    {
    }

    void
    test_mac_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    test_mac_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      return noutput_items;
    }
    
    
    
    
    
    
    void test_mac_impl::msg_handler(pmt::pmt_t msg) {
        
        if(hecho) return;
        
        hecho = true;
        
        std::string str = "David";
        std::vector<uint8_t> payload(str.begin(), str.end());
        libMAC::FieldsMAC array[10];

        
        std::cout << "\n\n\n\nListado de tramas MAC a comprobar:\n\n";
        
        libMAC::FieldsMAC mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Data,true,true,true,true,libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd, libMAC::Consts::FrameC::DestAdd_Mode_ShortAdd),
                                                        1,
                                                        1,
                                                        1,
                                                        11,
                                                        1,
                                                        1,
                                                        11,
                                                        payload);
        //mac.printMACFields();
        array[0] = mac;
        std::vector<uint8_t> frame = mac.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Data,false,false,false,false,libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd, libMAC::Consts::FrameC::DestAdd_Mode_ShortAdd),
                                                        2,
                                                        2,
                                                        2,
                                                        22,
                                                        2,
                                                        2,
                                                        22,
                                                        payload);
        //mac.printMACFields();
        array[1] = mac;
        frame = mac.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Data,false,false,false,true,libMAC::Consts::FrameC::SrcAdd_Mode_LongAdd, libMAC::Consts::FrameC::DestAdd_Mode_ShortAdd),
                                                        3,
                                                        3,
                                                        3,
                                                        33,
                                                        3,
                                                        3,
                                                        33,
                                                        payload);
        //mac.printMACFields();
        array[2] = mac;
        frame = mac.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Data,false,false,false,false,libMAC::Consts::FrameC::SrcAdd_Mode_LongAdd, libMAC::Consts::FrameC::DestAdd_Mode_LongAdd),
                                                        4,
                                                        4,
                                                        4,
                                                        44,
                                                        4,
                                                        4,
                                                        44,
                                                        payload);
        //mac.printMACFields();
        array[3] = mac;
        frame = mac.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Data,false,false,false,true,libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd, libMAC::Consts::FrameC::DestAdd_Mode_LongAdd),
                                                        5,
                                                        5,
                                                        5,
                                                        55,
                                                        5,
                                                        5,
                                                        55,
                                                        payload);
        //mac.printMACFields();
        array[4] = mac;
        frame = mac.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Data,false,false,false,false,libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd, libMAC::Consts::FrameC::DestAdd_Mode_LongAdd),
                                                        6,
                                                        6,
                                                        6,
                                                        66,
                                                        6,
                                                        6,
                                                        66,
                                                        payload);
        //mac.printMACFields();
        array[5] = mac;
        frame = mac.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Beacon,false,false,false,true,libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd, libMAC::Consts::FrameC::DestAdd_Mode_ShortAdd),
                                                        7,
                                                        7,
                                                        7,
                                                        77,
                                                        7,
                                                        7,
                                                        77,
                                                        payload);
        //mac.printMACFields();
        array[6] = mac;
        frame = mac.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_ACK,false,false,false,false,libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd, libMAC::Consts::FrameC::DestAdd_Mode_ShortAdd),
                                                        8,
                                                        8,
                                                        8,
                                                        88,
                                                        8,
                                                        8,
                                                        88,
                                                        payload);
        //mac.printMACFields();
        array[7] = mac;
        frame = mac.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Command,false,false,false,true,libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd, libMAC::Consts::FrameC::SrcAdd_Mode_Disabled),
                                                        9,
                                                        9,
                                                        9,
                                                        99,
                                                        9,
                                                        9,
                                                        99,
                                                        payload);
        //mac.printMACFields();
        array[8] = mac;
        frame = mac.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Data,false,false,false,false,libMAC::Consts::FrameC::SrcAdd_Mode_Disabled, libMAC::Consts::FrameC::SrcAdd_Mode_Disabled),
                                                        10,
                                                        10,
                                                        10,
                                                        100,
                                                        10,
                                                        10,
                                                        100,
                                                        payload);
        //mac.printMACFields();
        array[9] = mac;
        frame = mac.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        
        std::cout << "\n\nTodas las tramas:\n\n" << std::endl;
        for(int i=0; i<10; i++) {
            frame = array[i].toBytes();
            message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
            sleep(1);
        }
        sleep(10);
        
        delete this;
    }

  } /* namespace tfg */
} /* namespace gr */


/* -*- c++ -*- */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "test_nwk_impl.h"
#include "bytes.h"
#include <stdio.h>
#include <string.h>
#include "libMAC.h"


namespace gr {
  namespace tfg {

    test_nwk::sptr test_nwk::make() {
      return gnuradio::get_initial_sptr (new test_nwk_impl());
    }

    test_nwk_impl::test_nwk_impl() : gr::block("test_nwk",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)), hecho(false) {

                    message_port_register_in(pmt::mp("entrada"));
                    message_port_register_out(pmt::mp("salida"));
                    
                    set_msg_handler(pmt::mp("entrada"), boost::bind(&test_nwk_impl::msg_handler, this, _1));
    }

    test_nwk_impl::~test_nwk_impl() {}

    void test_nwk_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required) {}

    int test_nwk_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items) {

                  return noutput_items;
    }

    
    void test_nwk_impl::msg_handler(pmt::pmt_t msg) {
        
        if(hecho) return;
        
        hecho = true;
        
        std::string str = "David";
        std::vector<uint8_t> payload(str.begin(), str.end());
        //libNWK::FieldsNWK array[10];

        
        std::cout << "\n\n\n\nListado de tramas NWK a comprobar:\n\n";
        
        libMAC::FieldsMAC mac = libMAC::FieldsMAC(
                                    libMAC::FrameControl(libMAC::Consts::FrameC::FrameType_Data,false,false,false,true,libMAC::Consts::FrameC::SrcAdd_Mode_ShortAdd, libMAC::Consts::FrameC::DestAdd_Mode_ShortAdd),
                                                        1,
                                                        1,
                                                        1,
                                                        11,
                                                        1,
                                                        1,
                                                        11,
                                                        std::vector<uint8_t>());
        
        std::vector<uint16_t> sr;
        sr.clear();
        sr.push_back(0xABCD);
        sr.push_back(0xDCBA);
        sr.push_back(0x1234);
        sr.push_back(0x4321);
        libNWK::FieldsNWK fn = libNWK::FieldsNWK(
                                    libNWK::FrameControl(libNWK::Consts::FrameC::FrameType_Data,true,true,true,true,false,true),
                                                        0x0001,
                                                        0x0001,
                                                        1,
                                                        1,
                                                        0x0001,
                                                        0x0001,
                                                        true,
                                                        7,
                                                        7,
                                                        4,
                                                        3,
                                                        sr,
                                                        payload,
                                                        mac);
        //fn.printNWKFields();
        //array[0] = fn;
        libMAC::FieldsMAC mac2 = fn.toMAC();
        std::vector<uint8_t> frame = mac2.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        fn = libNWK::FieldsNWK(
                                    libNWK::FrameControl(libNWK::Consts::FrameC::FrameType_Data,false,false,false,false,false,false),
                                                        0x0002,
                                                        0x0002,
                                                        2,
                                                        2,
                                                        0x0002,
                                                        0x0002,
                                                        false,
                                                        7,
                                                        7,
                                                        4,
                                                        3,
                                                        sr,
                                                        payload,
                                                        mac);
        //fn.printNWKFields();
        //array[1] = fn;
        mac2 = fn.toMAC();
        frame = mac2.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        sr.clear();
        sr.push_back(0x1234);
        sr.push_back(0x1234);
        sr.push_back(0x1234);
        fn = libNWK::FieldsNWK(
                                    libNWK::FrameControl(libNWK::Consts::FrameC::FrameType_NWKCommand,true,true,true,false,true,true),
                                                        0x0003,
                                                        0x0003,
                                                        3,
                                                        3,
                                                        0x0003,
                                                        0x0003,
                                                        true,
                                                        3,
                                                        6,
                                                        3,
                                                        1,
                                                        sr,
                                                        payload,
                                                        mac);
        //fn.printNWKFields();
        //array[2] = fn;
        mac2 = fn.toMAC();
        frame = mac2.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        fn = libNWK::FieldsNWK(
                                    libNWK::FrameControl(libNWK::Consts::FrameC::FrameType_NWKCommand,false,false,false,false,false,false),
                                                        0x0004,
                                                        0x0004,
                                                        4,
                                                        4,
                                                        0x0004,
                                                        0x0004,
                                                        false,
                                                        7,
                                                        7,
                                                        4,
                                                        3,
                                                        sr,
                                                        payload,
                                                        mac);
        //fn.printNWKFields();
        //array[3] = fn;
        mac2 = fn.toMAC();
        frame = mac2.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        fn = libNWK::FieldsNWK(
                                    libNWK::FrameControl(libNWK::Consts::FrameC::FrameType_Data,true,false,true,false,true,false),
                                                        0x0005,
                                                        0x0005,
                                                        5,
                                                        5,
                                                        0x0505,
                                                        0x0505,
                                                        true,
                                                        5,
                                                        5,
                                                        4,
                                                        3,
                                                        sr,
                                                        payload,
                                                        mac);
        //fn.printNWKFields();
        //array[4] = fn;
        mac2 = fn.toMAC();
        frame = mac2.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        fn = libNWK::FieldsNWK(
                                    libNWK::FrameControl(libNWK::Consts::FrameC::FrameType_Data,false,true,false,true,false,true),
                                                        0x0006,
                                                        0x0006,
                                                        6,
                                                        6,
                                                        0x1006,
                                                        0x1006,
                                                        true,
                                                        5,
                                                        5,
                                                        2,
                                                        1,
                                                        sr,
                                                        payload,
                                                        mac);
        //fn.printNWKFields();
        //array[5] = fn;
        mac2 = fn.toMAC();
        frame = mac2.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        fn = libNWK::FieldsNWK(
                                    libNWK::FrameControl(libNWK::Consts::FrameC::FrameType_Data,true,true,true,false,false,false),
                                                        0x0007,
                                                        0x0007,
                                                        7,
                                                        7,
                                                        0x0007,
                                                        0x0007,
                                                        true,
                                                        7,
                                                        7,
                                                        4,
                                                        3,
                                                        sr,
                                                        payload,
                                                        mac);
        //fn.printNWKFields();
        //array[6] = fn;
        mac2 = fn.toMAC();
        frame = mac2.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        fn = libNWK::FieldsNWK(
                                    libNWK::FrameControl(libNWK::Consts::FrameC::FrameType_Data,false,true,false,true,false,true),
                                                        0x0008,
                                                        0x0008,
                                                        8,
                                                        8,
                                                        0x0008,
                                                        0x0008,
                                                        false,
                                                        3,
                                                        3,
                                                        4,
                                                        3,
                                                        sr,
                                                        payload,
                                                        mac);
        //fn.printNWKFields();
        //array[7] = fn;
        mac2 = fn.toMAC();
        frame = mac2.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        fn = libNWK::FieldsNWK(
                                    libNWK::FrameControl(libNWK::Consts::FrameC::FrameType_Data,true,true,false,false,true,true),
                                                        0x0009,
                                                        0x0009,
                                                        9,
                                                        9,
                                                        0x0009,
                                                        0x0009,
                                                        true,
                                                        2,
                                                        2,
                                                        4,
                                                        3,
                                                        sr,
                                                        payload,
                                                        mac);
        //fn.printNWKFields();
        //array[8] = fn;
        mac2 = fn.toMAC();
        frame = mac2.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        fn = libNWK::FieldsNWK(
                                    libNWK::FrameControl(libNWK::Consts::FrameC::FrameType_Data,false,false,true,true,false,false),
                                                        0x0010,
                                                        0x0010,
                                                        10,
                                                        10,
                                                        0x0010,
                                                        0x0010,
                                                        false,
                                                        1,
                                                        1,
                                                        4,
                                                        3,
                                                        sr,
                                                        payload,
                                                        mac);
        //fn.printNWKFields();
        //array[9] = fn;
        mac2 = fn.toMAC();
        frame = mac2.toBytes();
        message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
        sleep(1);
        
        
        /*std::cout << "\n\nTodas las tramas:\n\n" << std::endl;
        for(int i=0; i<10; i++) {
            mac2 = array[i].toMAC();
            frame = mac2.toBytes();
            message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
            sleep(1);
        }*/
        sleep(10);
        
        delete this;
    }

  } /* namespace tfg */
} /* namespace gr */


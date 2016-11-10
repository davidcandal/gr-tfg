/* -*- c++ -*- */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "test_aps_impl.h"
#include "bytes.h"
#include <stdio.h>
#include <string.h>
#include "libNWK.h"

namespace gr {
  namespace tfg {

    test_aps::sptr test_aps::make() {
      return gnuradio::get_initial_sptr (new test_aps_impl());
    }

    test_aps_impl::test_aps_impl() : gr::block("test_aps",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)), hecho(false) {

                    message_port_register_in(pmt::mp("entrada"));
                    message_port_register_out(pmt::mp("salida"));
                    
                    set_msg_handler(pmt::mp("entrada"), boost::bind(&test_aps_impl::msg_handler, this, _1));
    }

    test_aps_impl::~test_aps_impl() {}

    void test_aps_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required) {}

    int test_aps_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items) {

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

    
    void test_aps_impl::msg_handler(pmt::pmt_t msg) {
        
        
        if(hecho) return;
        hecho = true;
        
        
        std::string str = "David";
        std::vector<uint8_t> payload(str.begin(), str.end());
        libAPS::FieldsAPS arrayAPS[10];
        
        
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

        
        libNWK::FieldsNWK fn = libNWK::FieldsNWK(
                                    libNWK::FrameControl(libNWK::Consts::FrameC::FrameType_Data,false,false,false,false,false,false),
                                                        0x0001,
                                                        0x0001,
                                                        1,
                                                        1,
                                                        0x0001,
                                                        0x0001,
                                                        false,
                                                        0,
                                                        0,
                                                        0,
                                                        0,
                                                        std::vector<uint16_t>(),
                                                        std::vector<uint8_t>(),
                                                        mac);
        
        
        
        
        
        //std::cout << "\n\n\n\nListado de tramas APS a comprobar:\n\n";
        
        arrayAPS[0] = libAPS::FieldsAPS(libAPS::FrameControl(libAPS::Consts::FrameC::FrameType_Data,
                                                         libAPS::Consts::FrameC::Mode_Unicast,
                                                         true,true,true,false),
                                                    static_cast<unsigned uint8_t>(1),
                                                    static_cast<unsigned uint16_t>(0x0110),
                                                    static_cast<unsigned uint16_t>(0x1001),
                                                    static_cast<unsigned uint8_t>(11),
                                                    static_cast<unsigned uint8_t>(0x01),
                                                    payload,
                                                    fn);
                                 
        //aps.printAPSFields();
        
        
        arrayAPS[1] = libAPS::FieldsAPS(libAPS::FrameControl(libAPS::Consts::FrameC::FrameType_Data,
                                                         libAPS::Consts::FrameC::Mode_IndUnicast,
                                                         true,true,false,true),
                                                    static_cast<unsigned uint8_t>(2),
                                                    static_cast<unsigned uint16_t>(0x0220),
                                                    static_cast<unsigned uint16_t>(0x2002),
                                                    static_cast<unsigned uint8_t>(22),
                                                    static_cast<unsigned uint8_t>(0x02),
                                                    0,
                                                    static_cast<unsigned uint8_t>(0x02),
                                                    static_cast<unsigned uint8_t>(0x02),
                                                    payload,
                                                    fn);
        //aps.printAPSFields();
        
        
        arrayAPS[2] = libAPS::FieldsAPS(libAPS::FrameControl(libAPS::Consts::FrameC::FrameType_Data,
                                                         libAPS::Consts::FrameC::Mode_Broadcast,
                                                         false,false,false,true),
                                                    static_cast<unsigned uint8_t>(3),
                                                    static_cast<unsigned uint16_t>(0x0330),
                                                    static_cast<unsigned uint16_t>(0x3003),
                                                    static_cast<unsigned uint8_t>(33),
                                                    static_cast<unsigned uint8_t>(0x03),
                                                    1,
                                                    static_cast<unsigned uint8_t>(0x03),
                                                    static_cast<unsigned uint8_t>(0x03),
                                                    payload,
                                                    fn);
        //aps.printAPSFields();
        
        
        arrayAPS[3] = libAPS::FieldsAPS(libAPS::FrameControl(libAPS::Consts::FrameC::FrameType_Data,
                                                         libAPS::Consts::FrameC::Mode_Unicast,
                                                         false,true,false,true),
                                                    static_cast<unsigned uint8_t>(4),
                                                    static_cast<unsigned uint16_t>(0x0440),
                                                    static_cast<unsigned uint16_t>(0x4004),
                                                    static_cast<unsigned uint8_t>(44),
                                                    static_cast<unsigned uint8_t>(0x04),
                                                    2,
                                                    static_cast<unsigned uint8_t>(0x04),
                                                    static_cast<unsigned uint8_t>(0x04),
                                                    payload,
                                                    fn);
        //aps.printAPSFields();
        
        
        arrayAPS[4] = libAPS::FieldsAPS(libAPS::FrameControl(libAPS::Consts::FrameC::FrameType_Data,
                                                         libAPS::Consts::FrameC::Mode_Group,
                                                         true,false,false,true),
                                                    static_cast<unsigned uint16_t>(0x0005),
                                                    static_cast<unsigned uint16_t>(0x0550),
                                                    static_cast<unsigned uint16_t>(0x5005),
                                                    static_cast<unsigned uint8_t>(55),
                                                    static_cast<unsigned uint8_t>(0x05),
                                                    2,
                                                    static_cast<unsigned uint8_t>(0x05),
                                                    static_cast<unsigned uint8_t>(0x05),
                                                    payload,
                                                    fn);
        //aps.printAPSFields();
        
        
        arrayAPS[5] = libAPS::FieldsAPS(libAPS::FrameControl(libAPS::Consts::FrameC::FrameType_Data,
                                                         libAPS::Consts::FrameC::Mode_Group,
                                                         true,false,false,false),
                                                    static_cast<unsigned uint16_t>(0x0006),
                                                    static_cast<unsigned uint16_t>(0x0660),
                                                    static_cast<unsigned uint16_t>(0x6006),
                                                    static_cast<unsigned uint8_t>(66),
                                                    static_cast<unsigned uint8_t>(0x06),
                                                    payload,
                                                    fn);
        //aps.printAPSFields();
        
        
        arrayAPS[6] = libAPS::FieldsAPS(libAPS::FrameControl(libAPS::Consts::FrameC::FrameType_APSCommand,
                                                         libAPS::Consts::FrameC::Mode_Unicast,
                                                         true,false,true,false),
                                                    static_cast<unsigned uint8_t>(0x07),
                                                    static_cast<unsigned uint8_t>(0x07),
                                                    payload,
                                                    fn);
        //aps.printAPSFields();
        
        
        arrayAPS[7] = libAPS::FieldsAPS(libAPS::FrameControl(libAPS::Consts::FrameC::FrameType_APSCommand,
                                                         libAPS::Consts::FrameC::Mode_Broadcast,
                                                         false,true,false,false),
                                                    static_cast<unsigned uint8_t>(0x08),
                                                    static_cast<unsigned uint8_t>(0x08),
                                                    payload,
                                                    fn);
        //aps.printAPSFields();
        
        
        arrayAPS[8] = libAPS::FieldsAPS(libAPS::FrameControl(libAPS::Consts::FrameC::FrameType_APSACK,
                                                         libAPS::Consts::FrameC::Mode_Unicast,
                                                         true,false,true,false),
                                                    static_cast<unsigned uint8_t>(9),
                                                    static_cast<unsigned uint16_t>(0x0990),
                                                    static_cast<unsigned uint16_t>(0x9009),
                                                    static_cast<unsigned uint8_t>(99),
                                                    static_cast<unsigned uint8_t>(0x09),
                                                    payload,
                                                    fn);
                                 
        //aps.printAPSFields();
        
        
        arrayAPS[9] = libAPS::FieldsAPS(libAPS::FrameControl(libAPS::Consts::FrameC::FrameType_APSACK,
                                                         libAPS::Consts::FrameC::Mode_IndUnicast,
                                                         false,false,false,true),
                                                    static_cast<unsigned uint8_t>(10),
                                                    static_cast<unsigned uint16_t>(0x1010),
                                                    static_cast<unsigned uint16_t>(0x0101),
                                                    static_cast<unsigned uint8_t>(10),
                                                    static_cast<unsigned uint8_t>(0x0A),
                                                    2,
                                                    static_cast<unsigned uint8_t>(0x10),
                                                    static_cast<unsigned uint8_t>(0x10),
                                                    payload,
                                                    fn);
        //aps.printAPSFields();
        
        
        
        
        
        
        for(int i=0; i<10; i++) {
                
                libMAC::FieldsMAC mac = arrayAPS[i].toMAC();
                std::vector<uint8_t> frame = mac.toBytes();
                message_port_pub (pmt::mp("salida"), pmt::init_u8vector(frame.size(), &frame[0]));
                sleep(1);
            
        }
        sleep(3);
        
        
        delete this;
    }

  } /* namespace tfg */
} /* namespace gr */
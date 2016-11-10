/* -*- c++ -*- */

#ifndef INCLUDED_LIBNWK_H
#define INCLUDED_LIBNWK_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdint.h>
#include "libMAC.h"

namespace gr {
  namespace tfg {

        class libNWK {


            public:
                
                class FrameControl {

                public:
                //private:
                    int frameType;
                    int protocolVersion;
                    bool discoverRoute;
                    bool multicastFlag;
                    bool security;
                    bool sourceRoute;
                    bool destinationIEEE;
                    bool sourceIEEE;
                    
                //public:
                    FrameControl();
                    
                    FrameControl(int frameType,
                                bool discoverRoute,
                                bool multicastFlag,
                                bool security,
                                bool sourceRoute,
                                bool destinationIEEE,
                                bool sourceIEEE);
                        

                    std::vector<uint8_t> toBytes();
                    void fromBytes(std::vector<uint8_t>);
                };
            

                class FieldsNWK{
                  
                public:
                //private:
                    FrameControl framecontrol;
                    uint16_t destinationAdd;
                    uint16_t sourceAdd;
                    uint8_t radius;
                    uint8_t sequenceNumber;
                    uint64_t destinationIEEE;
                    uint64_t sourceIEEE;
                    bool multicastMember;
                    int multicastRadius;
                    int multicastMaxRadius;
                    uint8_t countSourceRoute;
                    uint8_t indexSourceRoute;
                    std::vector<uint16_t> listSourceRoute;
                    std::vector<uint8_t> payload;
                    libMAC::FieldsMAC fieldsMAC;
		    bool isNWK;
                    
                //public:
                    FieldsNWK();
                                
                    FieldsNWK(FrameControl framecontrol,
                                uint16_t destinationAdd,
                                uint8_t radius,
                                std::vector<uint8_t> payload,
                                libMAC::FieldsMAC fieldsMAC);
                                
                    FieldsNWK(FrameControl framecontrol,
                                uint16_t destinationAdd,
                                uint16_t sourceAdd,
                                uint8_t radius,
                                uint8_t sequenceNumber,
                                uint64_t destinationIEEE,
                                uint64_t sourceIEEE,
                                bool multicastMember,
                                int multicastRadius,
                                int multicastMaxRadius,
                                uint8_t countSourceRoute,
                                uint8_t indexSourceRoute,
                                std::vector<uint16_t> listSourceRoute,
                                std::vector<uint8_t> payload,
                                libMAC::FieldsMAC fieldsMAC);

                    void setFrameControl(FrameControl framecontrol);
                    void setDestinationAdd(uint16_t destinationAdd);
                    void setSourceAdd(uint16_t sourceAdd);
                    void setRadius(uint8_t radius);
                    void setSequenceNumber(uint8_t sequenceNumber);
                    void setDestinationIEEE(uint64_t destinationIEEE);
                    void setSourceIEEE(uint64_t sourceIEEE);
                    void setMulticast(bool multicastMember, int multicastRadius, int multicastMaxRadius);
                    void setSourceRoute (uint8_t countSourceRoute, uint8_t indexSourceRoute, std::vector<uint16_t> listSourceRoute);
                    void setPayload(std::vector<uint8_t> payload);
                    void setFieldsMAC(libMAC::FieldsMAC fieldsMAC);
                            
                            
                    std::vector<uint8_t> toBytes();
                    void fromBytes(std::vector<uint8_t>);
                    void printNWKFields();
                    void reset();
                    
                    libMAC::FieldsMAC toMAC();
                };
                
                
                
                
                class Consts {
                    
                    public: 
                        
                        class FrameC_bytes {
                            public:
                                const static int FrameType_Data = 0x0000;
                                const static int FrameType_NWKCommand = 0x0001;
                                const static int Protocol_V1 = 0x0004;
                                const static int Protocol_V2 = 0x0008;
                                const static int DiscoverRoute_Enabled = 0x0040;
                                const static int DiscoverRoute_Disabled = 0x0000;
                                const static int Multicast_Enabled = 0x0100;
                                const static int Multicast_Disabled = 0x0000;
                                const static int Security_Enabled = 0x0200;
                                const static int Security_Disabled = 0x0000;
                                const static int SourceRoute_Enabled = 0x0400;
                                const static int SourceRoute_Disabled = 0x0000;
                                const static int DestIEEE_Enabled = 0x0800;
                                const static int DestIEEE_Disabled = 0x0000;
                                const static int SrcIEEE_Enabled = 0x1000;
                                const static int SrcIEEE_Disabled = 0x0000;
                        };
                        
                        class FrameC {
                            public:
                                const static int FrameType_Data = 0;
                                const static int FrameType_NWKCommand = 1;
                                const static int Protocol_V1 = 1;
                                const static int Protocol_V2 = 2;
                                const static bool DiscoverRoute_Enabled = true;
                                const static bool DiscoverRoute_Disabled = false;
                                const static bool Multicast_Enabled = true;
                                const static bool Multicast_Disabled = false;
                                const static bool Security_Enabled = true;
                                const static bool Security_Disabled = false;
                                const static bool SourceRoute_Enabled = true;
                                const static bool SourceRoute_Disabled = false;
                                const static bool DestIEEE_Enabled = true;
                                const static bool DestIEEE_Disabled = false;
                                const static bool SrcIEEE_Enabled = true;
                                const static bool SrcIEEE_Disabled = false;
                        };
                        
                };
            
            
        };

  } // namespace tfg
} // namespace gr


#endif

/* -*- c++ -*- */

#ifndef INCLUDED_LIBAPS_H
#define INCLUDED_LIBAPS_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdint.h>
#include "libNWK.h"
#include "libMAC.h"

namespace gr {
  namespace tfg {

      
        class libAPS {

            public:
                
                class FrameControl {

                public:
                //private:
                    int frameType;
                    int deliveryMode;
                    bool ackFormat;
                    bool security;
                    bool ackRequest;
                    bool extHeaderPresent;
                    
                //public:
                    FrameControl();
                    
                    FrameControl(int frameType,
                                 int deliveryMode,
                                 bool ackFormat,
                                 bool security,
                                 bool ackRequest,
                                 bool extHeaderPresent);
                        

                    uint8_t toBytes();
                    void fromBytes(uint8_t);
                };
            

                


                class FieldsAPS{
                        
                    public:
                    //private:
                        FrameControl framecontrol;
                        uint8_t destinationEndpoint;
                        uint16_t groupAdd;
                        uint16_t clusterID;
                        uint16_t profileID;
                        uint8_t sourceEndpoint;
                        uint8_t apsCounter;
                        int fragmentation;
                        uint8_t blockNumber;
                        uint8_t ackBitfield;
                        uint8_t commandID;
                        std::vector<uint8_t> payload;
                        libNWK::FieldsNWK fieldsNWK;
		    	bool isAPS;
                        
                    //public:
                        FieldsAPS();
                                    
                        FieldsAPS(FrameControl framecontrol,
                                    uint8_t destinationEndpoint,
                                    uint16_t groupAdd,
                                    uint16_t clusterID,
                                    uint16_t profileID,
                                    uint8_t sourceEndpoint,
                                    uint8_t apsCounter,
                                    int fragmentation,
                                    uint8_t blockNumber,
                                    uint8_t ackBitfield,
                                    uint8_t commandID,
                                    std::vector<uint8_t> payload,
                                    libNWK::FieldsNWK fieldsNWK
                                 );
                                    
                        FieldsAPS(FrameControl framecontrol,
                                    uint8_t destinationEndpoint,
                                    uint16_t clusterID,
                                    uint16_t profileID,
                                    uint8_t sourceEndpoint,
                                    uint8_t apsCounter,
                                    std::vector<uint8_t> payload,
                                    libNWK::FieldsNWK fieldsNWK
                                 );
                                    
                        FieldsAPS(FrameControl framecontrol,
                                    uint8_t destinationEndpoint,
                                    uint16_t clusterID,
                                    uint16_t profileID,
                                    uint8_t sourceEndpoint,
                                    uint8_t apsCounter,
                                    int fragmentation,
                                    uint8_t blockNumber,
                                    uint8_t ackBitfield,
                                    std::vector<uint8_t> payload,
                                    libNWK::FieldsNWK fieldsNWK
                                 );
                                    
                        FieldsAPS(FrameControl framecontrol,
                                    uint16_t groupAdd,
                                    uint16_t clusterID,
                                    uint16_t profileID,
                                    uint8_t sourceEndpoint,
                                    uint8_t apsCounter,
                                    std::vector<uint8_t> payload,
                                    libNWK::FieldsNWK fieldsNWK
                                 );
                                    
                        FieldsAPS(FrameControl framecontrol,
                                    uint16_t groupAdd,
                                    uint16_t clusterID,
                                    uint16_t profileID,
                                    uint8_t sourceEndpoint,
                                    uint8_t apsCounter,
                                    int fragmentation,
                                    uint8_t blockNumber,
                                    uint8_t ackBitfield,
                                    std::vector<uint8_t> payload,
                                    libNWK::FieldsNWK fieldsNWK
                                 );
                                    
                        FieldsAPS(FrameControl framecontrol,
                                    uint8_t apsCounter,
                                    uint8_t commandID,
                                    std::vector<uint8_t> payload,
                                    libNWK::FieldsNWK fieldsNWK
                                 );
                                
                        
                        void setFrameControl(FrameControl framecontrol);
                        void setDestinationEndpoint(uint8_t destinationEndpoint);
                        void setGroupAddress(uint16_t groupAdd);
                        void setClusterID(uint16_t clusterID);
                        void setProfileID(uint16_t profileID);
                        void setSourceEndpoint(uint8_t sourceEndpoint);
                        void setApsCounter(uint8_t apsCounter);
                        void setFragmentation(int fragmentation);
                        void setBlockNumber(uint8_t blockNumber);
                        void setAckBitfield(uint8_t ackBitfield);
                        void setCommandID(uint8_t commandID);
                        void setPayload(std::vector<uint8_t> payload);
                        void setFieldsNWK(libNWK::FieldsNWK fieldsNWK);
                        
                        std::vector<uint8_t> toBytes();
                        void fromBytes(std::vector<uint8_t>, bool isNWK);
                        void printAPSFields();
                        void reset();
                        
                        libNWK::FieldsNWK toNWK();
                        libMAC::FieldsMAC toMAC();
                    };
                        
                        
                        
                        
                    class Consts {
                        
                        public: 
                            
                            class FrameC_bytes {
                                public:
                                    const static int FrameType_Data = 0x00;
                                    const static int FrameType_APSCommand = 0x01;
                                    const static int FrameType_APSACK = 0x02;
                                    
                                    const static int Mode_Unicast = 0x00;
                                    const static int Mode_IndUnicast = 0x04;
                                    const static int Mode_Broadcast = 0x08;
                                    const static int Mode_Group = 0x0C;
                                    
                                    const static int ACKFormat_Enabled = 0x10;
                                    const static int ACKFormat_Disabled = 0x00;
                                    
                                    const static int Security_Enabled = 0x20;
                                    const static int Security_Disabled = 0x00;
                                    
                                    const static int ACKRequest_Enabled = 0x40;
                                    const static int ACKRequest_Disabled = 0x00;
                                    
                                    const static int ExtHeader_Enabled = 0x80;
                                    const static int ExtHeader_Disabled = 0x00;
                            };
                            
                            class FrameC {
                                public:
                                    const static int FrameType_Data = 0;
                                    const static int FrameType_APSCommand = 1;
                                    const static int FrameType_APSACK = 2;
                                    
                                    const static int Mode_Unicast = 0;
                                    const static int Mode_IndUnicast = 1;
                                    const static int Mode_Broadcast = 2;
                                    const static int Mode_Group = 3;
                                    
                                    const static bool ACKFormat_Enabled = true;
                                    const static bool ACKFormat_Disabled = false;
                                    
                                    const static bool Security_Enabled = true;
                                    const static bool Security_Disabled = false;
                                    
                                    const static bool ACKRequest_Enabled = true;
                                    const static bool ACKRequest_Disabled = false;
                                    
                                    const static bool ExtHeader_Enabled = true;
                                    const static bool ExtHeader_Disabled = false;
                                    
                                    const static int ExtHeader_NotFrag = 0;
                                    const static int ExtHeader_FirstFrag = 1;
                                    const static int ExtHeader_Frag = 2;
                            };
                            
                    };
            
            
        };

  } // namespace tfg
} // namespace gr


#endif

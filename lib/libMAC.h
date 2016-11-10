/* -*- c++ -*- */

#ifndef INCLUDED_LIBMAC_H
#define INCLUDED_LIBMAC_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdint.h>

namespace gr {
  namespace tfg {

        class libMAC {


            public:
                
                class FrameControl {

                public:
                //private:
                    int frameType;
                    bool security;
                    bool framePending;
                    bool ackRequest;
                    bool intraPAN;
                    int destMode;
                    int srcMode;
                    
                //public:
                    FrameControl();
                    
                    FrameControl(int frameType,
                                bool security,
                                bool framePending,
                                bool ackRequest,
                                bool intraPAN,
                                int destMode,
                                int srcMode);
                        

                    std::vector<uint8_t> toBytes();
                    void fromBytes(std::vector<uint8_t>);
                };
            


            class FieldsMAC{
                  
                public:
                //private:
                    FrameControl framecontrol;
                    uint8_t seqNumber;
                    uint16_t destPAN;
                    uint16_t shortDestAddress;
                    uint64_t longDestAddress;
                    uint16_t srcPAN;
                    uint16_t shortSrcAddress;
                    uint64_t longSrcAddress;
                    std::vector<uint8_t> payload;
                    
                //public:
                    FieldsMAC();
                                
                    FieldsMAC(FrameControl framecontrol,
                                uint16_t destPAN,
                                uint16_t shortDestAddress,
                                std::vector<uint8_t> payload);
                    
                    FieldsMAC(FrameControl framecontrol,
                                uint16_t destPAN,
                                uint64_t longDestAddress,
                                std::vector<uint8_t> payload);
                                
                    FieldsMAC(FrameControl framecontrol,
                                uint16_t destPAN,
                                uint16_t shortDestAddress,
                                uint16_t srcPAN,
                                uint16_t shortSrcAddress,
                                std::vector<uint8_t> payload);
                    
                    FieldsMAC(FrameControl framecontrol,
                                uint16_t destPAN,
                                uint64_t longDestAddress,
                                uint64_t longSrcAddress,
                                std::vector<uint8_t> payload);
                                
                    FieldsMAC(FrameControl framecontrol,
                            uint8_t seqNumber,
                            uint16_t destPAN,
                            uint16_t shortDestAddress,
                            uint64_t longDestAddress,
                            uint16_t srcPAN,
                            uint16_t shortSrcAddress,
                            uint64_t longSrcAddress,
                            std::vector<uint8_t> payload);

                    void setFrameControl(FrameControl framecontrol);
                    void setSeqNumber(uint8_t seqNumber);
                    void setDestPAN(uint16_t destPAN);
                    void setShortDestAddress(uint16_t shortDestAddress);
                    void setLongDestAddress(uint64_t longDestAddress);
                    void setSrcPAN(uint16_t srcPAN);
                    void setShortSrcAddress(uint16_t shortSrcAddress);
                    void setLongSrcAddress(uint64_t longSrcAddress);
                    void setPayload(std::vector<uint8_t> payload);
                    static uint16_t makeFCS(uint8_t *buf, int len);
                            
                            
                    std::vector<uint8_t> toBytes();
                    void fromBytes(std::vector<uint8_t>);
                    void printMACFields();
                };
                
                
                
                
                class Consts {
                    
                    public: 
                        
                        class FrameC_bytes {
                            public:
                                const static int FrameType_Beacon = 0x0000;
                                const static int FrameType_Data = 0x0001;
                                const static int FrameType_ACK = 0x00002;
                                const static int FrameType_Command = 0x0003;
                                const static int Security_Enabled = 0x0008;
                                const static int Security_Disabled = 0x0000;
                                const static int Frame_Pending_Enabled = 0x0010;
                                const static int Frame_Pending_Disabled = 0x0000;
                                const static int ACK_Request_Enabled = 0x0020;
                                const static int ACK_Request_Disabled = 0x0000;
                                const static int IntraPAN_Enabled = 0x0040;
                                const static int IntraPAN_Disabled = 0x0000;
                                const static int DestAdd_Mode_Disabled = 0x0000;
                                const static int DestAdd_Mode_ShortAdd = 0x0800;
                                const static int DestAdd_Mode_LongAdd = 0x0C00;
                                const static int SrcAdd_Mode_Disabled = 0x0000;
                                const static int SrcAdd_Mode_ShortAdd = 0x8000;
                                const static int SrcAdd_Mode_LongAdd = 0xC000;
                        };
                        
                        class FrameC {
                            public:
                                const static int FrameType_Beacon = 0;
                                const static int FrameType_Data = 1;
                                const static int FrameType_ACK = 2;
                                const static int FrameType_Command = 3;
                                const static bool Security_Enabled = true;
                                const static bool Security_Disabled = false;
                                const static bool Frame_Pending_Enabled = true;
                                const static bool Frame_Pending_Disabled = false;
                                const static bool ACK_Request_Enabled = true;
                                const static bool ACK_Request_Disabled = false;
                                const static bool IntraPAN_Enabled = true;
                                const static bool IntraPAN_Disabled = false;
                                const static int DestAdd_Mode_Disabled = 0;
                                const static int DestAdd_Mode_ShortAdd = 1;
                                const static int DestAdd_Mode_LongAdd = 2;
                                const static int SrcAdd_Mode_Disabled = 0;
                                const static int SrcAdd_Mode_ShortAdd = 1;
                                const static int SrcAdd_Mode_LongAdd = 2;
                        };
                        
                };
            
            
        };

  } // namespace tfg
} // namespace gr


#endif
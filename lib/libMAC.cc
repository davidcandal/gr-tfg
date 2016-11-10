/* -*- c++ -*- */


#include "libMAC.h"
#include "bytes.h"

namespace gr {
  namespace tfg {

      
      libMAC::FrameControl::FrameControl() : frameType(Consts::FrameC::FrameType_Data),
                        security(false),
                        framePending(false),
                        ackRequest(false),
                        intraPAN(true),
                        destMode(Consts::FrameC::DestAdd_Mode_ShortAdd),
                        srcMode(Consts::FrameC::SrcAdd_Mode_ShortAdd) {};
                        
      libMAC::FrameControl::FrameControl(int frameType,
                                bool security,
                                bool framePending,
                                bool ackRequest,
                                bool intraPAN,
                                int destMode,
                                int srcMode)
                        : frameType(frameType%4),
                        security(security),
                        framePending(framePending),
                        ackRequest(ackRequest),
                        intraPAN(intraPAN),
                        destMode(destMode),
                        srcMode(srcMode) {};



      std::vector<uint8_t> libMAC::FrameControl::toBytes(){
                       
                       int aux = 0;
                       
                       if(this->frameType == Consts::FrameC::FrameType_Data){
                           aux += Consts::FrameC_bytes::FrameType_Data;
                       }
                       else if(this->frameType == Consts::FrameC::FrameType_ACK){
                           aux += Consts::FrameC_bytes::FrameType_ACK;
                       }
                       else if(this->frameType == Consts::FrameC::FrameType_Command){
                           aux += Consts::FrameC_bytes::FrameType_Command;
                       }
                       
                       if(this->security == Consts::FrameC::Security_Enabled){
                           aux += Consts::FrameC_bytes::Security_Enabled;
                       }
                       
                       if(this->framePending == Consts::FrameC::Frame_Pending_Enabled){
                           aux += Consts::FrameC_bytes::Frame_Pending_Enabled;
                       }
                       
                       if(this->ackRequest == Consts::FrameC::ACK_Request_Enabled){
                           aux += Consts::FrameC_bytes::ACK_Request_Enabled;
                       }
                       
                       if(this->intraPAN == Consts::FrameC::IntraPAN_Enabled){
                           aux += Consts::FrameC_bytes::IntraPAN_Enabled;
                       }
                       
                       if(this->destMode == Consts::FrameC::DestAdd_Mode_ShortAdd){
                           aux += Consts::FrameC_bytes::DestAdd_Mode_ShortAdd;
                       }
                       else if(this->destMode == Consts::FrameC::DestAdd_Mode_LongAdd){
                           aux += Consts::FrameC_bytes::DestAdd_Mode_LongAdd;
                       }
                       
                       if(this->srcMode == Consts::FrameC::SrcAdd_Mode_ShortAdd){
                           aux += Consts::FrameC_bytes::SrcAdd_Mode_ShortAdd;
                       }
                       else if(this->srcMode == Consts::FrameC::SrcAdd_Mode_LongAdd){
                           aux += Consts::FrameC_bytes::SrcAdd_Mode_LongAdd;
                       }

                       return int2Bytes(aux, 2);
                   };
        
        
        void libMAC::FrameControl::fromBytes(std::vector<uint8_t> frame){
            
            uint8_t aux = frame.at(0);
            this->frameType = (aux & 0x07);
            aux = (aux >> 3);
            this->security = (aux & 0x01);
            aux = (aux >> 1);
            this->framePending = (aux & 0x01);
            aux = (aux >> 1);
            this->ackRequest = (aux & 0x01);
            aux = (aux >> 1);
            this->intraPAN = (aux & 0x01);
            
            aux = frame.at(1);
            aux = (aux >> 2);
            this->destMode = ((aux & 0x03) > 0) ? ((aux & 0x03)-1):0;
            aux = (aux >> 4);
            this->srcMode = ((aux & 0x03) > 0) ? ((aux & 0x03)-1):0;
        };
                   
                   
                   
        libMAC::FieldsMAC::FieldsMAC()
                    : destPAN(0xABCD), shortDestAddress(0x0001) {};
        
        libMAC::FieldsMAC::FieldsMAC(FrameControl framecontrol,
                    uint16_t destPAN,
                    uint16_t shortDestAddress,
                    std::vector<uint8_t> payload)
                    : framecontrol(framecontrol), seqNumber(-1), destPAN(destPAN), shortDestAddress(shortDestAddress) {
                    this->payload.clear();
                    this->payload.reserve(payload.size());
                    this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
        };
        
        libMAC::FieldsMAC::FieldsMAC(FrameControl framecontrol,
                    uint16_t destPAN,
                    uint64_t longDestAddress,
                    std::vector<uint8_t> payload)
                    : framecontrol(framecontrol), seqNumber(-1), destPAN(destPAN), longDestAddress(longDestAddress) {
                    this->payload.clear();
                    this->payload.reserve(payload.size());
                    this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
        };
                    
        libMAC::FieldsMAC::FieldsMAC(FrameControl framecontrol,
                    uint16_t destPAN,
                    uint16_t shortDestAddress,
                    uint16_t srcPAN,
                    uint16_t shortSrcAddress,
                    std::vector<uint8_t> payload)
                    : framecontrol(framecontrol), seqNumber(-1), destPAN(destPAN), shortDestAddress(shortDestAddress), srcPAN(srcPAN), shortSrcAddress(shortSrcAddress) {
                    this->payload.clear();
                    this->payload.reserve(payload.size());
                    this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
        };
        
        libMAC::FieldsMAC::FieldsMAC(FrameControl framecontrol,
                    uint16_t destPAN,
                    uint64_t longDestAddress,
                    uint64_t longSrcAddress,
                    std::vector<uint8_t> payload)
                    : framecontrol(framecontrol), seqNumber(-1), destPAN(destPAN), longDestAddress(longDestAddress), longSrcAddress(longSrcAddress) {
                    this->payload.clear();
                    this->payload.reserve(payload.size());
                    this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
        };
                    
        libMAC::FieldsMAC::FieldsMAC(FrameControl framecontrol,
                uint8_t seqNumber,
                uint16_t destPAN,
                uint16_t shortDestAddress,
                uint64_t longDestAddress,
                uint16_t srcPAN,
                uint16_t shortSrcAddress,
                uint64_t longSrcAddress,
                std::vector<uint8_t> payload)
                    : framecontrol(framecontrol), seqNumber(seqNumber), destPAN(destPAN), shortDestAddress(shortDestAddress), srcPAN(srcPAN),
                        shortSrcAddress(shortSrcAddress), longDestAddress(longDestAddress), longSrcAddress(longSrcAddress) {
                    this->payload.clear();
                    this->payload.reserve(payload.size());
                    this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
        };

        void libMAC::FieldsMAC::setFrameControl(FrameControl framecontrol){
            this->framecontrol = framecontrol;
        };
        void libMAC::FieldsMAC::setSeqNumber(uint8_t seqNumber){
            this->seqNumber = seqNumber;
        };
        void libMAC::FieldsMAC::setDestPAN(uint16_t destPAN){
            this->destPAN = destPAN;
        };
        void libMAC::FieldsMAC::setShortDestAddress(uint16_t shortDestAddress){
            this->shortDestAddress = shortDestAddress;
        };
        void libMAC::FieldsMAC::setLongDestAddress(uint64_t longDestAddress){
            this->longDestAddress = longDestAddress;
        };
        void libMAC::FieldsMAC::setSrcPAN(uint16_t srcPAN){
            this->srcPAN = srcPAN;
        };
        void libMAC::FieldsMAC::setShortSrcAddress(uint16_t shortSrcAddress){
            this->shortSrcAddress = shortSrcAddress;
        };
        void libMAC::FieldsMAC::setLongSrcAddress(uint64_t longSrcAddress){
            this->longSrcAddress = longSrcAddress;
        };
        void libMAC::FieldsMAC::setPayload(std::vector<uint8_t> payload){
            this->payload.clear();
            this->payload.reserve(payload.size());
            this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
        };
                    
                    
        
        
                
                
        std::vector<uint8_t> libMAC::FieldsMAC::toBytes(){
            
            std::vector<uint8_t> frame;
            int tam = 5;
            
            if(this->framecontrol.destMode == Consts::FrameC::DestAdd_Mode_ShortAdd)
                tam += 4;
            else if(this->framecontrol.destMode == Consts::FrameC::DestAdd_Mode_LongAdd)
                tam += 10;
            
            if(this->framecontrol.intraPAN == 0)
                tam += 2;
            if(this->framecontrol.srcMode == Consts::FrameC::SrcAdd_Mode_ShortAdd)
                tam +=2;
            else if(this->framecontrol.srcMode == Consts::FrameC::SrcAdd_Mode_LongAdd)
                tam += 8;
            
            tam += sizeof(this->payload);
            frame.reserve(tam);
            
            
            std::vector<uint8_t> fc = this->framecontrol.toBytes();
            frame = appendVector(frame, fc);
            
            frame = appendInt(frame, this->seqNumber, 1);
            
            if(this->framecontrol.destMode == Consts::FrameC::DestAdd_Mode_ShortAdd){
                frame = appendInt(frame, this->destPAN, 2);
                frame = appendInt(frame, this->shortDestAddress, 2);
            }
            
            else if(this->framecontrol.destMode == Consts::FrameC::DestAdd_Mode_LongAdd){
                frame = appendInt(frame, this->destPAN, 2);
                frame = append64Int(frame, this->longDestAddress, 8);
            }
            
            if((this->framecontrol.intraPAN == 0) && (this->framecontrol.srcMode != Consts::FrameC::SrcAdd_Mode_Disabled))
                frame = appendInt(frame, this->srcPAN, 2);
            
            if(this->framecontrol.srcMode == Consts::FrameC::SrcAdd_Mode_ShortAdd)
                frame = appendInt(frame, this->shortSrcAddress, 2);
            
            else if(this->framecontrol.srcMode == Consts::FrameC::SrcAdd_Mode_LongAdd)
                frame = append64Int(frame, this->longSrcAddress, 8);
            
            frame.insert(frame.end(), this->payload.begin(), this->payload.end());
            
            uint16_t fcs = makeFCS(&frame[0], frame.size());
            frame = appendInt(frame, fcs, 2);
            //printVectorHexaValue(frame);

            return frame;
        };
        
        
        void libMAC::FieldsMAC::fromBytes(std::vector<uint8_t> frame){
            
            
            destPAN = 0;
            shortDestAddress = 0;
            longDestAddress = 0;
            srcPAN = 0;
            shortSrcAddress = 0;
            longSrcAddress = 0;
            int pos = 3;
                    

            std::vector<uint8_t>::iterator i=frame.begin();
            
            std::vector<uint8_t> fc (i, i+2);
            (this->framecontrol).fromBytes(fc);
            
            this->seqNumber = frame.at(2);
            
            if(this->framecontrol.destMode == Consts::FrameC::DestAdd_Mode_ShortAdd){
                this->destPAN = frame.at(3) + (frame.at(4) << 8);
                this->shortDestAddress = frame.at(5) + (frame.at(6) << 8);
                pos = 7;
            }
            
            else if(this->framecontrol.destMode == Consts::FrameC::DestAdd_Mode_LongAdd){
                this->destPAN = frame.at(3) + (frame.at(4) << 8);
                this->longDestAddress = frame.at(9) + (frame.at(10) << 8) + (frame.at(11) << 16) + (frame.at(12) << 24);
                this->longDestAddress = (this->longDestAddress << 32) + frame.at(5) + (frame.at(6) << 8) + (frame.at(7) << 16) + unsigned((frame.at(8) << 24));
                pos = 13;
            }
            
            if((this->framecontrol.intraPAN == 0) && (this->framecontrol.srcMode != Consts::FrameC::SrcAdd_Mode_Disabled)){
                this->srcPAN = frame.at(pos) + (frame.at(pos+1) << 8);
                pos +=2;
            }
            
            if(this->framecontrol.srcMode == Consts::FrameC::SrcAdd_Mode_ShortAdd){
                this->shortSrcAddress = frame.at(pos) + (frame.at(pos+1) << 8);
                pos += 2;
            }
            
            else if(this->framecontrol.srcMode == Consts::FrameC::SrcAdd_Mode_LongAdd){
                this->longSrcAddress = frame.at(pos+4) + (frame.at(pos+5) << 8) + (frame.at(pos+6) << 16) + (frame.at(pos+7) << 24);
                this->longSrcAddress = (this->longSrcAddress << 32) + frame.at(pos) + (frame.at(pos+1) << 8) + (frame.at(pos+2) << 16) + unsigned((frame.at(pos+3) << 24));
                pos += 8;
            }
            
            
            (this->payload).clear();
            (this->payload).reserve(frame.size() -2 - pos);
            for(pos; pos<(frame.size()-2); pos++)
                (this->payload).push_back(frame.at(pos));
        };
        
        uint16_t libMAC::FieldsMAC::makeFCS(uint8_t *buf, int len) {
            
            uint16_t fcs = 0;

            for(int i = 0; i < len; i++) {
                for(int k = 0; k < 8; k++) {
                    
                    int input_bit = (!!(buf[i] & (1 << k)) ^ (fcs & 1));
                    fcs = fcs >> 1;
                    
                    if(input_bit) {
                        fcs ^= (1 << 15);
                        fcs ^= (1 << 10);
                        fcs ^= (1 <<  3);
                    }
                }
            }

            return fcs;
}
        
        
        void libMAC::FieldsMAC::printMACFields(){
        
            std::cout << "\n\n\tFrame control:\n";
            std::cout << "\t\tTipo de trama: " << (this->framecontrol).frameType << "\n";
            std::cout << "\t\tSeguridad: " << (this->framecontrol).security << "\n";
            std::cout << "\t\tTrama pendiente: " << (this->framecontrol).framePending << "\n";
            std::cout << "\t\tPetición de ACK: " << (this->framecontrol).ackRequest << "\n";
            std::cout << "\t\tIntraPAN: " << (this->framecontrol).intraPAN << "\n";
            std::cout << "\t\tModo de dirección (destino): " << (this->framecontrol).destMode << "\n";
            std::cout << "\t\tModo de dirección (origen): " << (this->framecontrol).srcMode << "\n";
            
            std::cout << "\n\tNúmero de secuencia: " << unsigned(this->seqNumber) << "\n";
            if(this->destPAN > 0){
                std::cout << "\tDirección PAN destino: "; printByteHexaValue(this->destPAN);
            }
            if(this->longDestAddress > 0 || this->shortDestAddress > 0){
                std::cout << "\tDirección MAC destino: "; (this->longDestAddress > this->shortDestAddress ? printByteHexaValue(this->longDestAddress) : printByteHexaValue(this->shortDestAddress));
            }
            if(this->srcPAN > 0){
                std::cout << "\tDirección PAN origen: "; printByteHexaValue(this->srcPAN);
            }
            if(this->longSrcAddress > 0 || this->shortSrcAddress > 0){
                std::cout << "\tDirección MAC origen: "; (this->longSrcAddress > this->shortSrcAddress ? printByteHexaValue(this->longSrcAddress) : printByteHexaValue(this->shortSrcAddress));
            }
            std::cout << "\tCarga: ";printVectorHexaValue(this->payload);
            std::cout << "\n\n" << std::endl;
        }

  } // namespace tfg
} // namespace gr

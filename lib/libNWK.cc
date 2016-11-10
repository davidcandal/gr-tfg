/* -*- c++ -*- */


#include "libNWK.h"
#include "bytes.h"

namespace gr {
  namespace tfg {

      
      libNWK::FrameControl::FrameControl() : frameType(Consts::FrameC::FrameType_Data),
                        protocolVersion(Consts::FrameC::Protocol_V2),
                        discoverRoute(false),
                        multicastFlag(false),
                        security(false),
                        sourceRoute(false),
                        destinationIEEE(false),
                        sourceIEEE(false) {};
                        
      libNWK::FrameControl::FrameControl(int frameType,
                                bool discoverRoute,
                                bool multicastFlag,
                                bool security,
                                bool sourceRoute,
                                bool destinationIEEE,
                                bool sourceIEEE)
                        : frameType(frameType%2),
                        protocolVersion(Consts::FrameC::Protocol_V2),
                        discoverRoute(discoverRoute),
                        multicastFlag(multicastFlag),
                        security(security),
                        sourceRoute(sourceRoute),
                        destinationIEEE(destinationIEEE),
                        sourceIEEE(sourceIEEE) {};



      std::vector<uint8_t> libNWK::FrameControl::toBytes(){
                       
                       int aux = 0;
                       
                       if(this->frameType == Consts::FrameC::FrameType_NWKCommand){
                           aux += Consts::FrameC_bytes::FrameType_NWKCommand;
                       }
                       
                       aux += Consts::FrameC_bytes::Protocol_V2;
                       
                       if(this->discoverRoute == Consts::FrameC::DiscoverRoute_Enabled){
                           aux += Consts::FrameC_bytes::DiscoverRoute_Enabled;
                       }
                       
                       if(this->multicastFlag == Consts::FrameC::Multicast_Enabled){
                           aux += Consts::FrameC_bytes::Multicast_Enabled;
                       }
                       
                       if(this->security == Consts::FrameC::Security_Enabled){
                           aux += Consts::FrameC_bytes::Security_Enabled;
                       }
                       
                       if(this->sourceRoute == Consts::FrameC::SourceRoute_Enabled){
                           aux += Consts::FrameC_bytes::SourceRoute_Enabled;
                       }
                       
                       if(this->destinationIEEE == Consts::FrameC::DestIEEE_Enabled){
                           aux += Consts::FrameC_bytes::DestIEEE_Enabled;
                       }
                       
                       if(this->sourceIEEE == Consts::FrameC::SrcIEEE_Enabled){
                           aux += Consts::FrameC_bytes::SrcIEEE_Enabled;
                       }

                       std::vector<uint8_t> x = int2Bytes(aux, 2);
                       
                       return int2Bytes(aux, 2);
                   };
        
        
        void libNWK::FrameControl::fromBytes(std::vector<uint8_t> frame){
            
            uint8_t aux = frame.at(0);
            this->frameType = (aux & 0x03);
            aux = (aux >> 2);
            this->protocolVersion = (aux & 0x0F);
            aux = (aux >> 4);
            this->discoverRoute = (aux & 0x03);
            
            aux = frame.at(1);
            this->multicastFlag = (aux & 0x01);
            aux = (aux >> 1);
            this->security = (aux & 0x01);
            aux = (aux >> 1);
            this->sourceRoute = (aux & 0x01);
            aux = (aux >> 1);
            this->destinationIEEE = (aux & 0x01);
            aux = (aux >> 1);
            this->sourceIEEE = (aux & 0x01);
        };
                   
                   
                   
        libNWK::FieldsNWK::FieldsNWK()
                : destinationAdd(0x0001), radius(7), multicastMember(false), isNWK(false) {
                                this->payload.clear();
                                this->fieldsMAC = libMAC::FieldsMAC();
                        }
                                
        libNWK::FieldsNWK::FieldsNWK(FrameControl framecontrol,
                    uint16_t destinationAdd,
                    uint8_t radius,
                    std::vector<uint8_t> payload,
                    libMAC::FieldsMAC fieldsMAC)
                : framecontrol(framecontrol),
                destinationAdd(destinationAdd),
                radius(radius),
                multicastMember(false),
                fieldsMAC(fieldsMAC),
		isNWK(true) {
                    this->payload.clear();
                    this->payload.reserve(payload.size());
                    this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
                };
                    
        libNWK::FieldsNWK::FieldsNWK(FrameControl framecontrol,
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
                    libMAC::FieldsMAC fieldsMAC)
                : framecontrol(framecontrol),
                destinationAdd(destinationAdd),
                sourceAdd(sourceAdd),
                radius(radius),
                sequenceNumber(sequenceNumber),
                destinationIEEE(destinationIEEE),
                sourceIEEE(sourceIEEE),
                multicastMember(multicastMember),
                multicastRadius(multicastRadius%8),
                multicastMaxRadius(multicastMaxRadius%8),
                countSourceRoute(countSourceRoute),
                indexSourceRoute(indexSourceRoute),
                fieldsMAC(fieldsMAC),
		isNWK(true) {
                    this->listSourceRoute.clear();
                    this->listSourceRoute.reserve(listSourceRoute.size());
                    this->listSourceRoute.insert((this->listSourceRoute).begin(), listSourceRoute.begin(), listSourceRoute.end());
                    this->payload.clear();
                    this->payload.reserve(payload.size());
                    this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
                };

        void libNWK::FieldsNWK::setFrameControl(FrameControl framecontrol){
            this->framecontrol = framecontrol;
        };
        void libNWK::FieldsNWK::setDestinationAdd(uint16_t destinationAdd){
            this->destinationAdd = destinationAdd;
        };
        void libNWK::FieldsNWK::setSourceAdd(uint16_t sourceAdd){
            this->sourceAdd = sourceAdd;
        };
        void libNWK::FieldsNWK::setRadius(uint8_t radius){
            this->radius = radius;
        };
        void libNWK::FieldsNWK::setSequenceNumber(uint8_t sequenceNumber){
            this->sequenceNumber = sequenceNumber;
        };
        void libNWK::FieldsNWK::setDestinationIEEE(uint64_t destinationIEEE){
            this->destinationIEEE = destinationIEEE;
        };
        void libNWK::FieldsNWK::setSourceIEEE(uint64_t sourceIEEE){
            this->sourceIEEE = sourceIEEE;
        };
        void libNWK::FieldsNWK::setMulticast(bool multicastMember, int multicastRadius, int multicastMaxRadius){
            this->multicastMember = multicastMember;
            this->multicastRadius = multicastRadius%8;
            this->multicastMaxRadius = multicastMaxRadius%8;
        };
        void libNWK::FieldsNWK::setSourceRoute (uint8_t countSourceRoute, uint8_t indexSourceRoute, std::vector<uint16_t> listSourceRoute){
            this->countSourceRoute = countSourceRoute;
            this->indexSourceRoute = indexSourceRoute;
            this->listSourceRoute.clear();
            this->listSourceRoute.reserve(listSourceRoute.size());
            this->listSourceRoute.insert((this->listSourceRoute).begin(), listSourceRoute.begin(), listSourceRoute.end());
        };
        void libNWK::FieldsNWK::setPayload(std::vector<uint8_t> payload){
            this->payload.clear();
            this->payload.reserve(payload.size());
            this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
        };
        void libNWK::FieldsNWK::setFieldsMAC(libMAC::FieldsMAC fieldsMAC){
            this->fieldsMAC = fieldsMAC;
        }
        
        void libNWK::FieldsNWK::reset(){
	    this->framecontrol = FrameControl();
            this->destinationAdd = 0;
            this->sourceAdd = 0;
            this->radius = 0;
            this->sequenceNumber = 0;
            this->destinationIEEE = 0;
            this->sourceIEEE = 0;
            this->multicastMember = 0;
            this->multicastRadius = 0;
            this->multicastMaxRadius = 0;
            this->countSourceRoute = 0;
            this->indexSourceRoute = 0;
            this->listSourceRoute.clear();
            this->payload.clear();
            this->fieldsMAC = libMAC::FieldsMAC();
        }
        
        
        libMAC::FieldsMAC libNWK::FieldsNWK::toMAC(){
            
            std::vector<uint8_t> frame = this->toBytes();
            libMAC::FieldsMAC mac = libMAC::FieldsMAC(this->fieldsMAC.framecontrol,
                                        this->fieldsMAC.seqNumber,
                                        this->fieldsMAC.destPAN,
                                        this->fieldsMAC.shortDestAddress,
                                        this->fieldsMAC.longDestAddress,
                                        this->fieldsMAC.srcPAN,
                                        this->fieldsMAC.shortSrcAddress,
                                        this->fieldsMAC.longSrcAddress,
                                        frame);
            
            return mac;
        }
        
        
                
                
        std::vector<uint8_t> libNWK::FieldsNWK::toBytes(){

	    std::vector<uint8_t> frame;
            
	    if(!this->isNWK) {
		frame.reserve(sizeof(this->payload));
		frame.insert(frame.end(), this->payload.begin(), this->payload.end());
                return frame;
	    }

            if(this->countSourceRoute > this->listSourceRoute.size())
                this->countSourceRoute = this->listSourceRoute.size();
            if((this->framecontrol.sourceRoute == 1) && (this->countSourceRoute < 1))
                this->framecontrol.sourceRoute == 0;
            if((this->framecontrol.sourceRoute == 1) && (this->indexSourceRoute >= this->countSourceRoute))
                this->indexSourceRoute = this->countSourceRoute - 1;
            
            
            int tam = 8;
            
            if(this->framecontrol.destinationIEEE)
                tam += 8;
            if(this->framecontrol.sourceIEEE)
                tam += 8;
            if(this->framecontrol.multicastFlag)
                tam++;
            if(this->framecontrol.sourceRoute)
                tam += 2 + (2 * this->countSourceRoute);
            tam += sizeof(this->payload);
            frame.reserve(tam);
            
            
            std::vector<uint8_t> fc = this->framecontrol.toBytes();
            frame = appendVector(frame, fc);
            
            frame = appendInt(frame, this->destinationAdd, 2);
            frame = appendInt(frame, this->sourceAdd, 2);
            frame = appendInt(frame, this->radius, 1);
            frame = appendInt(frame, this->sequenceNumber, 1);
            
            
            if(this->framecontrol.destinationIEEE)
                frame = append64Int(frame, this->destinationIEEE, 8);
            
            if(this->framecontrol.sourceIEEE)
                frame = append64Int(frame, this->sourceIEEE, 8);
            
            if(this->framecontrol.multicastFlag){
                int aux = (this->multicastMaxRadius) << 5;
                aux += (this->multicastRadius) << 2;
                if(this->multicastMember) aux += 1;
                frame = appendInt(frame, aux, 1);
            }
            
            if(this->framecontrol.sourceRoute){
                
                frame = appendInt(frame, this->countSourceRoute, 1);
                frame = appendInt(frame, this->indexSourceRoute, 1);
                int aux2 = this->countSourceRoute;
                
                for(std::vector<uint16_t>::iterator i=this->listSourceRoute.begin(); (i!=this->listSourceRoute.end() && aux2>0); ++i){
                    frame = appendInt(frame, static_cast<unsigned int>(*i), 2);
                    aux2--;
                }
                
                while(aux2>0){
                    frame = appendInt(frame, this->destinationAdd, 2);
                    aux2--;
                }
            }

            frame.insert(frame.end(), this->payload.begin(), this->payload.end());
            
            //printVectorHexaValue(frame);

            return frame;
        };
        
        
        void libNWK::FieldsNWK::fromBytes(std::vector<uint8_t> frame){
            
            this->reset();
            std::vector<uint8_t>::iterator i=frame.begin();

		if(frame.size() < 8){
		    this->isNWK = false;
		    (this->payload).clear();
            	    (this->payload).reserve(frame.size());
		    (this->payload).insert((this->payload).end(), frame.begin(), frame.end());
		    return;
		}
		else this->isNWK = true;
            
            std::vector<uint8_t> fc (i, i+2);
            (this->framecontrol).fromBytes(fc);
            
            this->destinationAdd = frame.at(2) + (frame.at(3) << 8);
            this->sourceAdd = frame.at(4) + (frame.at(5) << 8);
            this->radius = frame.at(6);
            this->sequenceNumber = frame.at(7);
            
            int position = 8;
            if(this->framecontrol.destinationIEEE) {
                this->destinationIEEE = frame.at(position+4) + (frame.at(position+5) << 8) + (frame.at(position+6) << 16) + (frame.at(position+7) << 24);
                this->destinationIEEE = (this->destinationIEEE << 32) + frame.at(position) + (frame.at(position+1) << 8) + (frame.at(position+2) << 16) + unsigned((frame.at(position+3) << 24));
                position += 8;
            }
            else this->destinationIEEE = 0;
            
            if(this->framecontrol.sourceIEEE) {
                this->sourceIEEE = frame.at(position+4) + (frame.at(position+5) << 8) + (frame.at(position+6) << 16) + (frame.at(position+7) << 24);
                this->sourceIEEE = (this->sourceIEEE << 32) +  frame.at(position) + (frame.at(position+1) << 8) + (frame.at(position+2) << 16) + unsigned((frame.at(position+3) << 24));
                position += 8;
            }
            else this->sourceIEEE = 0;
            
            if(this->framecontrol.multicastFlag) {
                int aux = frame.at(position);
                this->multicastMember = (aux & 0x03);
                this->multicastRadius = (aux & 0x1C) >> 2;
                this->multicastMaxRadius = (aux & 0xE0) >> 5;
                position++;
            }
            else {
                this->multicastMember = 0;
                this->multicastRadius = 0;
                this->multicastMaxRadius = 0;
            }
            
            if(this->framecontrol.sourceRoute){
                
                this->countSourceRoute = frame.at(position);
                this->indexSourceRoute = frame.at(position+1);
                
                position+=2;
                (this->listSourceRoute).clear();
                (this->listSourceRoute).reserve(this->countSourceRoute);
                for(int i=0; i<this->countSourceRoute; i++){
                    (this->listSourceRoute).push_back(frame.at(position) + (frame.at(position+1) << 8));
                    position+=2;
                }
            }
            else {
                this->countSourceRoute = 0;
                this->indexSourceRoute = 0;
                (this->listSourceRoute).clear();
            }
            
            (this->payload).clear();
            (this->payload).reserve(frame.size() - position);
            for(position; position<frame.size(); position++)
                (this->payload).push_back(frame.at(position));
        };
        
        
        void libNWK::FieldsNWK::printNWKFields(){
        
		if(this->isNWK){
		    std::cout << "\n\n\tFrame control:\n";
		    std::cout << "\t\tTipo de trama: " << (this->framecontrol).frameType << "\n";
		    std::cout << "\t\tVersión: " << (this->framecontrol).protocolVersion << "\n";
		    std::cout << "\t\tDescubrimiento de ruta: " << (this->framecontrol).discoverRoute << "\n";
		    std::cout << "\t\tMulticast: " << (this->framecontrol).multicastFlag << "\n";
		    std::cout << "\t\tSeguridad: " << (this->framecontrol).security << "\n";
		    std::cout << "\t\tSource route: " << (this->framecontrol).sourceRoute << "\n";
		    std::cout << "\t\tIEEE destino: " << (this->framecontrol).destinationIEEE << "\n";
		    std::cout << "\t\tIEEE origen: " << (this->framecontrol).sourceIEEE << "\n";
		    
		    std::cout << "\n\tDirección NWK destino: "; printByteHexaValue(this->destinationAdd);
		    std::cout << "\tDirección NWK origen: "; printByteHexaValue(this->sourceAdd);
		    std::cout << "\tRadio: " << unsigned(this->radius) << "\n";
		    std::cout << "\tNúmero de secuencia: " << unsigned(this->sequenceNumber) << "\n";
		    if((this->framecontrol).destinationIEEE){
		        std::cout << "\tDirección IEEE destino: "; printByteHexaValue(this->destinationIEEE);
		    }
		    if((this->framecontrol).sourceIEEE){
		        std::cout << "\tDirección IEEE origen: "; printByteHexaValue(this->sourceIEEE);
		    }
		    if((this->framecontrol).multicastFlag){
		        std::cout << "\tMulticast:\n";
		        std::cout << "\t\tMiembro: " << this->multicastMember << "\n";
		        std::cout << "\t\tRadio: " << this->multicastRadius << "\n";
		        std::cout << "\t\tRadio maximo: " << this->multicastMaxRadius << "\n";
		    }
		    if((this->framecontrol).sourceRoute){
		        std::cout << "\tSource route: \n";
		        std::cout << "\t\tContador: " << unsigned(this->countSourceRoute) << "\n";
		        std::cout << "\t\tIndice: " << unsigned(this->indexSourceRoute) << "\n";
		        std::cout << "\t\tLista: ";printVectorHexaValue(this->listSourceRoute);
		    }
		    std::cout << "\n\tCarga: ";printVectorHexaValue(this->payload);
		}
		else std::cout << "\n\n\tCarga: ";printVectorHexaValue(this->payload);

		std::cout << "\n\n" << std::endl;
        }

  } // namespace tfg
} // namespace gr

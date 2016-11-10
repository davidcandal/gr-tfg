/* -*- c++ -*- */


#include "libAPS.h"
#include "bytes.h"
#include <cstring>

namespace gr {
  namespace tfg {

      
      libAPS::FrameControl::FrameControl()
                        : frameType(Consts::FrameC::FrameType_Data),
                        deliveryMode(Consts::FrameC::Mode_Unicast),
                        ackFormat(false),
                        security(false),
                        ackRequest(false),
                        extHeaderPresent(false) {}
                        
      libAPS::FrameControl::FrameControl(int frameType,
                                 int deliveryMode,
                                 bool ackFormat,
                                 bool security,
                                 bool ackRequest,
                                 bool extHeaderPresent)
                        : frameType(frameType%4),
                        deliveryMode(deliveryMode%4),
                        ackFormat(ackFormat),
                        security(security),
                        ackRequest(ackRequest),
                        extHeaderPresent(extHeaderPresent) {}



      uint8_t libAPS::FrameControl::toBytes(){
                       
            int aux = 0;
            
            if(this->frameType == Consts::FrameC::FrameType_APSCommand) {
                aux += Consts::FrameC_bytes::FrameType_APSCommand;
            }
            else if(this->frameType == Consts::FrameC::FrameType_APSACK) {
                aux += Consts::FrameC_bytes::FrameType_APSACK;
            }
            
            switch(this->deliveryMode) {
                case Consts::FrameC::Mode_IndUnicast:
                    aux += Consts::FrameC_bytes::Mode_IndUnicast;
                    break;
                case Consts::FrameC::Mode_Broadcast:
                    aux += Consts::FrameC_bytes::Mode_Broadcast;
                    break;
                case Consts::FrameC::Mode_Group:
                    aux += Consts::FrameC_bytes::Mode_Group;
                    break;
            }
            
            if(this->ackFormat == Consts::FrameC::ACKFormat_Enabled){
                aux += Consts::FrameC_bytes::ACKFormat_Enabled;
            }
            
            if(this->security == Consts::FrameC::Security_Enabled){
                aux += Consts::FrameC_bytes::Security_Enabled;
            }
            
            if(this->ackRequest == Consts::FrameC::ACKRequest_Enabled){
                aux += Consts::FrameC_bytes::ACKRequest_Enabled;
            }
            
            if(this->extHeaderPresent == Consts::FrameC::ExtHeader_Enabled){
                aux += Consts::FrameC_bytes::ExtHeader_Enabled;
            }

            
            return (aux & 0xFF);
        }
        
        
        void libAPS::FrameControl::fromBytes(uint8_t frame){
            
            this->frameType = (frame & 0x03);
            frame = (frame >> 2);
            this->deliveryMode = (frame & 0x03);
            frame = (frame >> 2);
            this->ackFormat = (frame & 0x01);
            frame = (frame >> 1);
            this->security = (frame & 0x01);
            frame = (frame >> 1);
            this->ackRequest = (frame & 0x01);
            frame = (frame >> 1);
            this->extHeaderPresent = (frame & 0x01);
        }


        



        
        
        
        libAPS::FieldsAPS::FieldsAPS() :framecontrol(FrameControl()),
                            destinationEndpoint(0x0001), isAPS(false) {
                                this->payload.clear();
                                this->fieldsNWK = libNWK::FieldsNWK();
                        }
                                
        libAPS::FieldsAPS::FieldsAPS(FrameControl framecontrol,
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
                                    libNWK::FieldsNWK fieldsNWK)
                            :framecontrol(framecontrol),
                            destinationEndpoint(destinationEndpoint),
                            groupAdd(groupAdd),
                            clusterID(clusterID),
                            profileID(profileID),
                            sourceEndpoint(sourceEndpoint),
                            apsCounter(apsCounter),
                            fragmentation(fragmentation%3),
                            blockNumber(blockNumber),
                            ackBitfield(ackBitfield),
                            commandID(commandID),
                            fieldsNWK(fieldsNWK),
			    isAPS(true) {
                                this->payload.clear();
                                this->payload.reserve(payload.size());
                                this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
                        }
                                    
                        libAPS::FieldsAPS::FieldsAPS(FrameControl framecontrol,
                                    uint8_t destinationEndpoint,
                                    uint16_t clusterID,
                                    uint16_t profileID,
                                    uint8_t sourceEndpoint,
                                    uint8_t apsCounter,
                                    std::vector<uint8_t> payload,
                                    libNWK::FieldsNWK fieldsNWK)
                            :framecontrol(framecontrol),
                            destinationEndpoint(destinationEndpoint),
                            groupAdd(0),
                            clusterID(clusterID),
                            profileID(profileID),
                            sourceEndpoint(sourceEndpoint),
                            apsCounter(apsCounter),
                            fragmentation(0),
                            blockNumber(0),
                            ackBitfield(0),
                            commandID(0),
                            fieldsNWK(fieldsNWK),
			    isAPS(true) {
                                this->payload.clear();
                                this->payload.reserve(payload.size());
                                this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
                        }
                                    
                        libAPS::FieldsAPS::FieldsAPS(FrameControl framecontrol,
                                    uint8_t destinationEndpoint,
                                    uint16_t clusterID,
                                    uint16_t profileID,
                                    uint8_t sourceEndpoint,
                                    uint8_t apsCounter,
                                    int fragmentation,
                                    uint8_t blockNumber,
                                    uint8_t ackBitfield,
                                    std::vector<uint8_t> payload,
                                    libNWK::FieldsNWK fieldsNWK)
                            :framecontrol(framecontrol),
                            destinationEndpoint(destinationEndpoint),
                            groupAdd(0),
                            clusterID(clusterID),
                            profileID(profileID),
                            sourceEndpoint(sourceEndpoint),
                            apsCounter(apsCounter),
                            fragmentation(fragmentation%3),
                            blockNumber(blockNumber),
                            ackBitfield(ackBitfield),
                            commandID(0),
                            fieldsNWK(fieldsNWK),
			    isAPS(true) {
                                this->payload.clear();
                                this->payload.reserve(payload.size());
                                this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
                        }
                                    
                        libAPS::FieldsAPS::FieldsAPS(FrameControl framecontrol,
                                    uint16_t groupAdd,
                                    uint16_t clusterID,
                                    uint16_t profileID,
                                    uint8_t sourceEndpoint,
                                    uint8_t apsCounter,
                                    std::vector<uint8_t> payload,
                                    libNWK::FieldsNWK fieldsNWK)
                            :framecontrol(framecontrol),
                            destinationEndpoint(0),
                            groupAdd(groupAdd),
                            clusterID(clusterID),
                            profileID(profileID),
                            sourceEndpoint(sourceEndpoint),
                            apsCounter(apsCounter),
                            fragmentation(0),
                            blockNumber(0),
                            ackBitfield(0),
                            commandID(0),
                            fieldsNWK(fieldsNWK),
			    isAPS(true) {
                                this->payload.clear();
                                this->payload.reserve(payload.size());
                                this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
                        }
                                    
                        libAPS::FieldsAPS::FieldsAPS(FrameControl framecontrol,
                                    uint16_t groupAdd,
                                    uint16_t clusterID,
                                    uint16_t profileID,
                                    uint8_t sourceEndpoint,
                                    uint8_t apsCounter,
                                    int fragmentation,
                                    uint8_t blockNumber,
                                    uint8_t ackBitfield,
                                    std::vector<uint8_t> payload,
                                    libNWK::FieldsNWK fieldsNWK)
                            :framecontrol(framecontrol),
                            destinationEndpoint(0),
                            groupAdd(groupAdd),
                            clusterID(clusterID),
                            profileID(profileID),
                            sourceEndpoint(sourceEndpoint),
                            apsCounter(apsCounter),
                            fragmentation(fragmentation%3),
                            blockNumber(blockNumber),
                            ackBitfield(ackBitfield),
                            commandID(0),
                            fieldsNWK(fieldsNWK),
			    isAPS(true) {
                                this->payload.clear();
                                this->payload.reserve(payload.size());
                                this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
                        }
                                    
                        libAPS::FieldsAPS::FieldsAPS(FrameControl framecontrol,
                                    uint8_t apsCounter,
                                    uint8_t commandID,
                                    std::vector<uint8_t> payload,
                                    libNWK::FieldsNWK fieldsNWK)
                            :framecontrol(framecontrol),
                            destinationEndpoint(0),
                            groupAdd(0),
                            clusterID(0),
                            profileID(0),
                            sourceEndpoint(0),
                            apsCounter(apsCounter),
                            fragmentation(0),
                            blockNumber(0),
                            ackBitfield(0),
                            commandID(commandID),
                            fieldsNWK(fieldsNWK),
			    isAPS(true) {
                                this->payload.clear();
                                this->payload.reserve(payload.size());
                                this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
                        }
            
            
            

        void libAPS::FieldsAPS::setFrameControl(FrameControl framecontrol){
            this->framecontrol = framecontrol;
        }
        void libAPS::FieldsAPS::setDestinationEndpoint(uint8_t destinationEndpoint){
            this->destinationEndpoint=destinationEndpoint;
        }
        void libAPS::FieldsAPS::setGroupAddress(uint16_t groupAdd){
            this->groupAdd = groupAdd;
        }
        void libAPS::FieldsAPS::setClusterID(uint16_t clusterID){
            this->clusterID = clusterID;
        }
        void libAPS::FieldsAPS::setProfileID(uint16_t profileID){
            this->profileID = profileID;
        }
        void libAPS::FieldsAPS::setSourceEndpoint(uint8_t sourceEndpoint){
            this->sourceEndpoint = sourceEndpoint;
        }
        void libAPS::FieldsAPS::setApsCounter(uint8_t apsCounter){
            this->apsCounter = apsCounter;
        }
        void libAPS::FieldsAPS::setFragmentation(int fragmentation){
            this->fragmentation = fragmentation;
        }
        void libAPS::FieldsAPS::setBlockNumber(uint8_t blockNumber){
            this->blockNumber = blockNumber;
        }
        void libAPS::FieldsAPS::setAckBitfield(uint8_t ackBitfield){
            this->ackBitfield = ackBitfield;
        }
        void libAPS::FieldsAPS::setPayload(std::vector<uint8_t> payload){
            this->payload.clear();
            this->payload.reserve(payload.size());
            this->payload.insert((this->payload).begin(), payload.begin(), payload.end());
        }
        void libAPS::FieldsAPS::setFieldsNWK(libNWK::FieldsNWK fieldsNWK){
            this->fieldsNWK = fieldsNWK;
        }
        
        void libAPS::FieldsAPS::reset(){
            this->framecontrol = FrameControl();
            this->destinationEndpoint = 0;
            this->groupAdd = 0;
            this->clusterID = 0;
            this->profileID = 0;
            this->sourceEndpoint = 0;
            this->apsCounter = 0;
            this->fragmentation = 0;
            this->blockNumber = 0;
            this->ackBitfield = 0;
            this->payload.clear();
            this->fieldsNWK = libNWK::FieldsNWK();
        }
                    
                    

                
        std::vector<uint8_t> libAPS::FieldsAPS::toBytes(){
            

            std::vector<uint8_t> frame;

	    if(!this->isAPS) {
		frame.reserve(sizeof(this->payload));
		frame.insert(frame.end(), this->payload.begin(), this->payload.end());
                return frame;
	    }

            uint8_t fc = this->framecontrol.toBytes();
            int tamEH = 0;
            
            
            switch(this->framecontrol.frameType) {


                case Consts::FrameC::FrameType_Data:
                    
                    if(this->framecontrol.extHeaderPresent) {
                        if(this->fragmentation == 0) tamEH = 1;
                        else tamEH = 2;
                    }
                    
                    if(this->framecontrol.deliveryMode == Consts::FrameC::Mode_Group) {
                        frame.reserve(9 + tamEH + sizeof(this->payload));
                        frame.push_back(fc);
                        frame = appendInt(frame, this->groupAdd, 2);
                    }
                    else {
                        frame.reserve(8 + tamEH +  sizeof(this->payload));
                        frame.push_back(fc);
                        frame.push_back(this->destinationEndpoint);
                    }
                    
                    frame = appendInt(frame, this->clusterID, 2);
                    frame = appendInt(frame, this->profileID, 2);
                    frame.push_back(this->sourceEndpoint & 0xFF);
                    frame.push_back(this->apsCounter & 0xFF);
                    
                    if(this->framecontrol.extHeaderPresent) {
                        frame.push_back(this->fragmentation & 0xFF);
                        if(this->fragmentation > 0) 
                            frame.push_back(this->blockNumber & 0xFF);
                    }
                    
                    frame.insert(frame.end(), this->payload.begin(), this->payload.end());
                    
                    break;
                    
                    
                    
                    
                case Consts::FrameC::FrameType_APSCommand:
                    
                    frame.reserve(3 + sizeof(this->payload));
                    
                    frame.push_back(fc);
                    frame.push_back(this->apsCounter & 0xFF);
                    frame.push_back(this->commandID & 0xFF);
                    frame.insert(frame.end(), this->payload.begin(), this->payload.end());
                    
                    break;
                    
                    
                    
                case Consts::FrameC::FrameType_APSACK:
                    
                    if(this->framecontrol.extHeaderPresent) {
                        if(this->fragmentation == 0) tamEH = 1;
                        else tamEH = 3;
                    }
                    
                    if(this->framecontrol.ackFormat) {
                        frame.reserve(2 + tamEH +  sizeof(this->payload));
                        frame.push_back(fc);
                        frame.push_back(this->apsCounter & 0xFF);
                    }
                    else {
                        frame.reserve(8 + tamEH + sizeof(this->payload));
                        frame.push_back(fc);
                        frame.push_back(this->destinationEndpoint);
                        frame = appendInt(frame, this->clusterID, 2);
                        frame = appendInt(frame, this->profileID, 2);
                        frame.push_back(this->sourceEndpoint & 0xFF);
                        frame.push_back(this->apsCounter & 0xFF);
                    }
                    
                    if(this->framecontrol.extHeaderPresent) {
                        frame.push_back(this->fragmentation & 0xFF);
                        if(this->fragmentation > 0) {
                            frame.push_back(this->blockNumber & 0xFF);
                            frame.push_back(this->ackBitfield & 0xFF);
                        }
                    }
                    
                    frame.insert(frame.end(), this->payload.begin(), this->payload.end());
                    
                    break;
            }

            return frame;
        }
        
        
        
        
        
        void libAPS::FieldsAPS::fromBytes(std::vector<uint8_t> frame, bool isNWK) {
            
            this->reset();

		if(frame.size() < 3 || !isNWK){
		    this->isAPS = false;
		    (this->payload).clear();
            	    (this->payload).reserve(frame.size());
		    (this->payload).insert((this->payload).end(), frame.begin(), frame.end());
		    return;
		}
		else this->isAPS = true;

            uint8_t fc = frame.at(0);
            (this->framecontrol).fromBytes(fc);
            int pos = 0;
            
            
            switch(this->framecontrol.frameType) {


                case Consts::FrameC::FrameType_Data:
                    
                    if (this->framecontrol.deliveryMode == Consts::FrameC::Mode_Group) {
                        this->destinationEndpoint = 0;
                        this->groupAdd = frame.at(1) + (frame.at(2) << 8);
                        pos = 1;
                    }
                    else {
                        this->destinationEndpoint = frame.at(1);
                        this->groupAdd = 0;
                    }
                    
                    this->clusterID = frame.at(2 + pos) + (frame.at(3 + pos) << 8);
                    this->profileID = frame.at(4 + pos) + (frame.at(5 + pos) << 8);
                    this->sourceEndpoint = frame.at(6 + pos);
                    this->apsCounter = frame.at(7 + pos);
                    
                    if(this->framecontrol.extHeaderPresent) {
                        this->fragmentation = (frame.at(8 + pos) & 0x03);
                        if(this->fragmentation > 0) {
                            this->blockNumber = frame.at(9 + pos);
                            pos++;
                        }
                        pos++;
                    }
                    
                    pos += 8;
                    (this->payload).clear();
                    (this->payload).reserve(frame.size() - pos);
                    for(pos; pos<frame.size(); pos++)
                        (this->payload).push_back(frame.at(pos));
                    
                    break;
                    
                    
                    
                    
                case Consts::FrameC::FrameType_APSCommand:
                    
                    this->apsCounter = frame.at(1);
                    this->commandID = frame.at(2);
                    
                    for(pos=3; pos<frame.size(); pos++)
                        (this->payload).push_back(frame.at(pos));
                    
                    break;
                    
                    
                    
                case Consts::FrameC::FrameType_APSACK:
                    
                    if (this->framecontrol.ackFormat) {
                        this->destinationEndpoint = 0;
                        this->clusterID = 0;
                        this->profileID = 0;
                        this->sourceEndpoint = 0;
                        this->apsCounter = frame.at(1);
                        pos = 2;
                    }
                    else {
                        this->destinationEndpoint = frame.at(1);
                        this->clusterID = frame.at(2) + (frame.at(3) << 8);
                        this->profileID = frame.at(4) + (frame.at(5) << 8);
                        this->sourceEndpoint = frame.at(6);
                        this->apsCounter = frame.at(7);
                        pos = 8;
                    }
                    
                    if(this->framecontrol.extHeaderPresent) {
                        this->fragmentation = (frame.at(pos) & 0x03);
                        pos++;
                        if(this->fragmentation > 0) {
                            this->blockNumber = frame.at(pos);
                            this->ackBitfield = frame.at(pos + 1);
                            pos += 2;
                        }
                    }
                    
                    (this->payload).clear();
                    (this->payload).reserve(frame.size() - pos);
                    for(pos; pos<frame.size(); pos++)
                        (this->payload).push_back(frame.at(pos));
                    
                    break;
            }
            
        }
        
        
        void libAPS::FieldsAPS::printAPSFields(){
    
	if(this->isAPS) {
    
            std::cout << "\n\n\tFrame control:\n";
            std::cout << "\t\tTipo de trama: " << (this->framecontrol).frameType << "\n";
            std::cout << "\t\tModo de entrega: " << (this->framecontrol).deliveryMode << "\n";
            
            if((this->framecontrol).frameType == Consts::FrameC::FrameType_APSACK){
                std::cout << "\t\tFormato ACK: " << (this->framecontrol).ackFormat << "\n";
            }
            
            std::cout << "\t\tSeguridad: " << (this->framecontrol).security << "\n";
            std::cout << "\t\tRequiere ACK: " << (this->framecontrol).ackRequest << "\n";
            std::cout << "\t\tCabecera extendida: " << (this->framecontrol).extHeaderPresent << "\n\n";
            
            
            if((this->framecontrol).frameType == Consts::FrameC::FrameType_Data){

                if((this->framecontrol).deliveryMode != Consts::FrameC::Mode_Group){
                    std::cout << "\tEndpoint destino: " << unsigned(this->destinationEndpoint) << "\n";
                }
                else{
                    std::cout << "\tDireccion de grupo: "; printByteHexaValue(this->groupAdd);
                }
                std::cout << "\tID clúster: "; printByteHexaValue(this->clusterID);
                std::cout << "\tID perfil: "; printByteHexaValue(this->profileID);
                std::cout << "\tEndpoint origen: " << unsigned(this->sourceEndpoint) << "\n";
            }
            else if(((this->framecontrol).frameType == Consts::FrameC::FrameType_APSACK) && ((this->framecontrol).ackFormat == Consts::FrameC::ACKFormat_Disabled)){
                std::cout << "\tEndpoint destino: " << unsigned(this->destinationEndpoint) << "\n";
                std::cout << "\tID clúster: "; printByteHexaValue(this->clusterID);
                std::cout << "\tID perfil: "; printByteHexaValue(this->profileID);
                std::cout << "\tEndpoint origen: " << unsigned(this->sourceEndpoint) << "\n";
            }
                
            std::cout << "\tContador APS: " << unsigned(this->apsCounter) << "\n";
            
            if((this->framecontrol).frameType != Consts::FrameC::FrameType_APSCommand){
                if(((this->framecontrol).extHeaderPresent == Consts::FrameC::ExtHeader_Enabled)/* && (this->fragmentation !=0)*/){
                    std::cout << "\tCabecera extendida:\n";
                    std::cout << "\t\tFragmentación: " << this->fragmentation << "\n";
                    std::cout << "\t\tNúmero de bloque: "; printByteHexaValue(this->blockNumber);
                    if((this->framecontrol).frameType == Consts::FrameC::FrameType_APSACK){
                        std::cout << "\t\tCampo ACK: "; printByteHexaValue(this->ackBitfield);
                    }
                }
            }
            else{
                std::cout << "\tID comando: " << unsigned(this->commandID) << "\n";
            }
            std::cout << "\tCarga: ";printVectorHexaValue(this->payload);
	}
	else std::cout << "\n\n\tCarga: ";printVectorHexaValue(this->payload);
	std::cout << "\n" << std::endl;
        }
        
        
        libNWK::FieldsNWK libAPS::FieldsAPS::toNWK(){
            
            std::vector<uint8_t> frame = this->toBytes();
            libNWK::FieldsNWK nwk = libNWK::FieldsNWK(this->fieldsNWK.framecontrol,
                                        this->fieldsNWK.destinationAdd,
                                        this->fieldsNWK.sourceAdd,
                                        this->fieldsNWK.radius,
                                        this->fieldsNWK.sequenceNumber,
                                        this->fieldsNWK.destinationIEEE,
                                        this->fieldsNWK.sourceIEEE,
                                        this->fieldsNWK.multicastMember,
                                        this->fieldsNWK.multicastRadius,
                                        this->fieldsNWK.multicastMaxRadius,
                                        this->fieldsNWK.countSourceRoute,
                                        this->fieldsNWK.indexSourceRoute,
                                        this->fieldsNWK.listSourceRoute,
                                        frame,
                                        this->fieldsNWK.fieldsMAC);
            
            return nwk;
        }
        
        
        libMAC::FieldsMAC libAPS::FieldsAPS::toMAC(){
            
            libNWK::FieldsNWK nwk = this->toNWK();
            std::vector<uint8_t> frame = nwk.toBytes();
            libMAC::FieldsMAC mac = libMAC::FieldsMAC(nwk.fieldsMAC.framecontrol,
                                        nwk.fieldsMAC.seqNumber,
                                        nwk.fieldsMAC.destPAN,
                                        nwk.fieldsMAC.shortDestAddress,
                                        nwk.fieldsMAC.longDestAddress,
                                        nwk.fieldsMAC.srcPAN,
                                        nwk.fieldsMAC.shortSrcAddress,
                                        nwk.fieldsMAC.longSrcAddress,
                                        frame);
            
            return mac;
        }

  } // namespace tfg
} // namespace gr

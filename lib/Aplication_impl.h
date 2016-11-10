/* -*- c++ -*- */


#ifndef INCLUDED_TFG_APLICATION_IMPL_H
#define INCLUDED_TFG_APLICATION_IMPL_H

#include <tfg/Aplication.h>
#include <string.h>

namespace gr {
  namespace tfg {

    uint64_t strtoint(std::string num, bool *resultado);
    template <typename T> std::string toHexString(const T t);
    template <typename T> std::string toDecString(const T t);
    std::vector<std::string> split(std::string str, char delimiter);
    std::string sourceRoute2String(uint8_t countSourceRoute, std::vector<uint16_t> listSourceRoute);

    class Aplication_impl : public Aplication
    {
     private:

      std::string payload;
      int ledCount;

      //MAC
      int MAC_frameType;
      bool MAC_security;
      bool MAC_framePending;
      bool MAC_ackRequest;
      bool MAC_intraPAN;
      int MAC_destMode;
      int MAC_srcMode;
      uint16_t MAC_destPAN;
      uint16_t MAC_shortDestAddress;
      uint64_t MAC_longDestAddress;
      uint16_t MAC_srcPAN;
      uint16_t MAC_shortSrcAddress;
      uint64_t MAC_longSrcAddress;
            
 
      //NWK
      int NWK_frameType;
      bool NWK_discoverRoute;
      bool NWK_multicastFlag;
      bool NWK_security;
      bool NWK_sourceRoute;
      bool NWK_hasDestIEEE;
      bool NWK_hasSrcIEEE;
      uint16_t NWK_destinationAdd;
      uint16_t NWK_sourceAdd;
      uint8_t NWK_radius;
      uint64_t NWK_destinationIEEE;
      uint64_t NWK_sourceIEEE;
      bool NWK_multicastMember;
      int NWK_multicastRadius;
      int NWK_multicastMaxRadius;
      uint8_t NWK_countSourceRoute;
      uint8_t NWK_indexSourceRoute;
      std::vector<uint16_t> NWK_listSourceRoute;
      
      
      //APS
      int APS_frameType;
      int APS_deliveryMode;
      bool APS_ackFormat;
      bool APS_security;
      bool APS_ackRequest;
      bool APS_extHeaderPresent;
      uint8_t APS_destinationEndpoint;
      uint16_t APS_groupAdd;
      uint16_t APS_clusterID;
      uint16_t APS_profileID;
      uint8_t APS_sourceEndpoint;
      int APS_fragmentation;
      uint8_t APS_blockNumber;
      uint8_t APS_ackBitfield;
      uint8_t APS_commandID;


      void msg_handler(pmt::pmt_t msg);

     public:
      Aplication_impl();
      ~Aplication_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
      
      virtual void send();
      virtual void setPayload(std::string payload);
      
      virtual void setMAC_frameType(int MAC_frameType);
      virtual void setMAC_security(bool MAC_security);
      virtual void setMAC_framePending(bool MAC_framePending);
      virtual void setMAC_ackRequest(bool MAC_ackRequest);
      virtual void setMAC_intraPAN(bool MAC_intraPAN);
      virtual void setMAC_destMode(int MAC_destMode);
      virtual void setMAC_srcMode(int MAC_srcMode);
      virtual void setMAC_destPAN(std::string MAC_destPAN);
      virtual void setMAC_destAddress(std::string MAC_destAddress);
      virtual void setMAC_srcPAN(std::string MAC_srcPAN);
      virtual void setMAC_srcAddress(std::string MAC_srcAddress);

      virtual void setNWK_frameType(int NWK_frameType);
      virtual void setNWK_discoverRoute(bool NWK_discoverRoute);
      virtual void setNWK_multicastFlag(bool NWK_multicastFlag);
      virtual void setNWK_security(bool NWK_security);
      virtual void setNWK_sourceRoute(bool NWK_sourceRoute);
      virtual void setNWK_hasDestIEEE(bool NWK_hasDestIEEE);
      virtual void setNWK_hasSrcIEEE(bool NWK_hasSrcIEEE);
      virtual void setNWK_destinationAdd(std::string NWK_destinationAdd);
      virtual void setNWK_sourceAdd(std::string NWK_sourceAdd);
      virtual void setNWK_radius(std::string NWK_radius);
      virtual void setNWK_destinationIEEE(std::string NWK_destinationIEEE);
      virtual void setNWK_sourceIEEE(std::string NWK_sourceIEEE);
      virtual void setNWK_multicastMember(bool NWK_multicastMember);
      virtual void setNWK_multicastRadius(std::string NWK_multicastRadius);
      virtual void setNWK_multicastMaxRadius(std::string NWK_multicastMaxRadius);
      virtual void setNWK_SourceRoute(std::string sourceRoute);
      
      virtual void setAPS_frameType(int APS_frameType);
      virtual void setAPS_deliveryMode(int APS_deliveryMode);
      virtual void setAPS_ackFormat(bool APS_ackFormat);
      virtual void setAPS_security(bool APS_security);
      virtual void setAPS_ackRequest(bool APS_ackRequest);
      virtual void setAPS_extHeaderPresent(bool APS_extHeaderPresent);
      virtual void setAPS_destinationEndpoint(std::string APS_destinationEndpoint);
      virtual void setAPS_groupAdd(std::string APS_groupAdd);
      virtual void setAPS_clusterID(std::string APS_clusterID);
      virtual void setAPS_profileID(std::string APS_profileID);
      virtual void setAPS_sourceEndpoint(std::string APS_sourceEndpoint);
      virtual void setAPS_fragmentation(int APS_fragmentation);
      virtual void setAPS_blockNumber(std::string APS_blockNumber);
      virtual void setAPS_ackBitfield(std::string APS_ackBitfield);
      virtual void setAPS_commandID(std::string APS_commandID);

      virtual void toggleRedLed();
      virtual void toggleGreenLed();
      virtual void toggleYellowLed();
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_TFG_APLICATION_IMPL_H */


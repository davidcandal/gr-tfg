/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_TFG_APLICATION_H
#define INCLUDED_TFG_APLICATION_H

#include <tfg/api.h>
#include <gnuradio/block.h>
#include <string.h>

namespace gr {
  namespace tfg {

    /*!
     * \brief <+description of block+>
     * \ingroup tfg
     *
     */
    class TFG_API Aplication : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<Aplication> sptr;
      
      static sptr make();
      virtual void send()=0;
      virtual void setPayload(std::string payload)=0;
      
      virtual void setMAC_frameType(int MAC_frameType)=0;
      virtual void setMAC_security(bool MAC_security)=0;
      virtual void setMAC_framePending(bool MAC_framePending)=0;
      virtual void setMAC_ackRequest(bool MAC_ackRequest)=0;
      virtual void setMAC_intraPAN(bool MAC_intraPAN)=0;
      virtual void setMAC_destMode(int MAC_destMode)=0;
      virtual void setMAC_srcMode(int MAC_srcMode)=0;
      virtual void setMAC_destPAN(std::string MAC_destPAN)=0;
      virtual void setMAC_destAddress(std::string MAC_destAddress)=0;
      virtual void setMAC_srcPAN(std::string MAC_srcPAN)=0;
      virtual void setMAC_srcAddress(std::string MAC_srcAddress)=0;

      virtual void setNWK_frameType(int NWK_frameType)=0;
      virtual void setNWK_discoverRoute(bool NWK_discoverRoute)=0;
      virtual void setNWK_multicastFlag(bool NWK_multicastFlag)=0;
      virtual void setNWK_security(bool NWK_security)=0;
      virtual void setNWK_sourceRoute(bool NWK_sourceRoute)=0;
      virtual void setNWK_hasDestIEEE(bool NWK_hasDestIEEE)=0;
      virtual void setNWK_hasSrcIEEE(bool NWK_hasSrcIEEE)=0;
      virtual void setNWK_destinationAdd(std::string NWK_destinationAdd)=0;
      virtual void setNWK_sourceAdd(std::string NWK_sourceAdd)=0;
      virtual void setNWK_radius(std::string NWK_radius)=0;
      virtual void setNWK_destinationIEEE(std::string NWK_destinationIEEE)=0;
      virtual void setNWK_sourceIEEE(std::string NWK_sourceIEEE)=0;
      virtual void setNWK_multicastMember(bool NWK_multicastMember)=0;
      virtual void setNWK_multicastRadius(std::string NWK_multicastRadius)=0;
      virtual void setNWK_multicastMaxRadius(std::string NWK_multicastMaxRadius)=0;
      virtual void setNWK_SourceRoute(std::string sourceRoute)=0;

      virtual void setAPS_frameType(int APS_frameType)=0;
      virtual void setAPS_deliveryMode(int APS_deliveryMode)=0;
      virtual void setAPS_ackFormat(bool APS_ackFormat)=0;
      virtual void setAPS_security(bool APS_security)=0;
      virtual void setAPS_ackRequest(bool APS_ackRequest)=0;
      virtual void setAPS_extHeaderPresent(bool APS_extHeaderPresent)=0;
      virtual void setAPS_destinationEndpoint(std::string APS_destinationEndpoint)=0;
      virtual void setAPS_groupAdd(std::string APS_groupAdd)=0;
      virtual void setAPS_clusterID(std::string APS_clusterID)=0;
      virtual void setAPS_profileID(std::string APS_profileID)=0;
      virtual void setAPS_sourceEndpoint(std::string APS_sourceEndpoint)=0;
      virtual void setAPS_fragmentation(int APS_fragmentation)=0;
      virtual void setAPS_blockNumber(std::string APS_blockNumber)=0;
      virtual void setAPS_ackBitfield(std::string APS_ackBitfield)=0;
      virtual void setAPS_commandID(std::string APS_commandID)=0;

      virtual void toggleRedLed()=0;
      virtual void toggleGreenLed()=0;
      virtual void toggleYellowLed()=0;
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_TFG_APLICATION_H */


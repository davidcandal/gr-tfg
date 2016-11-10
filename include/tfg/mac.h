/* -*- c++ -*- */


#ifndef INCLUDED_TFG_MAC_H
#define INCLUDED_TFG_MAC_H

#include <tfg/api.h>
#include <gnuradio/block.h>

namespace gr {
namespace tfg {

class TFG_API mac: virtual public block
{
public:
	virtual int get_num_packet_errors() = 0;
	virtual int get_num_packets_received() = 0;
	virtual float get_packet_error_ratio() = 0;
	
	typedef boost::shared_ptr<mac> sptr;
	static sptr make(bool debug= false);
        
        
private:
        uint16_t destPAN;
        uint16_t destAdd;
        uint16_t srcPAN;
        uint16_t srcAdd;
};

}  // namespace tfg
}  // namespace gr

#endif /* INCLUDED_TFG_MAC_H */
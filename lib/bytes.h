/* -*- c++ -*- */

#ifndef INCLUDED_BYTES_H
#define INCLUDED_BYTES_H

#include <vector>
#include <stdint.h>

namespace gr {
  namespace tfg {

        std::vector<uint8_t> int2Bytes (int value, int numBytes);
        
        std::vector<uint8_t> appendVector (std::vector<uint8_t> vector, std::vector<uint8_t> toappend);
        
        std::vector<uint8_t> appendInt (std::vector<uint8_t> vector, int value, int numBytes);
        
        std::vector<uint8_t> append64Int (std::vector<uint8_t> vector, uint64_t value, int numBytes);
        
        void printVectorHexaValue(std::vector<uint8_t>& vector);
        void printVectorHexaValue(std::vector<uint16_t>& vector);
        
        void printByteHexaValue(uint8_t byte);
        void printByteHexaValue(uint16_t byte);
        void printByteHexaValue(uint64_t byte);

  } // namespace tfg
} // namespace gr

#endif
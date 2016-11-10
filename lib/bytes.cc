/* -*- c++ -*- */


#include "bytes.h"
#include <iostream>

namespace gr {
  namespace tfg {

        std::vector<uint8_t> int2Bytes (int value, int numBytes) {
            
            std::vector<uint8_t> vector;
            vector.reserve(numBytes);
            
            for (std::size_t i=0; i<numBytes; ++i){
                vector.push_back(value & 0xFF);
                value = (value>>8);
            }
            
            return vector;
        }
        
        
        std::vector<uint8_t> appendVector (std::vector<uint8_t> vector, std::vector<uint8_t> toappend) {
            
            vector.insert(vector.end(), toappend.begin(), toappend.end());
            return vector;
        }
        
        
        std::vector<uint8_t> appendInt (std::vector<uint8_t> vector, int value, int numBytes) {
            
            for (std::size_t i=0; i<numBytes; ++i){
                vector.push_back(value & 0xFF);
                value = (value>>8);
            }
            
            return vector;
        }
        
        
        std::vector<uint8_t> append64Int (std::vector<uint8_t> vector, uint64_t value, int numBytes) {
            
            for (std::size_t i=0; i<numBytes; ++i){
                vector.push_back(value & 0xFF);
                value = (value>>8);
            }
            
            return vector;
        }
        
        
        void printVectorHexaValue(std::vector<uint8_t>& vector){

            const char* espacio = "";
            std::cout << std::hex << std::uppercase << "{";

            for(std::vector<uint8_t>::iterator i=vector.begin(); i!=vector.end(); ++i){
                
                unsigned int hex = static_cast<unsigned int>(*i);
                if(hex < 0x10)
                    std::cout << espacio << "(byte)0x0" << hex;
                else
                    std::cout << espacio << "(byte)0x" << hex;
                espacio = ", ";
                //espacio = " ";//(byte)0x
            }
            std::cout << "}" << std::nouppercase << std::dec << std::endl << std::endl;
        }
        
        
        void printVectorHexaValue(std::vector<uint16_t>& vector){

            const char* espacio = "";
            std::cout << std::hex << std::uppercase << "{";

            for(std::vector<uint16_t>::iterator i=vector.begin(); i!=vector.end(); ++i){
                
                unsigned int hex = static_cast<unsigned int>(*i);
                if(hex < 0x10)
                    std::cout << espacio << "0x000" << hex;
                else if(hex < 0x100)
                    std::cout << espacio << "0x00" << hex;
                else if(hex < 0x1000)
                    std::cout << espacio << "0x0" << hex;
                else
                    std::cout << espacio << "0x" << hex;
                espacio = ", ";
            }
            std::cout << "}" << std::nouppercase << std::dec << std::endl;
        }
        
        
        void printByteHexaValue(uint8_t byte){

            unsigned int hex = static_cast<unsigned int>(byte);
            if(hex < 0x10)
                std::cout << "0x0" << std::hex << std::uppercase << hex << std::nouppercase << std::dec << std::endl;
            else
                std::cout << "0x" << std::hex << std::uppercase << hex << std::nouppercase << std::dec << std::endl;
        }
        
        
        void printByteHexaValue(uint16_t byte){

            unsigned int hex = static_cast<unsigned int>(byte);
            if(hex < 0x10)
                std::cout << "0x000" << std::hex << std::uppercase << hex << std::nouppercase << std::dec << std::endl;
            else if(hex < 0x100)
                std::cout << "0x00" << std::hex << std::uppercase << hex << std::nouppercase << std::dec << std::endl;
            else if(hex < 0x1000)
                std::cout << "0x0" << std::hex << std::uppercase << hex << std::nouppercase << std::dec << std::endl;
            else
                std::cout << "0x" << std::hex << std::uppercase << hex << std::nouppercase << std::dec << std::endl;
        }
        
        
        void printByteHexaValue(uint64_t byte){

            unsigned int hex = static_cast<unsigned int>(byte >> 32);
            if(hex < 0x10)
                std::cout << "0x0000000" << std::hex << std::uppercase << hex;
            else if(hex < 0x100)
                std::cout << "0x000000" << std::hex << std::uppercase << hex;
            else if(hex < 0x1000)
                std::cout << "0x00000" << std::hex << std::uppercase << hex;
            else if(hex < 0x10000)
                std::cout << "0x0000" << std::hex << std::uppercase << hex;
            else if(hex < 0x100000)
                std::cout << "0x000" << std::hex << std::uppercase << hex;
            else if(hex < 0x1000000)
                std::cout << "0x00" << std::hex << std::uppercase << hex;
            else if(hex < 0x10000000)
                std::cout << "0x0" << std::hex << std::uppercase << hex;
            else
                std::cout << "0x" << std::hex << std::uppercase << hex;
            
            hex = static_cast<unsigned int>(byte & 0xFFFFFFFF);
            if(hex < 0x10)
                std::cout << "0000000" << std::hex << hex << std::nouppercase << std::dec << std::endl;
            else if(hex < 0x100)
                std::cout << "000000" << std::hex << hex << std::nouppercase << std::dec << std::endl;
            else if(hex < 0x1000)
                std::cout << "00000" << std::hex << hex << std::nouppercase << std::dec << std::endl;
            else if(hex < 0x10000)
                std::cout << "0000" << std::hex << hex << std::nouppercase << std::dec << std::endl;
            else if(hex < 0x100000)
                std::cout << "000" << std::hex << hex << std::nouppercase << std::dec << std::endl;
            else if(hex < 0x1000000)
                std::cout << "00" << std::hex << hex << std::nouppercase << std::dec << std::endl;
            else if(hex < 0x10000000)
                std::cout << "0" << std::hex << hex << std::nouppercase << std::dec << std::endl;
            else
                std::cout << std::hex << hex << std::nouppercase << std::dec << std::endl;
        }

  } // namespace tfg
} // namespace gr
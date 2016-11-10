#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/zigbee/gr-tfg/lib
export PATH=/home/zigbee/gr-tfg/build/lib:$PATH
export LD_LIBRARY_PATH=/home/zigbee/gr-tfg/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-tfg 

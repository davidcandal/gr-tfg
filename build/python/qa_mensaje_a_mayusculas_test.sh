#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/zigbee/gr-tfg/python
export PATH=/home/zigbee/gr-tfg/build/python:$PATH
export LD_LIBRARY_PATH=/home/zigbee/gr-tfg/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/zigbee/gr-tfg/build/swig:$PYTHONPATH
/usr/bin/python2 /home/zigbee/gr-tfg/python/qa_mensaje_a_mayusculas.py 

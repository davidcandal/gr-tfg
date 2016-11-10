#!/bin/bash

USRP=" "
if [ $# -eq 1 ] 
    then 
	USRP="serial=$1"
fi

FILE="/tmp/sdr.pcap"
FLOWGRAPH="SDR_usrp.py"
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
sudo rm ${FILE}
### create fifo
if [ -e ${FILE} ]
then
	echo "${FILE}: file already exists"
	if ! [ -p ${FILE} ]
	then
		echo "ERROR: ${FILE} exists and is not a FIFO"
		exit 1
	fi
else
	echo "creating fifo: ${FILE}"
	mkfifo ${FILE}
fi

### start transceiver
cd ${DIR}
cd ../examples/
./${FLOWGRAPH} ${USRP}&
sleep 1


wireshark -k -i ${FILE} & 

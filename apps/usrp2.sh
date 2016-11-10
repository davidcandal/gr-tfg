#!/bin/bash

USRP=""
NUM=""
if [ $# -eq 1 ] 
    then 
	USRP="serial=$1"
fi
if [ $# -eq 2 ] 
    then 
	USRP="serial=$1"
	NUM="$2"
fi


FILE="/tmp/sdr${NUM}.pcap"
FLOWGRAPH="SDR_usrp2.py"
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
./${FLOWGRAPH} ${USRP} ${NUM} &
sleep 1


wireshark -k -i ${FILE} & 

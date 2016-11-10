/* -*- c++ -*- */

#define TFG_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "tfg_swig_doc.i"

%{
#include "tfg/imprimir_mensajes.h"
#include "tfg/repetidor_caracteres.h"
#include "tfg/mensaje_a_mayusculas.h"
#include "tfg/imprimir_bytes.h"
#include "tfg/test_nwk.h"
#include "tfg/test_aps.h"
#include "tfg/APS_stack.h"
#include "tfg/NWK_stack.h"
#include "tfg/translation_block.h"
#include "tfg/Aplication.h"
#include "tfg/mac.h"
#include "tfg/MAC_stack.h"
#include "tfg/test_mac.h"
#include "tfg/motecontrol.h"
%}

%include "tfg/imprimir_mensajes.h"
GR_SWIG_BLOCK_MAGIC2(tfg, imprimir_mensajes);
%include "tfg/repetidor_caracteres.h"
GR_SWIG_BLOCK_MAGIC2(tfg, repetidor_caracteres);
%include "tfg/mensaje_a_mayusculas.h"
GR_SWIG_BLOCK_MAGIC2(tfg, mensaje_a_mayusculas);

%include "tfg/imprimir_bytes.h"
GR_SWIG_BLOCK_MAGIC2(tfg, imprimir_bytes);
%include "tfg/test_nwk.h"
GR_SWIG_BLOCK_MAGIC2(tfg, test_nwk);


%include "tfg/test_aps.h"
GR_SWIG_BLOCK_MAGIC2(tfg, test_aps);
%include "tfg/APS_stack.h"
GR_SWIG_BLOCK_MAGIC2(tfg, APS_stack);
%include "tfg/NWK_stack.h"
GR_SWIG_BLOCK_MAGIC2(tfg, NWK_stack);
%include "tfg/translation_block.h"
GR_SWIG_BLOCK_MAGIC2(tfg, translation_block);
%include "tfg/Aplication.h"
GR_SWIG_BLOCK_MAGIC2(tfg, Aplication);
%include "tfg/mac.h"
GR_SWIG_BLOCK_MAGIC2(tfg, mac);
%include "tfg/MAC_stack.h"
GR_SWIG_BLOCK_MAGIC2(tfg, MAC_stack);
%include "tfg/test_mac.h"
GR_SWIG_BLOCK_MAGIC2(tfg, test_mac);
%include "tfg/motecontrol.h"
GR_SWIG_BLOCK_MAGIC2(tfg, motecontrol);

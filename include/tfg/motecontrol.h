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


#ifndef INCLUDED_TFG_MOTECONTROL_H
#define INCLUDED_TFG_MOTECONTROL_H

#include <tfg/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace tfg {

    /*!
     * \brief <+description of block+>
     * \ingroup tfg
     *
     */
    class TFG_API motecontrol : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<motecontrol> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of tfg::motecontrol.
       *
       * To avoid accidental use of raw pointers, tfg::motecontrol's
       * constructor is in a private implementation
       * class. tfg::motecontrol::make is the public interface for
       * creating new instances.
       */
      static sptr make();
      virtual void toggleRed()=0;
      virtual void toggleGreen()=0;
      virtual void toggleYellow()=0;
    };

  } // namespace tfg
} // namespace gr

#endif /* INCLUDED_TFG_MOTECONTROL_H */


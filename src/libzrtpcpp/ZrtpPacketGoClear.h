/*
  Copyright (C) 2006 Werner Dittmann

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Boston, MA 02111.
*/

#ifndef _ZRTPPACKETGOCLEAR_H_
#define _ZRTPPACKETGOCLEAR_H_

#include <libzrtpcpp/ZrtpPacketBase.h>

/**
 * Implement the GoClear packet.
 *
 * The ZRTP message GoClear. The implementation sends this
 * to order the peer to switch to clear mode (non-SRTP mode).
 *
 * @author Werner Dittmann <Werner.Dittmann@t-online.de>
 */

class ZrtpPacketGoClear : public ZrtpPacketBase {

 protected:
    GoClear_t* clearHeader;

 public:
    ZrtpPacketGoClear();		/* Creates a GoCLear packet with default data */
    ZrtpPacketGoClear(uint8_t* data);	/* Creates a GoClear packet from received data */
    virtual ~ZrtpPacketGoClear();

    const uint8_t* getClearHmac() { return clearHeader->clearHmac; };
    const uint8_t* getReason()    { return clearHeader->reason; };

    void setClearHmac(uint8_t *text) { memcpy(clearHeader->clearHmac, text, 32); };
    void clrClearHmac()              { memset(clearHeader->clearHmac, 0, 32); };
    void setReason(uint8_t* text)    { memcpy(clearHeader->reason, text, 16); };

 private:
};

#endif // ZRTPPACKETGOCLEAR


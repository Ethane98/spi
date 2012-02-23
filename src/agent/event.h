/*
 * Copyright (c) 1996-2011 Barton P. Miller
 *
 * We provide the Paradyn Parallel Performance Tools (below
 * described as "Paradyn") on an AS IS basis, and do not warrant its
 * validity or performance.  We reserve the right to update, modify,
 * or discontinue this software at any time.  We shall have no
 * obligation to supply such updates or modifications or any other
 * form of support to you.
 *
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef SP_EVENT_H_
#define SP_EVENT_H_

#include <signal.h>

#include "agent/propeller.h"
#include "common/common.h"

namespace sp {

class SpEvent {
  public:
    virtual ~SpEvent() {}

    typedef SHARED_PTR(SpEvent) ptr;
    static ptr Create() { return ptr(new SpEvent); }
    virtual void RegisterEvent() OVERRIDE;
  protected:
    SpEvent();
};


// Instrument current function's callees after N seconds
class AsyncEvent : public SpEvent {
  public:
    typedef SHARED_PTR(AsyncEvent) ptr;

    // Parameter "sec" is the time for alarm signal. For other signals, this
		// parameter is ignored
    static ptr Create(int signum = SIGALRM,
                      int sec = 5) {
      return ptr(new AsyncEvent(signum, sec)); }
    virtual void RegisterEvent() OVERRIDE;
  protected:
    AsyncEvent(int signum, int sec);
    void* handler_;
    int after_secs_;
    int signum_;
};


// Instrument current function's callees right away
class SyncEvent : public SpEvent {
  public:
    typedef SHARED_PTR(SyncEvent) ptr;
    static ptr Create(std::string func_name="") {
      return ptr(new SyncEvent(func_name)); }
    void RegisterEvent();
  protected:
    SyncEvent(std::string func_name);

    std::string func_name_;
};

}


#endif /* SP_EVENT_H_ */
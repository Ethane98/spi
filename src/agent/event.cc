#include "agent/event.h"
#include "agent/context.h"
#include "agent/parser.h"

#include "common/utils.h"

namespace sp {
  extern SpContext* g_context;
	extern SpParser::ptr g_parser;

  // Default Event -- dumb event, does nothing
  SpEvent::SpEvent() {
  }

  void
  SpEvent::RegisterEvent() {
  }

  // AsyncEvent
  typedef void (*event_handler_t)(int, siginfo_t*, void*);

  void
  async_event_handler(int signum, siginfo_t* info, void* context) {
    assert(0 && "TODO");
  }

  AsyncEvent::AsyncEvent(int signum, int sec)
    : after_secs_(sec), signum_(signum) {
    handler_ = (void*)async_event_handler;
  }

  void
  AsyncEvent::RegisterEvent() {
    struct sigaction act;
    act.sa_sigaction = (event_handler_t)handler_;
    act.sa_flags = SA_SIGINFO;
    sigaction(signum_, &act, NULL);
    if (signum_ == SIGALRM) alarm(after_secs_);
  }

  // SyncEvent
  SyncEvent::SyncEvent(std::string func_name)
    : SpEvent(), func_name_(func_name) {
  }


  void
  SyncEvent::RegisterEvent() {
		bool fail_preload = false;
    if (!g_parser->injected()) {

      sp_debug("PRELOAD - preload agent.so, and instrument main()");

			ph::PatchFunction* f = g_parser->findFunction("main");
			if (f) {
        g_context->init_propeller()->go(f,
																				g_context->init_entry(),
																				g_context->init_exit());
			} else {
				sp_debug("FAIL PRELOAD - try injection ...");
				fail_preload = true;
			}
    } // LD_PRELOAD mode

    if (g_parser->injected() || fail_preload) {

      // Instrument all functions in the call stack.
      FuncSet call_stack;
      g_context->get_callstack(&call_stack);
      sp_debug("CALLSTACK - %lu calls in the call stack",
							 (unsigned long)call_stack.size());
      for (FuncSet::iterator i = call_stack.begin(); 
					 i != call_stack.end(); i++) {
				ph::PatchFunction* f = *i;
        g_context->init_propeller()->go(f,
                                        g_context->init_entry(),
                                        g_context->init_exit());
				// We instrument all functions along the call stack, until main
        if (f->name().compare("main") == 0) {
          break;
        }
      } // Call stack
    } // Injection mode
  }
}

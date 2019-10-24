//
// Created by joey.zhang on 2019/10/23.
//

#ifndef VINS_DROIDCV310_TRACE_H
#define VINS_DROIDCV310_TRACE_H

#define ATRACE_NAME(name) a2ir::ScopedTrace ___tracer(name)
// ATRACE_CALL is an ATRACE_NAME that uses the current function name.
#define ATRACE_CALL() ATRACE_NAME(__FUNCTION__)

namespace a2ir {
    class ScopedTrace {
    public:
        ScopedTrace (const char* tag);
        static void trace_init();
        ~ScopedTrace();
    };
}

#endif //VINS_DROIDCV310_TRACE_H

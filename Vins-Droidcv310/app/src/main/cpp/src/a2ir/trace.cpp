//
// Created by joey.zhang on 2019/10/23.
//
#include <android/trace.h>
#include <dlfcn.h>
#include "trace.h"
#include "log_util.h"

namespace a2ir {
    void *(*ATrace_beginSection) (const char* sectionName);
    void *(*ATrace_endSection) (void);

    typedef void *(*fp_ATrace_beginSection) (const char* sectionName);
    typedef void *(*fp_ATrace_endSection) (void);

    static bool b_init = false;

    void ScopedTrace::trace_init() {
#ifdef NDEBUG
        // Retrieve a handle to libandroid.
        void *lib = dlopen("libandroid.so", RTLD_NOW || RTLD_LOCAL);

        // Access the native tracing functions.
        if (lib != NULL) {
            // Use dlsym() to prevent crashes on devices running Android 5.1
            // (API level 22) or lower.
            ATrace_beginSection = reinterpret_cast<fp_ATrace_beginSection>(
                    dlsym(lib, "ATrace_beginSection"));
            ATrace_endSection = reinterpret_cast<fp_ATrace_endSection>(
                    dlsym(lib, "ATrace_endSection"));
            LOGD("trace init done");
            b_init = true;
        }
#endif
    }
    ScopedTrace::ScopedTrace(const char *tag) {
#ifdef NDEBUG
        if (b_init) {
            ATrace_beginSection(tag);
        } else {
            trace_init();
            ATrace_beginSection(tag);
        }
#endif
    }
    ScopedTrace::~ScopedTrace() {
#ifdef NDEBUG
        ATrace_endSection();
#endif
    }
}

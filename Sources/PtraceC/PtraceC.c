#include <stdio.h>
#import <dlfcn.h>
#import <sys/types.h>
#include "PtraceC.h"

#if defined (__arm64__)
#define prevent_debugger PfdVSCqqteGFWxmSPFAw // Obfuscate function name
void prevent_debugger() {
    asm volatile (
        "mov x0, #26\n" // ptrace syscall (26 in XNU)
        "mov x1, #31\n" // PT_DENY_ATTACH (0x1f) - first arg
        "mov x2, #0\n"
        "mov x3, #0\n"
        "mov x16, #0\n"
        "svc #128\n"    // make syscall
    );
}

#endif

/* This file exists to fix multilib conflicts */
#if defined(__x86_64__) || defined(__ia64__) || defined(__s390x__) || defined(__powerpc64__)
#include "jsautocfg64.h"
#else
#include "jsautocfg32.h"
#endif

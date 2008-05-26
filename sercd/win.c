/*
 * sercd Windows support
 * Copyright 2008 Peter Åstrand <astrand@cendio.se> for Cendio AB
 * see file COPYING for license details
 */

#ifdef WIN32
#include "win.h"

#include <stdio.h>

extern int MaxLogLevel;

/* Some day, we might want to support logging to Windows event log */
void
LogMsg(int LogLevel, const char *const Msg)
{
    if (LogLevel <= MaxLogLevel) {
	fprintf(stderr, "%s\n", Msg);
    }
}


#endif /* WIN32 */

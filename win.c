/*
 * sercd Windows support
 * Copyright 2008 Peter Åstrand <astrand@cendio.se> for Cendio AB
 * see file COPYING for license details
 */

#ifdef WIN32
#include "win.h"

#include <stdio.h>

extern int MaxLogLevel;

void
PlatformInit()
{
    WORD winsock_ver;
    WSADATA wsadata;

    /* init winsock */
    winsock_ver = MAKEWORD(2, 2);
    if (WSAStartup(winsock_ver, &wsadata)) {
	fprintf(stderr, "Unable to initialise WinSock\n");
	exit(1);
    }
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2) {
	fprintf(stderr, "WinSock version is incompatible with 2.2\n");
	WSACleanup();
	exit(1);
    }
}

/* Some day, we might want to support logging to Windows event log */
void
LogMsg(int LogLevel, const char *const Msg)
{
    if (LogLevel <= MaxLogLevel) {
	fprintf(stderr, "%s\n", Msg);
    }
}


#endif /* WIN32 */

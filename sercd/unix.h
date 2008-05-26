/*
 * sercd UNIX support
 * Copyright 2008 Peter Åstrand <astrand@cendio.se> for Cendio AB
 * see file COPYING for license details
 */

#ifndef WIN32
#ifndef SERCD_UNIX_H
#define SERCD_UNIX_H

#include <syslog.h>
#include <sys/ioctl.h>		/* ioctl */
#include <netinet/in.h>		/* htonl */
#include <netinet/ip.h>		/* IPTOS_LOWDELAY */
#include <arpa/inet.h>		/* inet_addr */
#include <sys/socket.h>		/* setsockopt */

#define PORTHANDLE int

#define SERCD_SOCKET int

#endif /* SERCD_UNIX_H */
#endif /* WIN32 */

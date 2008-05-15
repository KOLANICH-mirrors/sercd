/*
 * sercd Windows support
 * Copyright 2008 Peter Åstrand <astrand@cendio.se> for Cendio AB
 * see file COPYING for license details
 */

#ifdef WIN32
#ifndef SERCD_WIN_H
#define SERCD_WIN_H
#include <windows.h>

#define PORTHANDLE HANDLE

#define LOG_EMERG       0       /* system is unusable */
#define LOG_ALERT       1       /* action must be taken immediately */
#define LOG_CRIT        2       /* critical conditions */
#define LOG_ERR         3       /* error conditions */
#define LOG_WARNING     4       /* warning conditions */
#define LOG_NOTICE      5       /* normal but significant condition */
#define LOG_INFO        6       /* informational */
#define LOG_DEBUG       7       /* debug-level messages */

#endif /* SERCD_WIN_H */
#endif /* WIN32 */

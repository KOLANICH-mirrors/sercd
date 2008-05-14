/*
 * sercd UNIX support
 * Copyright 2008 Peter Åstrand <astrand@cendio.se> for Cendio AB
 * see file COPYING for license details
 */

#ifndef WIN32
#include "sercd.h"
#include "unix.h"

#include <termios.h>
#include <termio.h>

extern Boolean BreakSignaled;

/* Retrieves the port speed from PortFd */
unsigned long int
GetPortSpeed(PORTHANDLE PortFd)
{
    struct termios PortSettings;
    speed_t Speed;

    tcgetattr(PortFd, &PortSettings);
    Speed = cfgetospeed(&PortSettings);

    switch (Speed) {
    case B50:
	return (50UL);
    case B75:
	return (75UL);
    case B110:
	return (110UL);
    case B134:
	return (134UL);
    case B150:
	return (150UL);
    case B200:
	return (200UL);
    case B300:
	return (300UL);
    case B600:
	return (600UL);
    case B1200:
	return (1200UL);
    case B1800:
	return (1800UL);
    case B2400:
	return (2400UL);
    case B4800:
	return (4800UL);
    case B9600:
	return (9600UL);
    case B19200:
	return (19200UL);
    case B38400:
	return (38400UL);
    case B57600:
	return (57600UL);
    case B115200:
	return (115200UL);
    case B230400:
	return (230400UL);
    case B460800:
	return (460800UL);
    default:
	return (0UL);
    }
}

/* Retrieves the data size from PortFd */
unsigned char
GetPortDataSize(PORTHANDLE PortFd)
{
    struct termios PortSettings;
    tcflag_t DataSize;

    tcgetattr(PortFd, &PortSettings);
    DataSize = PortSettings.c_cflag & CSIZE;

    switch (DataSize) {
    case CS5:
	return ((unsigned char) 5);
    case CS6:
	return ((unsigned char) 6);
    case CS7:
	return ((unsigned char) 7);
    case CS8:
	return ((unsigned char) 8);
    default:
	return ((unsigned char) 0);
    }
}

/* Retrieves the parity settings from PortFd */
unsigned char
GetPortParity(PORTHANDLE PortFd)
{
    struct termios PortSettings;

    tcgetattr(PortFd, &PortSettings);

    if ((PortSettings.c_cflag & PARENB) == 0)
	return ((unsigned char) 1);

    if ((PortSettings.c_cflag & PARENB) != 0 && (PortSettings.c_cflag & PARODD) != 0)
	return ((unsigned char) 2);

    return ((unsigned char) 3);
}

/* Retrieves the stop bits size from PortFd */
unsigned char
GetPortStopSize(PORTHANDLE PortFd)
{
    struct termios PortSettings;

    tcgetattr(PortFd, &PortSettings);

    if ((PortSettings.c_cflag & CSTOPB) == 0)
	return ((unsigned char) 1);
    else
	return ((unsigned char) 2);
}

/* Retrieves the flow control status, including DTR and RTS status,
from PortFd */
unsigned char
GetPortFlowControl(PORTHANDLE PortFd, unsigned char Which)
{
    struct termios PortSettings;
    int MLines;

    /* Gets the basic informations from the port */
    tcgetattr(PortFd, &PortSettings);
    ioctl(PortFd, TIOCMGET, &MLines);

    /* Check wich kind of information is requested */
    switch (Which) {
	/* Com Port Flow Control Setting (outbound/both) */
    case 0:
	if (PortSettings.c_iflag & IXON)
	    return ((unsigned char) 2);
	if (PortSettings.c_cflag & CRTSCTS)
	    return ((unsigned char) 3);
	return ((unsigned char) 1);
	break;

	/* BREAK State  */
    case 4:
	if (BreakSignaled == True)
	    return ((unsigned char) 5);
	else
	    return ((unsigned char) 6);
	break;

	/* DTR Signal State */
    case 7:
	if (MLines & TIOCM_DTR)
	    return ((unsigned char) 8);
	else
	    return ((unsigned char) 9);
	break;

	/* RTS Signal State */
    case 10:
	if (MLines & TIOCM_RTS)
	    return ((unsigned char) 11);
	else
	    return ((unsigned char) 12);
	break;

	/* Com Port Flow Control Setting (inbound) */
    case 13:
	if (PortSettings.c_iflag & IXOFF)
	    return ((unsigned char) 15);
	if (PortSettings.c_cflag & CRTSCTS)
	    return ((unsigned char) 16);
	return ((unsigned char) 14);
	break;

    default:
	if (PortSettings.c_iflag & IXON)
	    return ((unsigned char) 2);
	if (PortSettings.c_cflag & CRTSCTS)
	    return ((unsigned char) 3);
	return ((unsigned char) 1);
	break;
    }
}

#endif /* WIN32 */

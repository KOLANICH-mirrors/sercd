
#ifndef SERCD_H
#define SERCD_H

#include "unix.h"
#include "win.h"
#include <sys/types.h>

/* Standard boolean definition */
typedef enum
{ False, True }
Boolean;

/* Maximum length of temporary strings */
#define TmpStrLen 255

/* Error conditions constants */
#define NoError 0
#define Error 1
#define OpenError -1

/* Base Telnet protocol constants (STD 8) */
#define TNSE ((unsigned char) 240)
#define TNNOP ((unsigned char) 241)
#define TNSB ((unsigned char) 250)
#define TNWILL ((unsigned char) 251)
#define TNWONT ((unsigned char) 252)
#define TNDO ((unsigned char) 253)
#define TNDONT ((unsigned char) 254)
#define TNIAC ((unsigned char) 255)

/* Base Telnet protocol options constants (STD 27, STD 28, STD 29) */
#define TN_TRANSMIT_BINARY ((unsigned char) 0)
#define TN_ECHO ((unsigned char) 1)
#define TN_SUPPRESS_GO_AHEAD ((unsigned char) 3)

/* Base Telnet Com Port Control (CPC) protocol constants (RFC 2217) */
#define TNCOM_PORT_OPTION ((unsigned char) 44)

/* CPC Client to Access Server constants */
#define TNCAS_SIGNATURE ((unsigned char) 0)
#define TNCAS_SET_BAUDRATE ((unsigned char) 1)
#define TNCAS_SET_DATASIZE ((unsigned char) 2)
#define TNCAS_SET_PARITY ((unsigned char) 3)
#define TNCAS_SET_STOPSIZE ((unsigned char) 4)
#define TNCAS_SET_CONTROL ((unsigned char) 5)
#define TNCAS_NOTIFY_LINESTATE ((unsigned char) 6)
#define TNCAS_NOTIFY_MODEMSTATE ((unsigned char) 7)
#define TNCAS_FLOWCONTROL_SUSPEND ((unsigned char) 8)
#define TNCAS_FLOWCONTROL_RESUME ((unsigned char) 9)
#define TNCAS_SET_LINESTATE_MASK ((unsigned char) 10)
#define TNCAS_SET_MODEMSTATE_MASK ((unsigned char) 11)
#define TNCAS_PURGE_DATA ((unsigned char) 12)

/* CPC Access Server to Client constants */
#define TNASC_SIGNATURE ((unsigned char) 100)
#define TNASC_SET_BAUDRATE ((unsigned char) 101)
#define TNASC_SET_DATASIZE ((unsigned char) 102)
#define TNASC_SET_PARITY ((unsigned char) 103)
#define TNASC_SET_STOPSIZE ((unsigned char) 104)
#define TNASC_SET_CONTROL ((unsigned char) 105)
#define TNASC_NOTIFY_LINESTATE ((unsigned char) 106)
#define TNASC_NOTIFY_MODEMSTATE ((unsigned char) 107)
#define TNASC_FLOWCONTROL_SUSPEND ((unsigned char) 108)
#define TNASC_FLOWCONTROL_RESUME ((unsigned char) 109)
#define TNASC_SET_LINESTATE_MASK ((unsigned char) 110)
#define TNASC_SET_MODEMSTATE_MASK ((unsigned char) 111)
#define TNASC_PURGE_DATA ((unsigned char) 112)

/* Generic log function with log level control. Uses the same log levels
of the syslog(3) system call */
void LogMsg(int LogLevel, const char *const Msg);

/* Function executed when the program exits */
void ExitFunction(void);

/* Function called on break signal */
void BreakFunction(int unused);

/* Abstract platform-independent select function */
int SercdSelect(PORTHANDLE *DeviceIn, PORTHANDLE *DeviceOut, PORTHANDLE *Modemstate,
		SERCD_SOCKET *SocketOut, SERCD_SOCKET *SocketIn,
		SERCD_SOCKET *SocketConnect, long PollInterval);
#define SERCD_EV_DEVICEIN 1
#define SERCD_EV_DEVICEOUT 2
#define SERCD_EV_SOCKETOUT 4
#define SERCD_EV_SOCKETIN 8
#define SERCD_EV_SOCKETCONNECT 16
#define SERCD_EV_MODEMSTATE 32

/* macros */
#ifndef MAX
#define MAX(x,y)                (((x) > (y)) ? (x) : (y))
#endif
#ifndef MIN
#define MIN(x,y)                (((x) > (y)) ? (y) : (x))
#endif

void NewListener(SERCD_SOCKET LSocketFd);
void DropConnection(PORTHANDLE * DeviceFd, SERCD_SOCKET * InSocketFd, SERCD_SOCKET * OutSocketFd, 
		    const char *LockFileName);

ssize_t WriteToDev(PORTHANDLE port, const void *buf, size_t count);
ssize_t ReadFromDev(PORTHANDLE port, void *buf, size_t count);
ssize_t WriteToNet(SERCD_SOCKET sock, const void *buf, size_t count);
ssize_t ReadFromNet(SERCD_SOCKET sock,  void *buf, size_t count);

#endif /* SERCD_H */

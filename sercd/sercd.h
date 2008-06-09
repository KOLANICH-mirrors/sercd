
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

/* Generic log function with log level control. Uses the same log levels
of the syslog(3) system call */
void LogMsg(int LogLevel, const char *const Msg);

/* Function executed when the program exits */
void ExitFunction(void);

/* Function called on break signal */
void BreakFunction(int unused);

/* Abstract platform-independent select function */
int SercdSelect(PORTHANDLE *DeviceIn, PORTHANDLE *DeviceOut,
		SERCD_SOCKET *SocketOut, SERCD_SOCKET *SocketIn,
		SERCD_SOCKET *SocketConnect, long PollInterval);
#define SERCD_EV_DEVICEIN 1
#define SERCD_EV_DEVICEOUT 2
#define SERCD_EV_SOCKETOUT 4
#define SERCD_EV_SOCKETIN 8
#define SERCD_EV_SOCKETCONNECT 16

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


#ifndef SERCD_H
#define SERCD_H

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

#endif /* SERCD_H */

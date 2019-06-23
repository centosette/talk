/****************************************************************

talkconfig.h

Configuration of the application. Default parameters, read
configuration files, edit configuration.

*****************************************************************/

#define LOCAL static

#ifndef TALKCONFIG
#define TALKCONFIG
#endif

#define DEFAULT_PORT 28314
#define ESCAPE_CHAR '\'

//get the current username
char* get_username(void);

//get the port to be used for connection
int get_port(void);

//get the escape char for entering commands
char get_escape_char(void);

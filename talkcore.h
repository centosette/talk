/*****************************************************************

talkcore.h 

Core application logic
*****************************************************************/
#include "connection.h"         //connection logic
#include "talkconfig.h"         //configuration data and utilities
#include "interpreter.h"        //interpretation of user input
#include "uinterface.h"         //user interface

typedef struct {
  char *user_id;                        //application user id
  struct tm *application_start_time;
} talk_local_info_t;

int startup();                  //Do basic initialization stuff
int prompt();                   //Prompt the user to type in  message
int print(char *text);          //Print out a text to the user interface
int shutdown();                 //Do cleanup when exiting

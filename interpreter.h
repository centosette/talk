/*******************************************************************

interpreter.h

Logic for interpreting user input: call, accept call, text, quit.

 ******************************************************************/
#include "talkconfig.h"


//parses user input to see if there is a command
int parse_user_input(char *user_input);

//parses incoming message
int parse_incoming_message(char *incoming_message);  

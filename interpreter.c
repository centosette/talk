#include "interpreter.h"
#include <string.h>
/************************************************************

interpreter.c

interpret user input

************************************************************/

typedef struct
{
  int argc = 0;
  char **args = 0;
} instruction;


const char *commands = ["call", "accept", "quit", "back"];
const n_commands = 4;

LOCAL int startswith(char *string, char character);
LOCAL int is_a_command(char *string);
LOCAL int command_call(void *args);
LOCAL instruction *tokenize (char *string);

//parses user input to see if there is a command
int parse_user_input(char *user_input)
{
  int is_escaped = 0;
  int is_command = 0;
  char escape_char = TALKCONFIG get_escape_char();

  //check whether it is an escaped sequence
  if startswith(user_input, escape_char) is_escaped = 1;

  //check if the following part is a command
  if !is_escaped
    {
      //it's simply text: send it to the recipient
      //...
    }
 

  
  
  return 0;
}

//parses incoming message
int parse_incoming_message(char *incoming_message);  

LOCAL int startswith(char *string, char character)
{
  if (string[0] == character) return 1;
  return 0;
}

LOCAL int is_a_command(char * string)
{
  int i;
  text_to_check = "";
  char * tokens = tokenize(string, " ");
  for (i = 0; i < n_commands; i++)
    {
      if strcmp(text_to_check, commands[i])==0 return 1
    }
  return 0;
}

LOCAL instruction *tokenize(char * string)
{
  char *token;
  char *search_string = strupa(string);
  int string_length = strlen(search_string);
  int i, token_len;
  instruction *instruct = malloc(sizeof(instruction), 1);

  for (i = 0; i < string_length; i++)
    {
      
    }
  
}

/*****************************************************************

comlogic.h

Logic of Communication. The main tools for connecting and chatting 
are described here.
******************************************************************/


/*

STORY OF A CONNECTION

When initiating a connection, an automatic startup  message should be
sent identifying the caller. 

If the caller receives no feedback, the session should be terminated.

When the session is set up, the receiver and the caller can both write 
and send messages to each other.

For example, the caller sends a message and waits for response.
While waiting for response, the sender can send another message.

The receiver sees the message on his screen, along with the sender ID.

If a message arrives while the user is composing her message, this 
operation must not be interrupted, but still she can read the new 
message.

*/
#include <time.h>
#include <malloc.h>
#include "ipc/tcp.h"   //use tcp server and client facilities
#include "talkconfig.h" //get application configuration tools and constants

//Logical Packet
/*****************************************
The logical packet is made up of three fixed-len (8 bytes)
fields ancd three variable length fields:
Fixed:
- user id field length
- application data field length
- message text field length

Variable:
- sender user id
- application data 
- message text
 *****************************************/
//length in bytes of the fixed-length parts of the logical packet
#define ID_LEN 8
#define APPDATA_LEN 8
#define MESSAGE_LEN 8

//Possible states of a connection
typedef enum {
	      INITIATING  //when starting a new call
	      , CONNECTED //when received an OK from sender
	      , TIMED_OUT //no OK received
	      , WAITING_FOR_RESPONSE //waiting for an OK
} connection_status_t;


//To maintain a dynamic list of connected ends, with session information.
//This list is necessary to broadcast any incoming message.
typedef struct {
  char *user_id;                             //string identifying the other end's user
  char *session_id;                          //unique string identifying this link
  struct tm *session_start_time;              
  struct tm *session_end_time;
  struct tm *last_incoming_msg_time;          //time when te last msg has been received
  connection_status_t connection_status;
  int socket_descriptor;                     //socket descriptor for the connection
  talk_session_t *next;                      //pointer to the next element of the linked list
} talk_session_t;

//Message structure
typedef struct {
  char *user_id;              //sender id
  char *appdata;              //control commands
  char *message_text;         //payload text 
} message_t;


//create a message_t from basic data


//create a logical packet from a message_t



//initiate a connection being called by a caller. Returns a socket_descriptor
int receiver_connection(int from_server_socket_descriptor);


//initialize local information (see talk_local_info_t)
talk_local_info_t initialize_local_info (char *user_id);

//broadcast incoming message to connected ends
int broadcast_message(char *message);

//add new connection: runs through the list and appends new item (see talk_session_t)
int add_connection (char *incoming_user_id, int socket_descriptor);

//send message, adding session information (user_id)
int write_text(int to_socket_descriptor, char *text_buffer);

//read message, decoding session information (user_id)
int read_text(int from_socket_descriptor, char *text_buffer);


//get session information
talk_session_t *get_session_by_socket(int socket_descriptor);

talk_session_t *get_session_by_user_id(char *user_id);

talk_session_t *get_session_i(int position);

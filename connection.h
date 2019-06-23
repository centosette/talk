/*****************************************************************

connection.h

Models a connection between client and server. Provides ways to
write a text and receive a response.
*****************************************************************/

#include "comlogic.h"  //use communication logic to properly handle the info (session, messages, users...) 

typedef enum {
	      CONNECT           //call for a private (1-1) connection
	      , JOIN            //call for a public connection
	      , REFUSE          //refuse the connection request
	      , ACCEPT          //accept the connection request
	      , PRIVATE         //send a message as private (no broadcast)
	      , PUBLIC          //send a message and broadcast it to other ends
	      , DISCONNECT      //disconnect 
} command_t;

//initiate a connection by calling a host. Returns a socket_descriptor
int connect(char *hostname, talk_local_info_t *local_appdata);

//accept_connection
int accept_connection(int socket_descriptor);

//refuse connection
int refuse_connection(int socket_descriptor);

//disconnect
int disconnect(int socket_descriptor);

int send_message(char *message, talk_session_t *session);

int get_message(char *message, talk_session_t *session);

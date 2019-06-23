#include "connection.h"


//initiate a connection by calling a host. Returns a socket_descriptor
int connect(char *hostname, talk_local_info_t *local_appdata)
{
  int socket_descriptor;
  message_t greeting;
  command_t connect = CONNECT;
  greeting.user_id = local_appdata->user_id;
  greeting.appdata = (char *) &connect;
  greeting.message_text = "Hello";

  
  
  socket_descriptor = makeclient(hostname, STANDARD_PORT);
  return(socket_descriptor);
}


//initiate a connection being called by a caller. Returns a socket_descriptor
int receiver_connection(int server_socket_descriptor)
{
  return (server_socket_descriptor);
}

LOCAL message_t * _create_message(char *user_id
				  , command_t command
				  , char *message_text)
{
  message_t *msg = malloc(sizeof(message_t), 1);
}

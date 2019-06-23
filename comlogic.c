#include "comlogic.h"

talk_session_t *session_list_head = NULL;

//initialize local information (see talk_local_info_t)
talk_local_info_t initialize_local_info (char *user_id)
{
  talk_local_info_t local_info;
  local_info.user_id = user_id;  //TODO check user_id length against ID_LEN
  init_time(local_info.application_start_time);
  return (local_info);
}

/**********************************************************************
Communication logic functions
 **********************************************************************/

//initiate a connection by calling a host. Returns a socket_descriptor
int caller_connection(char *hostname)
{
  //make a client connection
  int socket_descriptor;
  socket_descriptor = makeclient(hostname, DEFAULT_PORT);
  //TODO manage errors
  message_t handshake;
  handshake = handshake(local_info.user_id);

  write_message(
  
  return(socket_descriptor);
}

//initiate a connection being called by a caller. Returns a socket_descriptor
int receiver_connection(int from_server_socket_descriptor);

//broadcast incoming message to connected ends
int broadcast_message(char *message);

//add new connection: runs through the list and appends new item (see talk_session_t)
int add_connection (char *incoming_user_id, int socket_descriptor)
{
  talk_session_t *session, *prev_session;
  session = session_list_head;
  prev_session = session_list_head;

  
  for(;;)
    {
      if(session == NULL)
	{
	  session = (talk_session_t *) malloc (sizeof(talk_session_t));
	  //TODO manage allocation error
	  if(prev_session != NULL)
	    {
	      prev_session.next = session;
	    }
	  else
	    {
	      session_list_head = session;
	    }
	  break;
	}
      else //session is not NULL
	{
	  prev_session = session;
	  session = session.next;
	}
    }
  //now session is the freshly allocated talk_session_t
  session.user_id = incoming_user_id;
  session.next = NULL;
  session.socket_descriptor = socket_descriptor;
  init_time(session.session_start_time);
  session.session_end_time = NULL;
  session.last_incoming_msg_time = NULL;
  session.connection_status = INITIATING;

  return(0);
  
}


//send message, adding session information (user_id)
int write_text(int to_socket_descriptor, char *text_string)
{
  int len = strlen(text_string);
  int rc = write(to_socket_descriptor, text_string, len);

  if (rc < 0) {
    perror("Error while writing message\n");
    exit(EXIT_FAILURE);
  }
  return (0);
}


//read message, decoding session information (user_id)
int read_text(int from_socket_descriptor, char *text_buffer)
{
  int nread;
  nread = read(from_socket_descriptor, text_buffer, MAX_MESSAGE_LEN);
  if (nread < 0)
    {
      perror("Error while reading\n");
      exit(EXIT_FAILURE);
    }
  return nread;
}


//get session information
talk_session_t *get_session_by_socket(int socket_descriptor);

talk_session_t *get_session_by_user_id(char *user_id);

talk_session_t *get_session_i(int position);


/***************************************************************
Local Utility functions
 ***************************************************************/

LOCAL void init_time (struct_tm *now)
{
  time_t t;
  t = time(NULL);
  localtime_r(&t, now);
}


LOCAL message_t handshake(char *user_id)
{
  message_t hs;
  strcpy(hs.user_id, user_id);
  hs.message_text = "";
  hs.command = commands.HELLO;
  return(hs);
}

 LOCAL int write_message(message_t *message, int socket_descriptor)
 {
   
 }
 


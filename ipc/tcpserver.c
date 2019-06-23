#include "tcp.h"

/***************************************************************
tcpserver.c
Forks at each connection and provides the caller with 
a socket descriptor. A signal handler provides waiting for
children's exit status.
 ***************************************************************/
void sigchld_handler (int signum)
{
  int status;
  signal (signum, sigchld_handler);
  if (waitpid(WAIT_ANY, &status, WNOHANG) < 0)
    perror("sigchld_handler: error\n");
}

int makeserver (uint16_t port)
{
  int sock;                           //main listening socket
  sock = make_socket(port);
  if (listen(sock, SERVER_QLEN) < 0)
    {
      perror("Listen failed. Exiting.");
      exit(EXIT_FAILURE);
    }
  signal(SIGCHLD, sigchld_handler); //estabilish handler for managing SIGCHLD
  while(1)
    {
      struct sockaddr_in client;
      int sd;
      int size;
      size = sizeof(client);
      if ((sd = accept(sock, (struct sockaddr *)&client, &size)) < 0)
	{
	  perror("Error while accepting connection");
	}
      else
	{
	  pid_t pid;
	  if((pid = fork())==0) //we are in the child process
	    {
	      close(sock); //should not interfere with the parent copy
	      return (sd);
	    }
	}
    }

}


int make_socket (uint16_t port)
{
  int descriptor;
  struct sockaddr_in name;
  if ((descriptor = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
      perror("Error while creating socket");
      exit(EXIT_FAILURE);
    }
  name.sin_family = AF_INET;
  name.sin_port = htons(port);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(descriptor, (struct sockaddr *) &name, sizeof(name))<0)
    {
      perror("bind");
      exit(EXIT_FAILURE);
    }

 return (descriptor);

}

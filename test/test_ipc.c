#include "ipc/tcp.h"
#include <string.h>

#define PORT 20000

int main()
{
  int server_sd, client_sd;
  pid_t pid;
  char buffer[512];

  pid = fork();

  if(pid == 0)
    {
      //parent process
      int nread = 0;

      //start server
      server_sd = makeserver(PORT);
      while ((nread = read(server_sd, buffer, 512))>0)
	{
	  setbuf(stdout, NULL);
	  printf("Server: ");
	  write(1, buffer, nread);
	  printf("\n");
	}
    }
  else
    {
      //child process
      sleep(3);
      client_sd = makeclient("localhost", PORT);

      for(;;)
	{
	  printf("Enter message:\n");
	  read(0, buffer, 512);
	  write(client_sd, buffer, strlen(buffer));
	  sleep(1);
	}

      
    }

  
}

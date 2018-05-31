#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
  int listenSocket, clientSocket;
  char buffer[1024];
  /*could use sockaddr instead, for this example we will use sockaddr_in*/
  struct sockaddr_in myAddr;
  struct sockaddr_storage clientAddrInfo;
  socklen_t addr_size;

  /*create a socket to listen in for client connections*/
  listenSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  
  myAddr.sin_family = AF_INET;
  /*Host to network short will put the port number in the correct byte order*/
  myAddr.sin_port = htons(7891);
  
  /*Set the server adderess to the loopback address*/
  myAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  
  /*pad the structure with 0's this is needed when not using sockaddr*/
  memset(myAddr.sin_zero, '\0', sizeof(myAddr.sin_zero));  

  /*bind the address and port number to the socket*/
  bind(listenSocket, (struct sockaddr *) &myAddr, sizeof(myAddr));

  /*set server to listen in on the socket for incomming connections*/
  if(listen(listenSocket,5)==0)
  {
    printf("Listening for client to connect\n");
  }
  else
  {
    printf("Error with listening\n");
    exit(0);
   }

  
  addr_size = sizeof(clientAddrInfo);
  /*The program will pause, until an incoming connection is received*/
  clientSocket = accept(listenSocket, (struct sockaddr *) &clientAddrInfo, &addr_size);

  /*Once a connection is made, send a message to the client*/
  //strcpy(buffer,"Hello World\n");
  //send(clientSocket,buffer,13,0);
  while(1)
  {
          memset(buffer, '\0', 1024);  
	  recv(clientSocket, buffer,1024,0);
          printf("Echoing from client: %s",buffer);;
	  send(clientSocket, buffer, strlen(buffer)+1,0);

   }

  exit(0);
}

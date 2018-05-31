#include <stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
  int mySocket;
  char buffer[1024];
  char recvbuffer[1024];
  struct sockaddr_in destAddr;
  socklen_t addr_size;

  /*Both Client and server have to create a socket to send
  and receive data on*/
  mySocket = socket(PF_INET, SOCK_STREAM, 0);
  
  /*set the address of the server*/
  destAddr.sin_family = AF_INET;
  
  destAddr.sin_port = htons(7891);
 
  destAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  /*Again bad the structure with 0's since we are not using sockaddr*/
  memset(destAddr.sin_zero, '\0', sizeof(destAddr.sin_zero));  

  
  addr_size = sizeof destAddr;

  /*make a connection to the server*/

  if (connect(mySocket, (struct sockaddr *) &destAddr, addr_size) != 0)
  {
     printf("Failed to connect to the server\n");
     exit(1);
  }

   while(1)
   {
      memset(buffer, '\0', 1024);
      memset( recvbuffer, '\0', 1024);
      fgets(buffer,1024, stdin);
      send(mySocket,buffer,strlen(buffer)+1,0);
      recv(mySocket,recvbuffer,1024,0);
      printf("%s",recvbuffer);    
   }

  /*we expect an incomming message*/
   //recv(mySocket, buffer, 1024, 0);

  /*print the message from the server*/
  // printf("Message from server: %s",buffer);   

  exit(0);
}

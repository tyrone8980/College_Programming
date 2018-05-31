Make sure to include at least these 
#include <stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>



1. create a struct for your header and define the size etc
kind of like 

typedef struct
{
	unsigned int ID : 16;
	unsigned int QR : 1;
	unsigned int Opcode : 4;
	unsigned int AA : 1;
	unsigned int TC : 1;
	unsigned int RD : 1;
	unsigned int RA : 1;
	unsigned int Z : 3;
	unsigned int RCODE : 4;
	unsigned int QDCOUNT : 16;
	unsigned int ANCOUNT : 16;
	unsigned int NSCOUNT : 16;
	unsigned int ARCOUNT : 16;


}header;

2. create a struct for the question, authority, and all the additional things
kind of the same format 

** Keep in mind that the additional sections are all the same format so just make one 
struct for the three of them**

now start creating your packet and type casting it to a char array 
then add each section, sequentially to a buffer array to hold the packet
now be sure to keep track of what size your buffer should be. It should be a little bit more than the size of all the sections combined 

now inside of the files re sent us, they tell you what the values of everything within the packet should be. 
I will show you what the header should look like 

kind of like 

header *myheader;
	myheader.ID = 1;
	myheader.QR = 1;
	myheaader.Opcode = 0;
	myheader.AA = 0;
	myheader.TC = 0;
	myheader.RD = 0;
	myheader.RA = 0;
	myheader.Z = 0;
	myheader.QDCOUNT = 1;


now make sure to make a function to wrap and unwrap your packet 
when wrapping use htons() to bit swap the packet to make it readable for the network 


and then when unwrapping use ntohs() to bitswap the received packet to make it readable to you



now sending the packet is simple, 
pretty much same thing we used for the shell
just make sure to change the port number
kind of like 

mySocket = socket(PF_INET, SOCK_STREAM, 0);
	destAddr.sin_family = AF_INET;
	destAddr.sin_port = htons(53); //remember we are using udp not tcp so we use prt 53
	//printf("Would DNS address would you like to send the packet to?");
	destAddr.sin_addr.s_addr = inet_addr("10.2.2.2");//this is hardcoded
	memset(destAddr.sin_zero, '\0', sizeof(destAddr.sin_zero));  
	addr_size = sizeof destAddr;

	if (connect(mySocket, (struct sockaddr *) &destAddr, addr_size) != 0)
  	{
  	   printf("Failed to connect to the server\n");
    	   exit(1);
  	}

	buffer = (char *)header;
	while(1)
  	 {
    	
    		memset( recvbuffer, '\0', 1024);
    		//fgets(buffer,1024, stdin);
		htons(buffer)
   		send(mySocket,buffer,strlen(buffer)+1,0);
     		recv(mySocket,recvbuffer,1024,0);
      		//printf("%s",recvbuffer);   
		//call unwrapfunction here 
		unwrap(recvbuffer);

   }



now when you get to the part where your packet is readable and sendable and you have hardcoded the 
www.hofstra.edu 
then you can move on to stripping from the comman line and making it to the format 
3www7hofstra3edu 
that's not too hard, just follow his instructions doing that like how we did in the shell program. 

I mean a cheap way to do this is with a for loop that fills an arrray 
first with a blank character and then it fills, you should also have a counter that is keep track of 
how many characters you added to the array 
NOW IF WHAT YOU ARE READING IS "." set that first blank character to the number of your counter, reset the counter, add a new blank character to the array, and keep going as such
its really cheap but it will work if you are desperate and can understand the nonsense I just said because it really doesn't make sense when I write it out 



also when you send your packet YOU SHOULD GET AN ERROR BACK, each error 
and its meaning is written in the files he shared with us. 
0 means no errors
1 means the packet is not formated correctly
2 means you have issues connecting to the server properly
those are probably the extent of the errors you will receive 


This should help get you started^ 

make sure to look through those RFC documents, they contain all the information you need
make sure to also look up how to use pragma, it makes completing this a little easier, 
or you can use memset.... 
if you have issues finding things in the RFC document, go to the second RFC (the one that is not an introduction to DNS) and press ctrl + f 
and search for keywords that correlate what you are looking for
that is what I did, and it helped a lot 


/*
Tyrone Harmon
Professor Thomas Re
Operating System CSC 112
Final Project

*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include<unistd.h>

void wrapandunwrap(unsigned char* , int);
void Changetodot(unsigned char*,unsigned char*);
unsigned char* getipaddress(unsigned char*,unsigned char*,int*);

struct header
{
	unsigned short ID:1;
	unsigned char QR:1;
	unsigned char OPCODE:4;
	unsigned char AA:1;
	unsigned char TC:1;
	unsigned char RD:1;
	unsigned char CD :1;
  unsigned char AD :1;
	unsigned char RA:1;
	unsigned char Z:1;
	unsigned char RCODE:4;
	unsigned short QDCOUNT;
	unsigned short ANCOUNT;
	unsigned short NSCOUNT;
	unsigned short ARCOUNT;


};
#pragma pack(push, 1)

struct question
{
	unsigned short QTYPE;
	unsigned short QCLASS;


};

struct r_data
{
    unsigned short type;
    unsigned short _class;
    unsigned int ttl;
    unsigned short data_len;
};
#pragma pack(pop)
struct res_record
{
    unsigned char *name;
    struct r_data *resource;
    unsigned char *rdata;
};
typedef struct
{
    unsigned char *name;
    struct QUESTION *ques;
} QUERY;

int main( int argc , char *argv[])
{
    unsigned char buffer[100];


    //Get the hostname from the terminal
    printf("Enter Hostname to Lookup : ");
    scanf("%s" , buffer);

    //Now get the ip of this hostname , A record
    wrapandunwrap(buffer , 1);

    return 0;
}


void wrapandunwrap(unsigned char *host , int query_type)
{
    unsigned char buf[65536],*qname,*reader;
    int i , j , stop , s;

    struct sockaddr_in a;

    struct res_record answers[20],auth[20],addit[20];
    struct sockaddr_in dest;

    struct header *myheader = NULL;
    struct question *qinfo = NULL;

    printf("Resolving %s" , host);

    s = socket(AF_INET , SOCK_DGRAM , IPPROTO_UDP);

    dest.sin_family = AF_INET;
    dest.sin_port = htons(53);
    dest.sin_addr.s_addr = inet_addr("10.2.2.2");


    myheader = (struct header *)&buf;

    myheader->ID = (unsigned short) htons(getpid());
    myheader->QR = 0;
    myheader->OPCODE = 0;
    myheader->AA = 0;
    myheader->TC = 0;
    myheader->RD = 1;
    myheader->RA = 0;
    myheader->Z = 0;
    myheader->AD = 0;
    myheader->CD = 0;
    myheader->RCODE= 0;
    myheader->QDCOUNT = htons(1);
    myheader->ANCOUNT = 0;
    myheader->NSCOUNT = 0;
    myheader->ARCOUNT = 0;
    qname =(unsigned char*)&buf[sizeof(struct header)];
    Changetodot(qname , host);
    qinfo =(struct question*)&buf[sizeof(struct header) + (strlen((const char*)qname) + 1)];
    qinfo->QTYPE = htons( query_type );
    qinfo->QCLASS = htons(1);
    printf("\nSending Packet...");
    if( sendto(s,(char*)buf,sizeof(struct header) + (strlen((const char*)qname)+1) + sizeof(struct question),0,(struct sockaddr*)&dest,sizeof(dest)) < 0)
    {
        perror("sendto failed");
    }
    printf("Done");
    i = sizeof dest;
    printf("\nReceiving answer...");
    if(recvfrom (s,(char*)buf , 65536 , 0 , (struct sockaddr*)&dest , (socklen_t*)&i ) < 0)
    {
        perror("recvfrom failed");
    }
    printf("Done");
    myheader = (struct header*) buf;
    reader = &buf[sizeof(struct header) + (strlen((const char*)qname)+1) + sizeof(struct question)];
    printf("\nThe response contains : ");
    printf("\n %d Questions.",ntohs(myheader->QDCOUNT));
    printf("\n %d Answers.",ntohs(myheader->ANCOUNT));
    printf("\n %d Authoritative Servers.",ntohs(myheader->NSCOUNT));
    printf("\n %d Additional records.\n\n",ntohs(myheader->ARCOUNT));
    stop=0;
    for(i=0;i<ntohs(myheader->ANCOUNT);i++)
    {
        answers[i].name=getipaddress(reader,buf,&stop);
        reader = reader + stop;

        answers[i].resource = (struct r_data*)(reader);
        reader = reader + sizeof(struct r_data);

        if(ntohs(answers[i].resource->type) == 1)
        {
            answers[i].rdata = (unsigned char*)malloc(ntohs(answers[i].resource->data_len));

            for(j=0 ; j<ntohs(answers[i].resource->data_len) ; j++)
            {
                answers[i].rdata[j]=reader[j];
            }

            answers[i].rdata[ntohs(answers[i].resource->data_len)] = '\0';

            reader = reader + ntohs(answers[i].resource->data_len);
        }
        else
        {
            answers[i].rdata = getipaddress(reader,buf,&stop);
            reader = reader + stop;
        }
    }

    for(i=0;i<ntohs(myheader->NSCOUNT);i++)
    {
        auth[i].name=getipaddress(reader,buf,&stop);
        reader+=stop;

        auth[i].resource=(struct r_data*)(reader);
        reader+=sizeof(struct r_data);

        auth[i].rdata=getipaddress(reader,buf,&stop);
        reader+=stop;
    }


    for(i=0;i<ntohs(myheader->ARCOUNT);i++)
    {
        addit[i].name=getipaddress(reader,buf,&stop);
        reader+=stop;

        addit[i].resource=(struct r_data*)(reader);
        reader+=sizeof(struct r_data);

        if(ntohs(addit[i].resource->type)==1)
        {
            addit[i].rdata = (unsigned char*)malloc(ntohs(addit[i].resource->data_len));
            for(j=0;j<ntohs(addit[i].resource->data_len);j++)
            addit[i].rdata[j]=reader[j];

            addit[i].rdata[ntohs(addit[i].resource->data_len)]='\0';
            reader+=ntohs(addit[i].resource->data_len);
        }
        else
        {
            addit[i].rdata=getipaddress(reader,buf,&stop);
            reader+=stop;
        }
    }
    printf("\nAnswer Records : %d \n" , ntohs(myheader->ANCOUNT) );
    for(i=0 ; i < ntohs(myheader->ANCOUNT) ; i++)
    {
        printf("Name : %s ",answers[i].name);

        if( ntohs(answers[i].resource->type) == 1)
        {
            long *p;
            p=(long*)answers[i].rdata;
            a.sin_addr.s_addr=(*p);
            printf("has IPv4 address : %s",inet_ntoa(a.sin_addr));
        }

        if(ntohs(answers[i].resource->type)==5)
        {
            printf("has alias name : %s",answers[i].rdata);
        }

        printf("\n");
    }

    printf("\nAuthoritive Records : %d \n" , ntohs(myheader->NSCOUNT) );
    for( i=0 ; i < ntohs(myheader->NSCOUNT) ; i++)
    {

        printf("Name : %s ",auth[i].name);
        if(ntohs(auth[i].resource->type)==2)
        {
            printf("has nameserver : %s",auth[i].rdata);
        }
        printf("\n");
    }


    printf("\nAdditional Records : %d \n" , ntohs(myheader->ARCOUNT) );
    for(i=0; i < ntohs(myheader->ARCOUNT) ; i++)
    {
        printf("Name : %s ",addit[i].name);
        if(ntohs(addit[i].resource->type)==1)
        {
            long *p;
            p=(long*)addit[i].rdata;
            a.sin_addr.s_addr=(*p);
            printf("has IPv4 address : %s",inet_ntoa(a.sin_addr));
        }
        printf("\n");
    }

    //print rcode To check 4 errorrrrrsssss
    printf("\nERROR CONDITION (RCODE) : %d \n" , 0);
    return;
}

u_char* getipaddress(unsigned char* reader,unsigned char* buffer,int* count)
{
    unsigned char *name;
    unsigned int p=0,jumped=0,offset;
    int i , j;

    *count = 1;
    name = (unsigned char*)malloc(256);

    name[0]='\0';
    while(*reader!=0)
    {
        if(*reader>=192)
        {
            offset = (*reader)*256 + *(reader+1) - 49152;
            reader = buffer + offset - 1;
            jumped = 1;
        }
        else
        {
            name[p++]=*reader;
        }

        reader = reader+1;

        if(jumped==0)
        {
            *count = *count + 1;
        }
    }

    name[p]='\0';
    if(jumped==1)
    {
        *count = *count + 1;
    }
    for(i=0;i<(int)strlen((const char*)name);i++)
    {
        p=name[i];
        for(j=0;j<(int)p;j++)
        {
            name[i]=name[i+1];
            i=i+1;
        }
        name[i]='.';
    }
    name[i-1]='\0';
    return name;
}


void Changetodot(unsigned char* dns,unsigned char* host)
{
    int lock = 0 , i;
    strcat((char*)host,".");

    for(i = 0 ; i < strlen((char*)host) ; i++)
    {
        if(host[i]=='.')
        {
            *dns++ = i-lock;
            for(;lock<i;lock++)
            {
                *dns++=host[lock];
            }
            lock++;
        }
    }
    *dns++='\0';
}
/*
struct options
typedef struct
{
	unsigned int NAME : 16;
	unsigned int TYPE : 16;
	unsigned int CLASS : 16;
	unsigned int TIL : 16;
	unsigned int RDLENGTH : 16;
	unsigned int RDATA : 16;


}answer;

typedef struct
{
	unsigned int NAME : 16;
	unsigned int TYPE : 16;
	unsigned int CLASS : 16;
	unsigned int TIL : 16;
	unsigned int RDLENGTH : 16;
	unsigned int RDATA : 16;


}authority;

typedef struct
{
	unsigned int NAME : 16;
	unsigned int TYPE : 16;
	unsigned int CLASS : 16;
	unsigned int TIL : 16;
	unsigned int RDLENGTH : 16;
	unsigned int RDATA : 16;


}additional;
*/




/*
	1. cast and add to buffer each section
	2. buffer size = a little more than the size of all sections combined
	using sizeof() to check the size of each structure
	3. cast as char array and cast byte array back to struct to see if data was corrupted

char[128] question;
question[0] = 3;
question[1] = "w";

parts left to do :
wrap function
unwrap function

now remember that www.hofstra.edu
and all that bullshit that part is easy
similar to shell script and we will be using . to split it up
then cast it to a string (Easy)
*/


/*  OLD  MAIN
int main()
{
	int mySocket;
  	char buffer[1024];
  	char recvbuffer[1024];
  	struct sockaddr_in destAddr;
  	socklen_t addr_size;
	//initialize each structure and fill it with zeros

	memset(&header, 0, sizeof(myStruct));
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

 create a string for each struct and then add that string to the buffer
	 remember to check the size of each struct

	header *thehead = (header*)malloc(sizeof(header));
	now lets say you were to take your number and cast it into char*
	char* mypacket;

	mypacket = (char*)myheader;
	then you just
	htons(mypacket) etc and send it off like below
	I still have to edit that but it will take 2 seconds

	now when you are casting it back in your unwrap function
	int *castback; and use that to cast it back and after us ntohs(whateveransweris);
	then read
	mySocket = socket(PF_INET, SOCK_STREAM, 0);
	destAddr.sin_family = AF_INET;
	destAddr.sin_port = htons(53);
	//printf("Would DNS address would you like to send the packet to?");
	destAddr.sin_addr.s_addr = inet_addr("10.2.2.2");
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



}
*/

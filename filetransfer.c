#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int sd,port_no,fromlen,len;
	int i;
	struct sockaddr_in serveraddr,fromaddr;
	char recvbuf[80];
	sd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&serveraddr,sizeof(serveraddr));
	printf("enter the port no");
	scanf("%d",&port_no);
	serveraddr.sin_port=htons(port_no);
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_addr.s_addr=INADDR_ANY;
	bind(sd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	fromlen=sizeof(struct sockaddr_in);
	do
	{
		len=recvfrom(sd,recvbuf,80,0,(struct sockaddr*)&fromaddr,&fromlen);
		for(i=0;i<len;i++)
		{
			printf("%c",recvbuf[i]);
		}
		sendto(sd,"packet recieved\n",23,0,(struct sockaddr*)&fromaddr,fromlen);
		
	}while(1);
	return 0;
}

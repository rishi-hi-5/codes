#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
vector<int> a;
int sequence_no;
void no_error_at_reciever(int window_size)
{
	//printf("data send successfully to reciever\n");
	for(int i=sequence_no;i<)
}
void error_at_reciever(int size of );
{

	packet_lost=rand()%11;
	printf("packet lost\n");
}
int main()
{
	int window_size,choice,i,data,total_data=0;
	printf("enter the window size\n");
	scanf("%d",&window_size);
	printf("enter the no the data to be send and enter -1 to stop accepting data\n");
	while(true)
	{
		scanf("%d",&data);
		if(data==-1)
		break;
		v.push_back(data);
	}
	
	printf("sending the data......\n");
	printf("what you want to simulate...\n1.packets lost \n2.No packets lost");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			no_error_at_reciever(window_size);
		break;
		case 2: 
			error_at_reciever();
		break;
	}
	return 0;
}



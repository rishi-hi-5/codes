#include<sstream>
#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

ifstream fin;
ofstream fout;
int SI;
bool occupied_pages[30];

class memory
{
	private:
		char mem[300][4];
		char ch;
		int page_table_ptr;
		
	public:
		void reset()//ok
		{
			//reset the memory by replacing every symbol in 2D array by $
			memset(mem,'$',sizeof(char)*300*4);
			memset(occupied_pages,false,sizeof(bool)*30);
			occupied_pages[13]=0;
			page_table_ptr=0;
		}
		string get_mem(int pos)//get word form memory
		{
			//get the memory contents of given position
			string temp="";
			for(int i=0;i<4;i++)
				temp+=mem[pos][i];
			return temp;
		}
		void set_mem(string s, int pos)//store word in mem
		{
			//set the memory for the recieved value at postion 
			for(int i=0;i<4;i++)
				mem[pos][i]=s[i];
		}
		int allocate_page()
		{
			int page_no=rand()%30;
			while(occupied_pages[page_no]==true)
				page_no=rand()%30;
			occupied_pages[page_no]=true;
			set_page_table(page_no);
			return page_no;
		}
		void set_page_table(int page_no)
		{
			ostringstream temp;
			temp << page_no;
			string table_entry="$1"+temp.str();
			set_mem(table_entry,page_table_ptr++);
		}
		void store_card(string s,int mem_cnt)
		{
			//extract the words and call the setmem function
			string word="";
			int page_no=allocate_page()*10;
			for(int i=0;i<s.length();i+=4)
			{
				for(int j=0;j<4;j++)
				{
					word+=s[i+j];
				}	
				set_mem(word,page_no);
				page_no++;
				word="";
			}
		}
/*		void get_program_cards()
		{
			int flag=0;
			for(int i=0;i<100;i++)
			{
				for(int j=0;j<=3;j++)
				{
`					fin>>ch;
					mem[i][j]=ch;
					if(mem[i][0]=='H')
					{
						flag=1;
						break;
					}
				}
				if(flag)
					break;
			}
		}*/
		void print_mem()
		{
			int flag=0;
			for(int i=0;i<300;i++)
			{
				for(int j=0;j<4;j++)
				{
					if (mem[i][j]=='$')
					{
						flag=1;
						break;
					}
					else
						cout<<mem[i][j];
				}
				if (flag)
					break;
				cout<<endl;
			}
		}
}m_obj;

class cpu
{
	private:
		int fetched_IC;
		bool terminate,fetched_C;
		string fetched_IR,operand,opreator,fetched_R,compare_string;
		char IR[4],R[4],IC[2];
		bool C,run_mos;

	public:
	/*	cpu()
		{
			occupied_pages			
		}*/
		//set and reset function of all the register
		int s_to_i(string operand)//ok
		{
			//return the integer no for the given string
			return ((int)operand[0]-48)*10+((int)operand[1]-48);
		}

		void set_IC()
		{
			IC[0]='0';
			IC[1]='0';
		}
		void set_IC(int pos)//ok
		{
			IC[1]=((char)pos%10)+48;
			pos=pos/10;
			IC[0]=((char)pos%10)+48;
		}
		int get_IC()
		{
			int val;
			val=((int)IC[0]-48)*10+((int)IC[1]-48);
			return val;	
		}	
		void inc_IC()//ok
		{
			int val;
			val=get_IC();
			val++;
			set_IC(val);
		}

		void set_IR(int IC)//ok
		{
			string returned_value="";
			returned_value=m_obj.get_mem(IC);
			for(int i=0;i<4;i++)
			IR[i]=returned_value[i];
		}
		string get_IR()//ok
		{
			string ret_IR="";
			for(int i=0;i<4;i++)
			ret_IR+=IR[i];
			return ret_IR;
		}
		void set_R(int pos)//ok
		{
			string returned_value="";
			returned_value=m_obj.get_mem(pos);
			for(int i=0;i<4;i++)
				R[i]=returned_value[i];
		}
		string get_R()//ok
		{
			string ret_R="";
			for(int i=0;i<4;i++)
			{
				ret_R+=R[i];
			}
			return ret_R;
		}
		void set_C(bool value)//ok
		{
			C=value;
		}
		bool get_C()//ok
		{
			return C;
		}
		void startexe()
		{
			//set ic to 0 and start the execution of the program
			set_IC();
			PROGRAM();
		}		
		void PROGRAM()
		{
			//fetch decode execute cycle given below
			terminate=false;
			while(!terminate)
			{

			//fetch ic
			//fetch ir form the location specified by ic
			//get the value of operator and operand
				run_mos=false;
				fetched_IC =get_IC();
				inc_IC();
				set_IR(fetched_IC);
				fetched_IR=get_IR();
				opreator=fetched_IR.substr(0,2);
				operand=fetched_IR.substr(2,2);

				if(!(opreator.compare("LR")))//ok
				{
					//set the contents of the register R from the given location of memory specified in the operand
					//cout<<"LR";
					int pos=s_to_i(operand);
					set_R(pos);
				}
				else if (!(opreator.compare("SR")))//ok
				{
					//get the contents of register R
					//store them at the location of memory specified in the operand
					//cout<<"SR";
					fetched_R=get_R();
					int pos=s_to_i(operand);
					m_obj.set_mem(fetched_R, pos);
				}
				else if (!(opreator.compare("CR")))//ok
				{
					//get the contents of register r
					//compare with given memory location
					//if the values of above two matches then set toggle register to true
					//else set the toggle register to false
					//cout<<"CR";
					fetched_R=get_R();
					int pos=s_to_i(operand);
					compare_string=m_obj.get_mem(pos);
					if(fetched_R.compare(compare_string)==0)
						set_C(true);
					else
						set_C(false);
				}
				else if (!(opreator.compare("BT")))//ok
				{

					//if the value of toggle register is true 
					//we change the value of ic
					//cout<<"BT";
					fetched_C=get_C();
					if(fetched_C)
					{
						int pos=s_to_i(operand);
						set_IC(pos);
					}
				}
				else if (!(opreator.compare("GD")))//ok
				{
					SI=1;
					run_mos=true;
				}
				else if (!(opreator.compare("PD")))//ok
				{
					SI=2;
					run_mos=true;
				}
				else//ok
				{
					SI=3;
					run_mos=true;
				}
				if(run_mos)
				MOS();
			}
		}
		void MOS()
		{
			if(SI==1)
			{
				//get the instrution of the file in terms of 4 words 
				//store it one by one into memory
				//at start store the program card from memory location with unit place 0

				string s;
				int pos=s_to_i(operand);
				pos=(pos/10)*10;
				getline(fin,s);
				if(!s.empty() && s[s.size()-1]=='\r')
					s.erase(s.size()-1);
				int len=s.length(),start=0,i;
				string s1;
				for(i=pos;start<len;i++)
				{
					if((len-start)<4)
						s1=s.substr(start,(len-start));
					else	
						s1=s.substr(start,4);
					start+=4;
					m_obj.set_mem(s1,i);
				}
			}
			else if(SI==2)
			{
				//put the data from memory into the file specified

				int pos=s_to_i(operand),flag=0;
				pos=(pos/10)*10;
				string ans="",temp="";
				for(int i=pos;i<pos+10;i++)
				{
					temp=m_obj.get_mem(i);
					for(int j=0;j<4;j++)
					{
						if(temp[j]=='\0' || temp[j]=='$')
						{
							break;
							flag=1;
						}
						ans+=temp[j];
					}
					if(flag)
						break;
				}
				fout<<ans<<endl;
			}
			else
			{
				//make terminate true to end the program
				//as we encountered the halt instruction 

				terminate=true;
				fout<<"--------------------------------------"<<endl<<endl;
				fout<<"--------------------------------------"<<endl<<endl;
			}
		}
}exe;

int main()
{

	//open two files one input and one output
	//create memory and cpu object

	fin.open("myjob.txt");
	fout.open("job2_Output.txt");
	string s,s1;
	int mem_cnt=0;
	while(!(fin.eof()))//ok
	{
		//get the line one byb one and check wether it contains as follows

		getline(fin,s);
		if(s.empty())
		break;
		if(s.find("$AMJ")!=-1)
		{
			//reset the memory
			m_obj.reset();
			continue;
		}
		else if(s.find("$DTA")!=-1)
		{	
			m_obj.print_mem();
			exe.startexe();
		}
		else if(s.find("$END")!=-1)
		{
			//proceed to the next job
			mem_cnt=0;	
			continue;
		}
		else 
		{
			//load the program card as soon as it comes
			m_obj.store_card(s,mem_cnt);
			mem_cnt+=(s.length()/4);
		}
	}
	fin.close();
	fout.close();
	return 0;
}

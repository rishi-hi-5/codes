#include<iostream>
#include<stdio.h>
class IntCell
{
	public:
	explicit IntCell( int initialvalue = 0 )
	: storedValue( initialvalue ) { }
	
	int read( ) const
	{ 
		return storedValue;
	} 
	void write( int x )
	{ 
		storedValue = x; 
	}
	private:
	int storedValue; 
};
int main()
{

	IntCell obj =37;
	int temp=37;
	return 0;
}

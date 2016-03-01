#include <iostream>
#include <algorithm>
using namespace std;
template< typename TYPE >
void print(TYPE val)
{
    std::cout << val << " ";
}
int main()
{ 
int data[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
sort(data, data+10);
for_each (data, data+10, print<int>);
cout <<endl;
	return 0;
}

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Box
{ 
	public:
	Box() 
		{
		cout << "Constructor called!" <<endl;
		}
	~Box() 
		{
		cout << "Destructor called!" <<endl;
		}
};

int main( )
{
	
	Box* myBoxArray = new Box[4];
	delete [] myBoxArray; // Delete array
	_sleep(50000);
	
}

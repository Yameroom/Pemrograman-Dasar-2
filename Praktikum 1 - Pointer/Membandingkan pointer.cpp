#include <iostream>

using namespace std;

const int MAX = 3;

int main () {
	
	int var[MAX] = {10,80,300};
	int *ptr;
	
	ptr = var;
	int i = 0;
	while ( ptr <= &var[ MAX - 1] ) 
	{
		cout << "Address of var [" << i << "] = ";
		cout << ptr << endl;
		cout << "Value of var[" << i << "] = ";
		cout << *ptr << endl;
		ptr++;
		i++;
	}
	return 0;
}

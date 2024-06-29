#include <iostream>

using namespace std;

const int MAX = 4;

int main () {
	char *names[MAX] = {
		"surabaya",
		"Depok",
		"Bandung",
		"Malang",
		
		};
	for (int i = 0; i < MAX; i++)
 	{
 		cout << "Value of names[" << i << "] = ";
 		cout << names[i] << endl;
 	}
 	
 return 0;
}


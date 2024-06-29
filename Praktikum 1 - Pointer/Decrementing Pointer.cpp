#include <iostream>

using namespace std;

const int MAX = 3;

int main () {
	int var[MAX] = {10,1000,2000};
	int *ptr;
	
	ptr = &var[MAX-1];
	for (int i = MAX; i > 0; i--){
		cout << "Addres of var [" << i <<"] = ";
		cout << ptr << endl;
		cout << "value of var [" << i <<"] = ";
		cout << *ptr << endl;
		
		ptr--;
	}
	
	return 0;
}

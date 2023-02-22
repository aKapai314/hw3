#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack<int> test;

	test.push(1);
	test.push(2);

	//cout << "just pushed " << test.top() << endl;

	


	cout << test.size() << endl;
	cout << test.empty() << endl;
	



	return 0;
}
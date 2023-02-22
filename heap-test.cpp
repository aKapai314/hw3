#include "heap.h"
#include <iostream>
using namespace std;

struct Greater
{
bool operator()(int v1, int v2){
	return v1 > v2;
}
};


int main()
{

	Greater func;
	Heap<int, Greater> test(2, func);

	test.push(3);
	test.push(10);
	
	cout << test.top() << endl;

	cout << test.size() << endl; 
	
	test.pop();

	cout << test.size() << endl;

	cout << test.top() << endl;



	return 0;
}
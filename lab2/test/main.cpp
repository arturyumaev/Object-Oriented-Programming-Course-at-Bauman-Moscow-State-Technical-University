#include <iostream>

#include "class.h"

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");

	MyClass<int> a(10);

	cout << a.getSize() << endl;

	return 0;
}

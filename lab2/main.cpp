/* TODO: 
 * 1) base realization
 * 2) tests ??
 * ???
 * PROFIT!!!
 */

#include "stdafx.h"
#include "MyVector.h"
#include "unitTests.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");

    unitTest();

    vector<int> v(5, 1);

    cout << v.size() << v.capacity() << endl;

    v.pop_back();

    cout << v.size() << v.capacity() << endl;

    v.shrink_to_fit();

    cout << v.size() << v.capacity() << endl;

    cout << "\n==========\n" << endl;

    MyVector<int> b(10, 2);

    for (int i = 0; i < 4; i++)
    {
        b.pop_back();
    }

    return 0;
}
/* TODO: 
 * 1) base realization
 * 2) tests ??
 * ???
 * PROFIT!!!
 */

#include "stdafx.h"
#include "MyVector.h"
#include "unitTests.h"

template <typename T> void printVector(MyVector<T>* v)
{
    /* Get a POINER to the vector <v> because of escaping from 
     * creating local copy of vector <v> and calling destructor,
     * that leads to double free allocated memory.
     */

    for (int i = 0; i < (*v).size(); i++)
    {
        cout << (*v).at(i) << endl;
    }
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");

    unitTest();

    return 0;
}
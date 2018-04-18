#include "MyVector.h"

void unitTest()
{
    cout << "\n === Unit Tests === \n\n"; 

    // MyVector::empty test
    MyVector<int> a;
    MyVector<int> b(5);
    MyVector<int> c(5, 6);
    cout << "MyVector::empty ";
    bool answer1Exp = a.empty(), answer2Exp = b.empty(), answer3Exp = c.empty();
    if ((answer1Exp == true) && (answer2Exp == false) && (answer3Exp == false)) {cout << "--- OK" << endl;}
    else {cout << "--- ERROR" << endl;}

    // Next test
}
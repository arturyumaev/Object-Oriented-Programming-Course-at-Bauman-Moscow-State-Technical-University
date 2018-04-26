#include "stdafx.h"
#include "ndvector.h"

void printStatus(int testIndex, bool status)
{
    if (status == true)
    {
        cout << "Test " << testIndex << " --- OK" << endl;
    }
    else
    {
        cout << "Test " << testIndex << " --- ERROR" << endl;
    }
}

void UnitTest()
{
    ndarray<int> a(10, 1);
    ndarray<int> b(5, 5);
    ndarray<int> c(10, 3);
    ndarray<int> d(4, 1);
    ndarray<int> o1(2, 1);
    ndarray<int> o2(o1);
    o2.fill(0, -1.0);

    (a.cross(c) == 30.0) ? printStatus(1, 1) : printStatus(1, 0);
    (a == b) ? printStatus(2, 0) : printStatus(2, 1);
    ((a[3] == 1) && (a.at(3) == 1)) ? printStatus(3, 1) : printStatus(3, 0);
    (d.len() == 2) ? printStatus(4, 1) : printStatus(4, 0);
    (~(d < a)) ? printStatus(5, 1) : printStatus(5, 0);
    (a < c) ? printStatus(6, 1) : printStatus(6, 0);
    (o1.is_orthogonal_to(o2)) ? printStatus(7, 1) : printStatus(7, 0);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");

    UnitTest();

    return 0;
}

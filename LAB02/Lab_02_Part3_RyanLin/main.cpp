#include "pyramid.h"
#include <iostream>
using namespace std;

int main()
{
    Pyramid pyramid1(1);
    Pyramid pyramid2(2);
    Pyramid pyramid3(17);
    Pyramid pyramid4(20);
    Pyramid pyramid5(34);
  
    pyramid1.create();
    pyramid1.flip();

    pyramid2.create();
    pyramid2.flip();

    pyramid3.create();
    pyramid3.flip();

    pyramid4.create();
    pyramid4.flip();

    pyramid5.create();
    pyramid5.flip();
}
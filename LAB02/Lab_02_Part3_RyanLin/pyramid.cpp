#include "pyramid.h"
#include <iostream>
using namespace std;

Pyramid::Pyramid(int p_rows)
{
    rows = p_rows;
}
void Pyramid::create(){
    
    int xCount=0;
   
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows - i - 1; j++)
        {
            cout << " ";
        }
        for(int k = 0; k < 2 * i + 1; k++)
        {
            cout << "X";
            xCount++;
        }
        cout << endl;
    }
    cout << "This pyramid has " << xCount << " X's" << endl;
}

void Pyramid::flip()
{
    cout << "The flipped version is: " << endl;
    for(int i = rows - 1; i >= 0; i--)
    {
        for(int j = 0; j < rows - i - 1; j++)
        {
            cout << " ";
        }
        for(int k = 0; k < 2 * i + 1; k++)
        {
            cout << "X";
        }
        cout << endl;
    }
}
#include <iostream>
#include <list>
using namespace std;

void reverse_list(list<int> &ml, int left,int right){
    list<int>::iterator start = ml.begin();
    list<int>::iterator end = ml.begin();
    int temp = 0;

    //get left point 
    for(int i = 0; i < left; i++){
        start++;
    }
    //get right point
    for(int i =0; i < right; i++){
        end++;
    }
    //reverse
    while(start != end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;

        if(start==end)
        {
            break;
        }
        end--;
    }
}

int main(){
    list<int> myList = {0,1,2,3,4,5,6,7,8,9};
    reverse_list(myList, 1, 5);
    cout << "Output: ";
    for (int value : myList) {
        cout << value << " ";
    }
    cout << endl;
}
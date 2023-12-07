#include <stack>
#include <iostream>

using namespace std;

class MyQueue{
public:
    stack<int> inputStack;
    stack<int> outputStack;
    void push(int x){
        inputStack.push(x);
        cout << "add element: " << x << endl;
    }

    int pop(){
        if(outputStack.empty()){
            while(!inputStack.empty()){
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        int frontValue = outputStack.top();
        outputStack.pop();
        cout <<"pop out element: "<< frontValue << endl;
        return frontValue;
    }

    int front(){
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        cout << "get element: " << outputStack.top() << endl;
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
int main(){
    MyQueue* obj = new MyQueue();

    obj->push(1);
    obj->push(3);

    int res1 = obj ->front();
    cout << "=====> the top value is: " << res1 << endl;
    obj->pop();

    obj->push(5);

    int res2 = obj->front();
    cout << "=====> the top value is: " << res2 << endl;
    obj->pop();
    obj->pop();

    bool res3 = obj->empty();
    cout << "=====> is myQueue empty?: " << res3 << endl;

}
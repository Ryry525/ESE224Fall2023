#include <queue>
#include <iostream>

using namespace std;

class MyStack{
public:
    queue<int> q1;
    queue<int> q2;
    
    void push(int x){
        cout << "add element: " << x << endl;
        if (q1.empty()){
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        else{
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    int pop(){
        int topValue = top();
        if(!q1.empty()){
            q1.pop();
        }
        else{
            q2.pop();
        }
        cout << "pop out element: " << topValue << endl;
        return topValue;
    }

    int top(){
        if(!q1.empty()){
            return q1.front();
        }
        else{
            return q2.front();
        }
    }

    bool empty(){
        return q1.empty() && q2.empty();
    }
    
};

int main(){
    MyStack* obj = new MyStack();

    obj->push(1);
    obj->push(3);

    int res1 = obj->top();
    cout << "=====> the top value is: " << res1 << endl;
    obj->pop();

    obj->push(5);

    int res2 = obj->top();
    cout << "=====> the top value is: " << res2 << endl;
    obj->pop();
    obj->pop();

    bool res3 = obj->empty();
    cout << "=====> is myStack empty?: " << res3 << endl;

    return 0;
}
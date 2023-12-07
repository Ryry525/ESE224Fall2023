#include <iostream>
#include <stack>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    stack<int> stack1, stack2;

    while(l1){
        stack1.push(l1->val);
        l1 = l1-> next;
    }

    while(l2){
        stack2.push(l2->val);
        l2 = l2->next;
    }
    int carry = 0;
    ListNode* result = nullptr;

    while(!stack1.empty() || !stack2.empty() || carry){
        int sum = carry;
        if (!stack1.empty()) {
            sum += stack1.top();
            stack1.pop();
        }
        if (!stack2.empty()) {
            sum += stack2.top();
            stack2.pop();
        }
        
        carry = sum / 10;
        sum %= 10;
        
        ListNode* newNode = new ListNode(sum);
        newNode->next = result;
        result = newNode;
    }
    
    return result;
}
// Function to print a linked list.
void printList(ListNode* head) {
    cout << "Output: ";
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << ", ";
        }
        head = head->next;
    }
    cout << endl;
}

ListNode* createList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    cout << "Enter a number (-1 to end): ";
    int value;
    while (cin >> value && value != -1) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}

int main() {
    cout << "Enter the first list of numbers:" << endl;
    ListNode* l1 = createList();
    
    cout << "Enter the second list of numbers:" << endl;
    ListNode* l2 = createList();

    // Add the two numbers.
    ListNode* result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}
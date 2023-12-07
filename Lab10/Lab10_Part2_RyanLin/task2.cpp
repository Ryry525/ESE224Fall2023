#include <iostream>
#include <vector>

using namespace std;

template <typename Type>
struct Node{
    Type value;
    Node* prev;
    Node* next;

    Node(): next(nullptr), prev(nullptr) {}
    Node(Type x, Node* next = nullptr, Node* prev = nullptr): value(x), next(next), prev(prev) {} 
    ~Node() {}
};

template<typename Type>
void printDoublyLinkedList(Node<Type>* head){
    while(head)
    {
        cout << head->value<<"<==>";
        head = head->next;
    }
    if(head==nullptr)
    {
        cout <<"NULL" << endl;
    }
    cout << endl;
}

template<typename Type>
Node<Type>* createDoublyLinkedList(vector<Type> vec){
    Node<Type>* head = new Node<Type>(vec[0]);
    Node<Type>* cur = head;

    for(int i = 1; i <vec.size(); i++)
    {
        Node<Type>* tmp = new Node<Type>(vec[i]);
        cur->next = tmp;
        tmp->prev = cur;
        cur= cur->next;
    }
    return head;
}

template<typename Type>
void reverseDoublyLinkedList(Node<Type>*& head) {
    Node<Type>* temp = nullptr;
    Node<Type>* current = head;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }
}

int main(){
    vector<int> dll1 = {1,2,3,4,5,6,7,8,9};
    vector<int> dll2 = {3,2,1,1,2,3,4,5};

    Node<int>* dll1_head = createDoublyLinkedList(dll1);
    Node<int>* dll2_head = createDoublyLinkedList(dll2);

    cout << "Double Linked List #1:" << endl;
    printDoublyLinkedList(dll1_head);

    reverseDoublyLinkedList(dll1_head);

    cout << "Doubly Linked List #1 after reverse:" <<endl;
    printDoublyLinkedList(dll1_head);

    cout << "Double Linked List #2:" << endl;
    printDoublyLinkedList(dll2_head);

    reverseDoublyLinkedList(dll2_head);

    cout << "Doubly Linked List #2 after reverse:" <<endl;
    printDoublyLinkedList(dll2_head);
}
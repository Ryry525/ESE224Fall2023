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
void removeDuplicates(Node<Type>*& head) {
    Node<Type>* current = head;
    while (current != nullptr) {
        Node<Type>* runner = current->next;
        while (runner != nullptr && runner->value == current->value) {
            Node<Type>* temp = runner;
            runner = runner->next;
            if (runner != nullptr) {
                runner->prev = temp->prev;
            }
            delete temp;
        }
        current->next = runner;
        if (runner != nullptr) {
            runner->prev = current;
        }
        current = runner;
    }
}

int main(){
    vector<int> dll = {1,2,2,3,4,4,4,5};

    Node<int>* dll_head = createDoublyLinkedList(dll);

    cout << "Double Linked List:" << endl;
    printDoublyLinkedList(dll_head);

    removeDuplicates(dll_head);

    cout << "Doubly Linked List after removing duplicates:" <<endl;
    printDoublyLinkedList(dll_head);

}
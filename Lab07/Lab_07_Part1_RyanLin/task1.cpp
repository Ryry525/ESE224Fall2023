#include <iostream>

using namespace std;

template <typename Type>
class Node {
public:
    Type data;
    Node* next;

    Node(Type value) : data(value), next(nullptr) {}
};

template <typename Type>
Node<Type>* createdLinkedList(Type* arr, int size) {
    if (arr == nullptr || size == 0) return nullptr;

    Node<Type>* head = new Node<Type>(arr[0]);
    Node<Type>* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new Node<Type>(arr[i]);
        current = current->next;
    }

    return head;
}

template <typename Type>
void printLinkedList(Node<Type>* head) {
    Node<Type>* current = head;

    while (current) {
        cout << current->data;
        if (current->next) {
            cout << ", ";
        }
        current = current->next;
    }

    cout << endl;
}

template <typename Type>
Node<Type>* reverse(Node<Type>* head)
{
    Node<Type>* current = head;
    Node<Type>* pre = NULL;
    Node<Type>* next = NULL;

    while(current)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    return pre;
}
int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    cout << "created linked from list array:" << endl;
    Node<int>* node = createdLinkedList(arr, 7);
    printLinkedList(node);

    cout << "reverse linked list:" <<endl;
    Node<int>* reversed_node = reverse(node);
    printLinkedList(reversed_node);
}
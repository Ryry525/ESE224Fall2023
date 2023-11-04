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
Node<Type>* removeDuplicates(Node<Type>* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // No duplicates to remove for empty or single-node lists
    }

    Node<Type>* current = head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node<Type>* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
    }

    return head;
}

int main() {
    int arr[] = {1, 1, 2, 3, 3, 3, 4, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Creating linked list:" << endl;
    Node<int>* node = createdLinkedList(arr, size);
    printLinkedList(node);

    cout << "Removing duplicates:" << endl;
    Node<int>* remDuplicated = removeDuplicates(node);
    printLinkedList(remDuplicated);

    return 0;
}

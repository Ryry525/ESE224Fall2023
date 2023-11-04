#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Define a structure for a node in the linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Define a class for a basic linked list
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to add a new element to the end of the linked list
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to get the head of the linked list
    Node* getHead() {
        return head;
    }

    // Function to print the elements of the linked list
    void print() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to manually delete the linked list to free memory
    void deleteList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    LinkedList list1;
    LinkedList list2;
    LinkedList resultList;

    string line;
    int value;

    // Read and populate list1 from the first line
    getline(inputFile, line);
    istringstream iss1(line);
    while (iss1 >> value) {
        list1.push_back(value);
    }

    // Read and populate list2 from the second line
    getline(inputFile, line);
    istringstream iss2(line);
    while (iss2 >> value) {
        list2.push_back(value);
    }

    // Calculate the sum of corresponding elements and store them in resultList
    Node* current1 = list1.getHead();
    Node* current2 = list2.getHead();
    while (current1 && current2) {
        resultList.push_back(current1->data + current2->data);
        current1 = current1->next;
        current2 = current2->next;
    }

    // Print the values of list1, list2, and resultList
    cout << "List 1: ";
    list1.print();
    cout << "List 2: ";
    list2.print();
    cout << "Result List: ";
    resultList.print();

    // Write the values of resultList to the output file
    Node* result = resultList.getHead();
    while (result) {
        outputFile << result->data << " ";
        result = result->next;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    // Manually delete the lists to free memory
    list1.deleteList();
    list2.deleteList();
    resultList.deleteList();

    return 0;
}

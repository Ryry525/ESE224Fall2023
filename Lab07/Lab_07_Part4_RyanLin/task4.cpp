#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(T value, Node *ptr = nullptr) : data(value), next(nullptr) {}
        ~Node() {}
    };
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void push_back(T value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode; // add new node to the end
        }
    }
    // Delete node, returns true or false
    bool deleteNode(T value)
    {
        if (!head)
        {
            return false; // Empty list, node not found
        }

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node *current = head;
        while (current->next)
        {
            if (current->next->data == value)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                return true;
            }
            current = current->next;
        }

        return false; // Node not found
    }

    void displayDeletedNodeDetails(T value)
    {
        int nodePosition = 0;
        Node *current = head;
        while (current)
        {
            nodePosition++;
            if (current->data == value)
            {
                cout << "Deleted node with value " << value << " at position " << nodePosition << endl;
                return;
            }
            current = current->next;
        }
        cout << "Node with value " << value << " not found." << endl;
    }
    size_t size() const
    {
        size_t count = 0;
        Node *current = head;
        while (current)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main()
{
    LinkedList<int> list;
    list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.displayDeletedNodeDetails(2);
	list.displayDeletedNodeDetails(9);
	list.deleteNode(4);
	list.displayDeletedNodeDetails(4);

    return 0;
}

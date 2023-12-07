#include <iostream>
#include <stack>
#include <iterator>
using namespace std;

class CustomContainer
{
private:
	stack<int> containerStack;

public:
	// Adds an integer to the container
	void add(int value)
	{
		containerStack.push(value);
	}

	// Returns the element at the specified index
	int get(int index)
	{
		if (index < 0 || index >= containerStack.size())
		{
			cout << "Invalid index input" << endl;
			return -1;
		}

		stack<int> tempStack;

		// pop elements until the element of the specified index is reached
		for (int i = 0; i < index; ++i)
		{
			// push top value and pop 
			tempStack.push(containerStack.top());
			containerStack.pop();
		}

		int resultElement = containerStack.top(); // value of element at the index
		
		while (!tempStack.empty())
		{
			containerStack.push(tempStack.top());
			tempStack.pop();
		}

		return resultElement;
	}

	// Removes all occurrences of the specified value from the container
	void remove(int value)
	{
		stack<int> tempStack;

		for (int i = 0; i < containerStack.size(); ++i)
		{
			if (containerStack.top() == value)
			{
				containerStack.pop();
			}

			else
			{
				tempStack.push(containerStack.top());
				containerStack.pop();
			}
		}

		while (!tempStack.empty())
		{
			containerStack.push(tempStack.top());
			tempStack.pop();
		}
	}

	class CustomIterator
	{
	private:
		stack<int>* stackPtr;
		int currentIndex;

	public:
		// initialize constructor here
		CustomIterator(stack<int>* ptr, int index) : stackPtr(ptr), currentIndex(index) {}

		int operator*() const
		{
			if (currentIndex < 0 || currentIndex >= static_cast<int>(stackPtr->size()))
			{
				cout << ("Iterator is out of range") << endl;
			}

			stack<int> tempStack = *stackPtr;

			for (int i = 0; i < currentIndex; ++i)
			{
				tempStack.pop();
			}

			return tempStack.top();
		}

		// Moves the iterator to the next position
		void operator++()
		{
			if (currentIndex < 0 || currentIndex >= static_cast<int>(stackPtr->size()))
			{
				cout << ("Iterator is out of range") << endl;
			}

			++currentIndex;
		}

		// Check if two iterators are not equal
		bool operator!=(const CustomIterator& other) const
		{
			return currentIndex != other.currentIndex;
		}
	};

	CustomIterator begin() const
	{
		return CustomIterator(const_cast<stack<int> *>(&containerStack), 0);
	}

	CustomIterator end() const
	{
		return CustomIterator(const_cast<stack<int> *>(&containerStack), containerStack.size());
	}
};

int main()
{
	CustomContainer container;

	container.add(1);
	container.add(2);
	container.add(3);
	container.add(2);
	container.add(4);
    
	container.remove(2);
	
	cout << "Container Elements: ";

	for (CustomContainer::CustomIterator it = container.begin(); it != container.end(); ++it)
	{
		cout << *it << " ";
	}

	cout << endl;
	return 0;
}
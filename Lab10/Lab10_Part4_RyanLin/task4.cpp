#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& vec, int n, int i)
{
	// INITIALIZE largest AS ROOT INDEX
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// HANDLE LEFT CHILD LARGER THAN ROOT
	if (l < n && vec[l] > vec[largest])
	{
		largest = l;
	}

	// HANDLE RIGHT CHILD LARGER THAN ROOT
	if (r < n && vec[r] > vec[largest])
	{
		largest = r;
	}

	// largest IS NOT ROOT
	if (largest != i)
	{
		swap(vec[i], vec[largest]);
		maxHeapify(vec, n, largest);
	}
}

void maxHeapSort(vector<int>& vec, int n)
{
	// REARRANGE THE ARRAY
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		maxHeapify(vec, n, i);
	}

	for (int i = n - 1; i > 0; i--)
	{
		swap(vec[0], vec[i]);					// REVERSE TO MAKE ASCENDING ORDER
		maxHeapify(vec, i, 0);
	}
}

void extractTop(vector<int>& vec, int k)
{
	int n = vec.size();

	// BUILD MAX HEAP
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		maxHeapify(vec, n, i);
	}

	// EXTRACT TOP K ELEMENTS
	for (int i = n - 1; i >= n - k; i--)
	{
		swap(vec[0], vec[i]);
		maxHeapify(vec, i, 0);
		cout << vec[i] << "  ";
	}
}

int main()
{
	vector<int> heap = { 9,2,9,7,2,4,5,4,9,8 };
	maxHeapSort(heap, heap.size());
	cout << "Heap after sorted (ascending): " << endl;

	for (int i = 0; i < heap.size(); i++)
	{
		cout << heap[i] << "  ";
	}

	cout << endl;

	int k;
	cout << "Enter top k greatest value elements to be printed: " << endl;
	cin >> k;
	cout << "Top " << k << " elements:" << endl;
	extractTop(heap, k);

	return 0;
}
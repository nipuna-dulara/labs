// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (root != largest)
    {
        swap(arr[largest], arr[root]);
        heapify(arr, n, largest);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
    vector<int> arr;
    int ele;
    cin >> ele;
    while (getchar() != '\n')
    {
        arr.push_back(ele);
        cin >> ele;
    }
    arr.push_back(ele);

    int n = arr.size();
    int heap_arr[n];
    for (int i = 0; i < n; i++)
    {
        heap_arr[i] = arr[i];
    }

    cout << "Input array" << endl;
    displayArray(heap_arr, n);

    heapSort(heap_arr, n);

    cout << "Sorted array" << endl;
    displayArray(heap_arr, n);
}

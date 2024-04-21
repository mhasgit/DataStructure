#include <iostream>

using namespace std;

void insert(int arr[], int position, int value, int& numOfElements, int capacity)
{
    if (position < 0 || position > numOfElements || numOfElements >= capacity) {
        // If the position is out of the existing range or if the array is full
        cout << "Invalid operation" << endl;
        return;
    }

    // Shift elements to the right to make room for the new element
    for (int i = numOfElements; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    numOfElements++;  // Increase the number of elements in the array after insertion
}

int main()
{
    int capacity = 10;  // Total capacity of the array
    int arr[10] = {12, 43, 10, 55, 45, 67, 22, 88, 77};  // Initial elements
    int numOfElements = 9, position = 4, value = 99;  // Initial number of elements, insertion position, and value

    cout << "Array before insertion:" << endl;
    for (int i = 0; i < numOfElements; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insert(arr, position, value, numOfElements, capacity);

    cout << "Array after insertion:" << endl;
    for (int i = 0; i < numOfElements; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
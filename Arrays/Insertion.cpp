#include <iostream>

using namespace std;

void insert(int arr[], int position, int value, int& numOfElements, int capacity)
{
    if (position < 0 || position >= capacity || numOfElements || numOfElements >= capacity)
    {
        cout << "\n\nInvalid position\n\n";
        return;
    }

    // Shifting array elements to right for new value
    for (int i = numOfElements; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
}

int main()
{
    int capacity = 10;
    int arr[10] = {12, 43, 10, 55, 45, 67, 22, 88, 77, 90};
    int numOfElements = 9, position = 4, value = 99;

    cout << "Array before Insersion" << endl;
    for (int i = 0; i < capacity; i++)
    {
        cout << arr[i] << " ";
    }

    insert(arr, position, value, numOfElements, capacity);

    cout << "\nArray After Insersion" << endl;
    for (int i = 0; i < capacity; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int search(int arr[], int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
       return -1;
}

// Function to search for all occurrences of an element in the array
vector<int> searchAll(int arr[], int key, int size) {
    vector<int> indices;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }
    return indices;
}

void testingSearchAll()
{
    int arr[10] = {12, 43, 10, 55, 45, 67, 22, 88, 10, 55};
    int numOfElements = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    cout << "Array Elements:" << endl;
    for (int i = 0; i < numOfElements; i++) {
        cout << arr[i] << " ";
    }

    vector<int> indices = searchAll(arr, key, numOfElements);

    if (!indices.empty()) {
        cout << "\nElement " << key << " found at indices: ";
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "\nElement " << key << " not found in the array." << endl;
    }
}

int main()
{
    int arr[10] = {12, 43, 10, 55, 45, 67, 22, 88, 10, 55};
    int numOfElements = sizeof(arr) / sizeof(arr[0]);
    int  key = 10;

    cout << "Array Elements" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    int index = search(arr, key, numOfElements);

    if (index != -1) {
        cout << "\nElement " << key << " found at index " << index << "." << endl;
    } else {
        cout << "\nElement " << key << " not found in the array." << endl;
    }   

    return 0;
}
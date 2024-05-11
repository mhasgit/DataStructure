#include <iostream>

using namespace std;

// deletes Specifc position
void deleteArray(int arr[], int& numOfElements, int positionToDelete)
{
    if (positionToDelete < 0 || positionToDelete >= numOfElements)
    {
        cout << "\nInvalid Position!!";
        return;
    }

    // Shifting to the left
    for (int i = positionToDelete; i < numOfElements - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    numOfElements--;
}

bool deleteValue(int arr[], int& numOfElements, int valueToDelete)
{
    int positionToDelete = -1;

    for (int i = 0; i < numOfElements; i++)
    {
        if (arr[i] == valueToDelete)
        {
            positionToDelete = i;
            break;
        }
    }
    

    if (positionToDelete != -1)
    {
        for (int i = positionToDelete; i < numOfElements - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        numOfElements--;
        return true;
    }
    return false;
}

void testingDeleteValue()
{
    int capacity = 10; // Total capacity of the array
    int arr[10] = {12, 43, 10, 55, 45, 67, 22, 88, 77, 90};
    int numOfElements = 10; // Number of actual elements
    int valueToDelete = 10; // Value to delete

    cout << "Array before Deletion" << endl;
    for (int i = 0; i < numOfElements; i++) {
        cout << arr[i] << " ";
    }

    bool deleted = deleteValue(arr, numOfElements, valueToDelete);

    cout << "\n\nArray After Deletion" << endl;
    if (deleted) {
        for (int i = 0; i < numOfElements; i++) {
            cout << arr[i] << " ";
        }
        cout << "\nValue deleted successfully." << endl;
    } else {
        cout << "\nValue not found in the array." << endl;
    }
}



int main(int argc, char const *argv[])
{
    testingDeleteValue();
    int arr[10] = {12, 43, 10, 55, 45, 67, 22, 88, 77, 90};
    int numOfElements = 9, position = 4, valueToDelete = 99, positionToDelete = 5;

    cout << "Array before Deletion" << endl;
    for (int i = 0; i < numOfElements; i++)
    {
        cout << arr[i] << " ";
    }

    deleteArray(arr, numOfElements, positionToDelete);

    cout << "\n\nArray After Deletion" << endl;
    for (int i = 0; i < numOfElements; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

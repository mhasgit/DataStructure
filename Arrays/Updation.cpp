#include <iostream>

using namespace std;

void UpdateArray(int arr[], int position, int newValue)
{
    if (position < 0 && position <= sizeof(arr) / sizeof(arr[0]))
    {
        cout << "Invalid position";
        return;
    }
    arr[position] = newValue;   
}

int main()
{
    int arr[10] = {12, 43, 10, 55, 45, 67, 22, 88, 77};
    int numOfElements = 9, position = 4, value = 10;

    cout << "Array before Insersion" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    UpdateArray(arr, position, value);

    cout << "Array After Insersion" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    

    return 0;
}

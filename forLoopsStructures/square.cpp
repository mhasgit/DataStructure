#include <iostream>

using namespace std;

void drawShapeL()
{
    int height = 5;
    int width = 5;

    for (int i = 0; i < height; i++)
    {
        if (i < height - 1)
        {
            cout << "* " << endl;
        }
        else
        {
            for (int i = 0; i < width; i++)
            {
                cout << "* ";
            }
            cout << endl;
        }  
    }
    
}

void drawSquare()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "*";
    }
    
    return 0;
}
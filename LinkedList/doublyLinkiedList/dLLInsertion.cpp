#include <iostream>

using namespace std;

struct Node
{
    Node* prev;
    int data;
    Node* next;
};

void insertFront(Node **head, int data)
{
    Node* newNode = new Node();

    newNode->data = data;

    newNode->next = *head;
    newNode->prev = NULL;

    if ((*head) != NULL)
    {
         (*head)->prev = newNode;
    }
    
    *head = newNode;
}

void insertAfter(Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        cout << "Previous node is requre!" << endl;
        return;
    }

    Node* newNode = new Node();

    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if (newNode->next != NULL)
    {
        newNode->prev->next = newNode;
    }
}


int main(int argc, char const *argv[])
{
    Node* head = NULL;

    insertFront(&head, 10);
    insertFront(&head, 20);
    insertFront(&head, 30);
    insertFront(&head, 40);
    insertAfter(head, 60);
    return 0;
}

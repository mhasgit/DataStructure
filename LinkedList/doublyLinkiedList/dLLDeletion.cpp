#include <iostream>

using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

void insertFront(Node **head, int data)
{
    Node *newNode = new Node();

    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

Node *deleteFirst(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }

    Node *tempNode = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    delete (tempNode);
    return head;
}

Node *deleteLast(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }

    Node *tempNode = head;
    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }

    if (tempNode->prev == NULL)
    {
        head = NULL; // The list will be empty after this node is deleted
    }
    else
    {
        tempNode->prev->next = NULL; // Set the next of the second last node to NULL
    }
    delete (tempNode);

    return head;
}

Node* deleteNodeWithValue(Node** head, int valueToDelete)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return NULL;
    }

    Node* tempNode = *head, *prevNode = NULL;

    while (tempNode != NULL && tempNode->data != valueToDelete)
    {
        tempNode = tempNode->next;
    }
    
    if (tempNode == NULL)
    {
        cout << "Value not found in the list" << endl;
        return *head;
    }
    
    if (tempNode == *head)
    {
        *head = tempNode->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        if (tempNode->next != NULL)
        {
            tempNode->next->prev = tempNode->prev;
        }
        tempNode->prev->next = tempNode->next;
    }

    delete(tempNode);
    return *head;
}

void displayList(Node *node) {
    if (node == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    while (node != NULL) {
        cout << node->data;
        if (node->next != NULL)
            cout << "<==>";
        node = node->next;
    }
    cout << "-->NULL" << endl;
}


int main(int argc, char const *argv[])
{
    Node *head = NULL;

    insertFront(&head, 10);
    insertFront(&head, 20);
    insertFront(&head, 30);
    insertFront(&head, 40);
    displayList(head);
    head = deleteNodeWithValue(&head, 30);
    displayList(head);
    return 0;
}

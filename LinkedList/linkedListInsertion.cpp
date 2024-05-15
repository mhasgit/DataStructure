#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertAtFirst(Node **head, int data)
{
    Node *newNode = new Node();

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAfterNode(Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        cout << "The given node is required, cannot be null " << endl;
        return;
    }

    Node *newNode = new Node();

    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode; 
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    // if the list is empty, the new node becomes the first node
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    
}

void displayLinkedList(Node *node)
{
    while(node != NULL)
    {
        cout << node->data;
        if (node->next != NULL) 
        cout << "-->";
        node = node->next;
    }
    cout << "-->null" << endl;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    insertAtFirst(&head, 10);
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 30);
    insertAtFirst(&head, 40);
    insertAfterNode(head, 50);
    insertAtEnd(&head, 60);

    cout << "Final linked list: " << endl;
    displayLinkedList(head);
    return 0;
}

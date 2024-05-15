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

Node* deleteFirst(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *tempNode = head;
    head = head->next;
    delete(tempNode);
    return head;
}

Node* deleteLast(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    
    if (head->next == NULL)
    {
        delete(head);
        return NULL;
    }

    Node *secondLastNode = head;
    while (secondLastNode->next->next != NULL)
    {
        secondLastNode = secondLastNode->next;
    }
    delete(secondLastNode);
    return head;    
}

void displayLinkedList(Node *node)
{
    if (node == NULL)
    {
        cout << "Linked List is empty" << endl;
        return; 
    }

    while (node != NULL)
    {
        cout << node->data;
        if (node->next != NULL)
            cout << "-->";
        node = node->next;
    }
    cout << "-->null" << endl;
}

Node *deleteAtSpecific(Node *prevNode)
{
}

int main()
{
    Node *head = NULL;
    insertAtFirst(&head, 10);
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 30);
    displayLinkedList(head);
    cout << endl;
    head = deleteFirst(head);
    cout << endl;
    displayLinkedList(head);
    head = deleteLast(head);
    cout << endl;
    displayLinkedList(head);

    return 0;
}
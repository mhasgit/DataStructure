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

Node* deleteFirst(Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node* tempNode = head;
    head = head->next;
    delete(tempNode);
    return head;
}

Node* deleteLast(Node* head)
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
        Node* secondLast = head;
        while (secondLast->next->next != NULL)
        {
            secondLast = secondLast->next;
        }
        delete(secondLast->next);
        secondLast->next = NULL;
        return head;
    
    
       
}

void displayLinkedList(Node* node)
{
    if (node == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }

    while (node != NULL)
    {
        cout << node->data;
        if (node->next != NULL)
        {
            cout << "-->";
        }
        node = node->next;
    }
    cout << "-->null" << endl;
    
    
}

Node* deleteAtSpecific(Node **head, int valueToDelete)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }

    Node *tempNode = *head, *prevNode = NULL;

    if (tempNode != NULL && tempNode->data == valueToDelete)
    {
        *head = tempNode->next;
        delete(tempNode);
        return *head;
    }

    while (tempNode != NULL && tempNode->data != valueToDelete)
    {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    
    if (tempNode == NULL)
    {
        cout << "Value not found in the list" << endl;
        return *head;
    }
    
    prevNode->next = tempNode->next;
    delete(tempNode);
    return *head;
    
}

int main()
{
    Node *head = NULL;
    insertAtFirst(&head, 10);
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 30);
    insertAtFirst(&head, 40);
    insertAtFirst(&head, 50);
    displayLinkedList(head);
    cout << endl;
    head = deleteFirst(head);
    cout << endl;
    displayLinkedList(head);
    head = deleteLast(head);
    cout << endl;
    displayLinkedList(head);
    head = deleteAtSpecific(&head, 40);
    displayLinkedList(head);

    return 0;
}
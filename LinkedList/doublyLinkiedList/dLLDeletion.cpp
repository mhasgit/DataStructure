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
        (*head)->prev = *head;
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

Node* deleteAfterSpecificNode(Node* head, int data)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return NULL;
    }
    

}

void displayList(Node *node)
{
    struct Node *last;

    while (node != NULL)
    {
        cout << node->data << "<==>";
        last = node;
        node = node->next;
    }
    if (node == NULL)
        cout << "NULL";
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;

    insertFront(&head, 10);
    insertFront(&head, 20);
    insertFront(&head, 30);
    insertFront(&head, 40);
    displayList(head);

    return 0;
}

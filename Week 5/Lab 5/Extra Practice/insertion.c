#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr);
struct Node *insertAtFirst(struct Node *head, int data);
struct Node *insertAtEnd(struct Node *head, int data);
struct Node *insertAfterNode(struct Node *prevNode, int data);
struct Node *insertAtIndex(struct Node *head, int data, int index);
void freeLinkedList(struct Node *head);

int main(void)
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;

    // Allocate memory for the Linked list in the Heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // Linked first and second node
    head->data = 7;
    head->next = second;

    // Linked second and third node
    second->data = 11;
    second->next = third;

    // Linked third and fourth node
    third->data = 41;
    third->next = fourth;

    // Terminate the list in the fourth node
    fourth->data = 66;
    fourth->next = NULL;

    // Printing all the elements of the Linked List before Insertion
    printf("Linked list before insertion\n");
    linkedListTraversal(head);

    // Case 1: Insert at the Beginning
    head = insertAtFirst(head, 56);
    printf("\nLinked list after insertion at the Beginning\n");
    linkedListTraversal(head);

    // Case 2: Insert at the End
    head = insertAtEnd(head, 56);
    printf("\nLinked list after insertion at the End\n");
    linkedListTraversal(head);

    // Case 3: Insert after a Node
    head = insertAfterNode(third, 45);
    printf("\nLinked list after insertion after a Node\n");
    linkedListTraversal(head);

    // Case 4: Insert in Between
    head = insertAtIndex(head, 56, 2);
    printf("\nLinked list after insertion in Between the Linked List\n");
    linkedListTraversal(head);

    // Free allocated memory
    freeLinkedList(head);

    return 0;
}

// Printing all the elements of the Linked List
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: Insert at the Beginning
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;

    return ptr;
}

// Case 2: Insert at the End
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;

    return head;
}

// Case 3: Insert after a Node
struct Node *insertAfterNode(struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return prevNode;
}

// Case 4: Insert in Between
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head;

    for (int i = 0; i < index - 1 && p != NULL; i++)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Index out of range\n");
        return head;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Function to free the entire linked list
void freeLinkedList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

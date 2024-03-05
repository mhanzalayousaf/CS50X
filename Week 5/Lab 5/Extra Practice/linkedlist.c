#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(void)
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

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

    linkedListTraversal(head);

    // Free allocated memory
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}

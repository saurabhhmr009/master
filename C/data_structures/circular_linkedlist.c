/* Program for the Circular Linked List.
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct linked {
    int data;
    struct linked *next;
}Node;

// Pointer which points to the last node of the linked list.  
Node *last;

// Creates the Head of the Circular Linked List.
Node* create_head(Node *start) {
    if(start == NULL) {
        int data;
        start = (Node*)malloc(sizeof(Node));
        printf("Enter the data for the head: \n");
        scanf("%d", &data);
        start->data = data;
        start->next = start;
        last = start;
    }
    else {
        printf("Head is already created.\n");
    }
    return start;
}

// Creates and adds the node to the main linked list.
Node* create_node(Node *start) {
    Node *new_node = NULL;
    Node *temp = start;
    int data;

    new_node = (Node*)malloc(sizeof(Node));
    printf("Enter the data for the node: \n");
    scanf("%d", &data);
    new_node->data = data;
    new_node->next = start;

    if(start->next == start) {
        start->next = new_node;
    }
    else {
        while(temp->next != start) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    last = new_node;
    return start;
}

// Inserts node at the begining of the list.
Node* insert_beg(Node* start) {
    int data;
    Node *new_node = NULL;
    new_node = (Node*)malloc(sizeof(Node));
    printf("Enter the data for the node: \n");
    scanf("%d", &data);
    new_node->data = data;
    last->next = new_node;
    new_node->next = start;
    return new_node;
}

// Deletes the node at the begining of the list.
Node* delete_beg(Node *start) {
    last->next = start->next;
    start->next = NULL;
    free(start);
    return last->next;
}

// Inserts the node at the end of the list.
Node* insert_end(Node *start) {
    int data;
    Node *new_node = NULL;
    new_node = (Node*)malloc(sizeof(Node));
    printf("Enter the data for the node: \n");
    scanf("%d", &data);
    new_node->data = data;

    last->next = new_node;
    new_node->next = start;
    last = new_node;
    return start;
}

Node* delete_end(Node *start) {
    Node *temp = start, *prev;
    do {
        prev = temp;
        temp = temp->next;
    }
    while(temp != last);
    prev->next = last->next;
    last = prev;
    temp->next = NULL;
    free(temp);
    return last->next;
}

// Deletes the next node which matches the item.
Node* delete_mid(Node *start) {
    Node *temp = last->next, *extra;
    int item;

    printf("Enter the item after which you want to delete the node: \n");
    scanf("%d", &item);

    while(temp->data != item) {
        temp = temp->next;
    }
    extra = temp->next;
    temp->next = temp->next->next;
    extra->next = NULL;
    free(extra);
    return start;
}

Node* insert_mid(Node *start) {
    int data, item;
    Node *new_node = NULL, *temp = last->next, *extra;
    new_node = (Node*)malloc(sizeof(Node));
    printf("Enter the data for the node: \n");
    scanf("%d", &data);
    printf("Enter the item after which you want to insert the node: \n");
    scanf("%d", &item);
    new_node->data = data;

    while(temp->data != item) {
        temp = temp->next;
    }
    extra = temp->next;
    temp->next = new_node;
    new_node->next = extra;

    return start;
}

// Prints the Circular Linked List.
void print_list(Node *start) {
    Node *temp = start;

    if(start != NULL) {
        do {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        while (temp != start);
    }
    printf("%d\n", last->next->data);
}

int main(void) {
    Node *start = NULL;

    // Creates the head node
    start = create_head(start);

    // Adds node to the list.
    start = create_node(start);
    start = create_node(start);
    start = create_node(start);
    start = create_node(start);
    print_list(start);

    // Insert operations in the Circular linked list.
    start = insert_beg(start);
    print_list(start);
    start = insert_end(start);
    print_list(start);
    start = insert_mid(start);
    print_list(start);

    // Delete operations in the Circular linked list.
    start = delete_beg(start);
    print_list(start);
    start = delete_end(start);
    print_list(start);
    start = delete_mid(start);
    print_list(start);

    return 0;
}
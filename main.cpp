#include <stdio.h>
#include <stdlib.h>
//NAME: JOHN KIMANI NJUGUNA
//SCT222-0141/2023
//ASSINGMENT 2
//USING MERGE SORT
// Define a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to merge two sorted linked lists
struct Node* merge(struct Node* list1, struct Node* list2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining elements
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Example linked lists
    struct Node* list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(5);

    struct Node* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);

    printf("List 1: ");
    printList(list1);
    
    printf("List 2: ");
    printList(list2);
    
    struct Node* mergedList = merge(list1, list2);
    
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
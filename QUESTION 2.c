#include <stdio.h>
#include <stdlib.h>
// NAME ; JOHN KIMANI NJUGUNA 
//REG NO ; SCT222-0141/2023
// QUESTION 2

// Define a node structure for the doubly linked list
typedef struct Node {
    int digit;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int digit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->digit = digit;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to add two doubly linked lists
Node* addTwoLists(Node* first, Node* second) {
    Node* result = NULL;
    Node* temp = NULL;
    int carry = 0;
    
    // Traverse both lists from the end
    while (first != NULL || second != NULL || carry) {
        int sum = carry;
        
        if (first != NULL) {
            sum += first->digit;
            first = first->next;
        }
        
        if (second != NULL) {
            sum += second->digit;
            second = second->next;
        }
        
        carry = sum / 10;
        sum = sum % 10;
        
        // Create a new node for the result
        Node* newNode = createNode(sum);
        
        // Insert the new node at the beginning of the result list
        newNode->next = result;
        if (result != NULL) {
            result->prev = newNode;
        }
        result = newNode;
    }
    
    return result;
}

// Function to print the doubly linked list
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->digit);
        node = node->next;
    }
    printf("\n");
}

// Function to free the doubly linked list
void freeList(Node* node) {
    while (node != NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}

// Main function
int main() {
    // Create first doubly linked list: 2 -> 5 -> 9 (represents 259)
    Node* first = createNode(2);
    first->next = createNode(5);
    first->next->prev = first;
    first->next->next = createNode(9);
    first->next->next->prev = first->next;

    // Create second doubly linked list: 3 -> 8 -> 1 (represents 381)
    Node* second = createNode(3);
    second->next = createNode(8);
    second->next->prev = second;
    second->next->next = createNode(1);
    second->next->next->prev = second->next;

    // Add the two lists
    Node* sumList = addTwoLists(first, second);

    // Print the result
    printf("Sum stored in a doubly linked list: ");
    printList(sumList);

    // Print the sum as an integer
    printf("259 + 381 = ");
    Node* current = sumList;
    int total = 0;
    int placeValue = 1;
    while (current != NULL) {
        total += current->digit * placeValue;
        placeValue *= 10;
        current = current->next;
    }
    printf("%d\n", total);

    // Free the allocated memory
    freeList(first);
    freeList(second);
    freeList(sumList);

    return 0;
}
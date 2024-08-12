#include <stdio.h>
#include <stdlib.h>

// Linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add two numbers represented by linked lists
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = createNode(0);
    Node* curr = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        curr->next = createNode(sum % 10);
        carry = sum / 10;
        curr = curr->next;
    }

    if (carry > 0) {
        curr->next = createNode(carry);
    }

    return dummy->next;
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    // Create the first linked list: 3 -> 1 -> 5
    Node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    // Create the second linked list: 5 -> 9 -> 2
    Node* l2 = createNode(2);
    l2->next = createNode(1);
    l2->next->next = createNode(5);

    printf("First number: ");
    printList(l1);
    printf("Second number: ");
    printList(l2);

    Node* result = addTwoNumbers(l1, l2);
    printf("Sum: ");
    printList(result);

    return 0;
}
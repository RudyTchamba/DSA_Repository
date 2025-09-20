#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

//Without using the buffer
void deleteDups(Node* head){
    if(head == NULL || head->next == NULL){
        return;
    }

    Node* curr = head;
    while(curr->next != NULL){
        Node* runner = curr;
        while(runner->next != NULL){
            if(runner->next->data == curr->data){
                Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            }else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

// Function to remove duplicates from an unsorted linked list using a temporary buffer
void removeDuplicates(Node* head) {
    if (head == NULL || head->next == NULL) { // Base case: if the list is empty or has only one node, return
        return;
    }

    // Create a temporary buffer (array) to store the unique elements
    int buffer[100] = {0}; // Assume the values in the list are non-negative integers less than 100
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (buffer[curr->data] == 0) { // If the current element is not in the buffer
            buffer[curr->data] = 1; // Mark it as present in the buffer
            prev = curr; // Update the previous pointer
            curr = curr->next; // Move to the next node
        } else { // If the current element is in the buffer
            Node* temp = curr; // Store the current node
            prev->next = curr->next; // Update the previous node's next pointer to skip the current node
            curr = curr->next; // Move to the next node
            free(temp); // Free the memory occupied by the duplicate node
        }
    }
}

// Function to add a new node to the linked list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 4);
    addNode(&head, 5);
    addNode(&head, 2);

    printf("Original list: ");
    printList(head);

    deleteDups(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
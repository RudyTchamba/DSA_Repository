#include <stdio.h>
#include <stdlib.h>

// Linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* nthToLast(Node* head, int n){
    if(head == NULL){
        return NULL;
    }

    Node* p1 = head;
    Node* p2 = head;
    for(int j = 0; j < n - 1; j++){
        if(p2 == NULL){
            return NULL;
        }
        p2 = p2->next;
    }

    if(p2->next != NULL){
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
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

// Function to add a new node to the linked list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int main(){
    Node* head = NULL;

    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 4);
    addNode(&head, 5);
    addNode(&head, 2);

    printf("Linked list: ");
    printList(head);

    int n = 2; // Find the 2nd to last element
    Node* findNthToLast = nthToLast(head, n);

    if (findNthToLast == NULL) {
        printf("The list has less than %d nodes.\n", n);
    } else {
        printf("The %dth to last element is %d.\n", n, findNthToLast->data);
    }

    return 0;
}
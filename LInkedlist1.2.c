#include <stdio.h> 
#include <stdlib.h> 

/* Link list Node */
typedef struct Node { 
    int data; 
    struct Node* next; 
} Node;

int countOfNodes(Node* head) { 
    int count = 0; 
    while (head != NULL) { 
        head = head->next; 
        count++; 
    } 
    return count; 
} 

/*void deleteNode(Node* head){
    if(head == NULL || head->next == NULL){
        return;
    }
    Node* copyHead = head->next;
    head->data = copyHead->data;
    head->next = copyHead->next;
    free(copyHead);
}*/

Node* deleteNode(Node* head) { 
    // Base cases 
    if (head == NULL) 
        return NULL; 
    if (head->next == NULL) { 
        free(head); 
        return NULL; 
    } 
    Node* copyHead = head; 
    // Find the count of nodes 
    int count = countOfNodes(head); 
    // Find the middle node 
    int mid = count / 2; 
    // Delete the middle node 
    while(mid-->1) 
      head = head->next; 
    // Delete the middle node 
    head->next = head->next->next; 
    return copyHead; 
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
    addNode(&head, 4);
    addNode(&head, 5);
    /*addNode(&head, 5);
    addNode(&head, 2);*/

    printf("Linked list: ");
    printList(head);

    // Delete the middle node (node with value 3)
    deleteNode(head->next->next);

    printf("Linked list after deletion: ");
    printList(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/* Définition d'un Booléen */
typedef enum
{
    false,
    true
}Bool;

// Define the structure for an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Define the structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Define the structure for a graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph
        = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(
        V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to perform DFS to check if there is a route
int hasRoute(struct Graph* graph, int source, int destination, int* visited) {
    // Mark the current node as visited
    visited[source] = 1;

    // If the current node is the destination, return true
    if (source == destination) {
        return 1;
    }

    // Traverse the neighbors of the current node
    struct AdjListNode* neighbor = graph->array[source].head;
    while (neighbor != NULL) {
        if (!visited[neighbor->dest] && hasRoute(graph, neighbor->dest, destination, visited)) {
            return 1;
        }
        neighbor = neighbor->next;
    }

    // No route found, return false
    return 0;
}

int main() {
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Check if there is a route between node 0 and node 3
    int* visited = (int*)calloc(V, sizeof(int));
    if (hasRoute(graph, 0, 3, visited)) {
        printf("There is a route between node 0 and node 3.\n");
    } else {
        printf("There is no route between node 0 and node 3.\n");
    }

    // Check if there is a route between node 0 and node 2
    visited = (int*)calloc(V, sizeof(int));
    if (hasRoute(graph, 0, 2, visited)) {
        printf("There is a route between node 0 and node 2.\n");
    } else {
        printf("There is no route between node 0 and node 2.\n");
    }

    // Free the memory
    for (int i = 0; i < V; i++) {
        struct AdjListNode* temp = graph->array[i].head;
        while (temp != NULL) {
            struct AdjListNode* nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
    }
    free(graph->array);
    free(graph);
    free(visited);

    return 0;
}
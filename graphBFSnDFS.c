#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph node
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct Node* adjacencyList[MAX_VERTICES];
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Initialize adjacency list
    for (int i = 0; i < numVertices; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Add an edge from dest to src (since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function for Breadth-First Search (BFS) traversal
void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS Traversal: ");

    while (front != rear) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        // Visit all adjacent vertices of the dequeued vertex
        struct Node* temp = graph->adjacencyList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

// Function for Depth-First Search (DFS) traversal
void DFSUtil(struct Graph* graph, int vertex, int visited[]) {
    // Mark the current vertex as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Visit all adjacent vertices of the current vertex
    struct Node* temp = graph->adjacencyList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Wrapper function for DFS traversal
void DFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};

    printf("DFS Traversal: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

// Main function
int main() {
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    // Performing BFS and DFS traversals
    BFS(graph, 0);
    DFS(graph, 0);

    return 0;
}

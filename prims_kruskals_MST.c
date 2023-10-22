#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Structure to represent a graph
struct Graph {
    int numVertices, numEdges;
    struct Edge* edges;
};

// Function to create a graph
struct Graph* createGraph(int numVertices, int numEdges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->edges[graph->numEdges].src = src;
    graph->edges[graph->numEdges].dest = dest;
    graph->edges[graph->numEdges].weight = weight;
    graph->numEdges++;
}

// Function to find the set of an element (uses path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two sets (uses union by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare edges based on weight (used for sorting)
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to perform Kruskal's algorithm for MST
void kruskalMST(struct Graph* graph) {
    int numVertices = graph->numVertices;
    struct Edge result[numVertices - 1];  // MST will have numVertices-1 edges
    int e = 0;  // Index variable for result[]

    // Sort all the edges in non-decreasing order of their weights
    qsort(graph->edges, graph->numEdges, sizeof(graph->edges[0]), compareEdges);

    // Allocate memory for creating numVertices subsets
    struct Subset* subsets = (struct Subset*)malloc(numVertices * sizeof(struct Subset));

    // Initialize subsets for each vertex
    for (int v = 0; v < numVertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Process all edges one by one
    for (int i = 0; i < graph->numEdges; i++) {
        // Get the smallest edge and check if it forms a cycle or not
        int x = find(subsets, graph->edges[i].src);
        int y = find(subsets, graph->edges[i].dest);

        if (x != y) {
            result[e++] = graph->edges[i];
            unionSets(subsets, x, y);
        }
    }

    // Print the edges of MST
    printf("Kruskal's MST:\n");
    for (int i = 0; i < numVertices - 1; i++) {
        printf("%d - %d (%d)\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
}

// Function to find the vertex with the minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[], int numVertices) {
    int min = __INT_MAX__, min_index;

    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Prim's MST:\n");
    for (int i = 1; i < numVertices; i++)
        printf("%d - %d (%d)\n", parent[i], i, graph[i][parent[i]]);
}

// Function to perform Prim's algorithm for MST
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int parent[MAX_VERTICES];  // Array to store constructed MST
    int key[MAX_VERTICES];     // Key values used to pick the minimum weight edge
    bool mstSet[MAX_VERTICES]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < numVertices; i++) {
        key[i] = __INT_MAX__;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;     // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of MST

    // The MST will have numVertices vertices
    for (int count = 0; count < numVertices - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, numVertices);

        // Mark the picked vertex as included
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < numVertices; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if the graph[u][v] is smaller than the current key value
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, numVertices);
}

// Main function
int main() {
    int numVertices = 5;
    struct Graph* kruskalGraph = createGraph(numVertices, 7);

    // Adding edges to the graph for Kruskal's algorithm
    addEdge(kruskalGraph, 0, 1, 2);
    addEdge(kruskalGraph, 0, 3, 1);
    addEdge(kruskalGraph, 1, 2, 4);
    addEdge(kruskalGraph, 1, 3, 3);
    addEdge(kruskalGraph, 1, 4, 5);
    addEdge(kruskalGraph, 2, 4, 6);
    addEdge(kruskalGraph, 3, 4, 7);

    kruskalMST(kruskalGraph);

    // Adding adjacency matrix for Prim's algorithm
    int primGraph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 2, 0, 1, 0},
        {2, 0, 4, 3, 5},
        {0, 4, 0, 0, 0},
        {1, 3, 0, 0, 7},
        {0, 5, 0, 7, 0}
    };

    primMST(primGraph, numVertices);

    free(kruskalGraph->edges);
    free(kruskalGraph);

    return 0;
}

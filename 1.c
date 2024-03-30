#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Node* createNode(int v, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (Node**)malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

int shortestPath(Graph* graph, int src, int dest) {
    int* dist = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 0; i < graph->numVertices - 1; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            Node* node = graph->adjLists[j];
            while (node != NULL) {
                if (dist[j] != INT_MAX && dist[j] + node->weight < dist[node->vertex]) {
                    dist[node->vertex] = dist[j] + node->weight;
                }
                node = node->next;
            }
        }
    }

    int shortestPath = dist[dest];
    free(dist);
    return shortestPath;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u - 1, v - 1, w);
    }

    int s, t;
    scanf("%d %d", &s, &t);

    int shortest = shortestPath(graph, s - 1, t - 1);
    printf("%d\n", shortest);

    return 0;
}

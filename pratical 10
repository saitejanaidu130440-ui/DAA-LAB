#include <iostream>
#include <algorithm>
using namespace std;

// Structure to store an edge
struct Edge {
    int u, v, weight;
};

// Function to find the parent of a vertex
int findParent(int parent[], int x) {
    if (parent[x] == x)
        return x;

    return findParent(parent, parent[x]);
}

// Function to join two sets
void unionSet(int parent[], int rank[], int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {

    // Graph edges
    Edge edges[] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 3, 1},
        {1, 4, 4},
        {2, 3, 4},
        {2, 4, 5},
        {3, 4, 2}
    };

    int vertices = 5;
    int edgesCount = 7;

    // Sort edges according to weight
    sort(edges, edges + edgesCount, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    int parent[5];
    int rank[5] = {0};

    // Initially, every vertex is its own parent
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    cout << "Edges in Minimum Spanning Tree:\n";

    int totalCost = 0;
    int selectedEdges = 0;

    // Kruskal's Algorithm
    for (int i = 0; i < edgesCount; i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        // If they don't form a cycle
        if (parentU != parentV) {

            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unionSet(parent, rank, u, v);

            selectedEdges++;

            // MST needs V-1 edges
            if (selectedEdges == vertices - 1)
                break;
        }
    }

    cout << "Total Cost = " << totalCost << endl;

    return 0;
}

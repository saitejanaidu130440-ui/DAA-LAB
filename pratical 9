#include <iostream>
#include <climits>
using namespace std;

int main() {

    // Graph represented using an adjacency matrix
    int graph[5][5] = {
        {0, 2, 3, 0, 0},
        {2, 0, 0, 1, 4},
        {3, 0, 0, 4, 5},
        {0, 1, 4, 0, 2},
        {0, 4, 5, 2, 0}
    };

    int n = 5;

    int parent[n];
    int key[n];
    bool visited[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1;

    // Prim's Algorithm
    for (int count = 0; count < n - 1; count++) {

        int min = INT_MAX;
        int u;

        // Find the vertex with minimum key
        for (int i = 0; i < n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        // Include vertex in MST
        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    int totalCost = 0;

    cout << "Minimum Spanning Tree:\n";

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "Total Cost = " << totalCost << endl;

    return 0;
}

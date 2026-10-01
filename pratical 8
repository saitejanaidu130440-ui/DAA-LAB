#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Graph {
    int vertices;
    vector<vector<int>> graph;

public:
    Graph(int n) {
        vertices = n;
        graph.resize(n + 1);
    }

    void addEdge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void dfs(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int next : graph[node]) {
            if (!visited[next]) {
                dfs(next, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(vertices + 1, false);
        dfs(start, visited);
    }

    void BFS(int start) {
        vector<bool> visited(vertices + 1, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int next : graph[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    auto startDFS = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";
    g.DFS(start);

    auto endDFS = high_resolution_clock::now();

    auto dfsTime =
        duration_cast<nanoseconds>(endDFS - startDFS);

    auto startBFS = high_resolution_clock::now();

    cout << "\n\nBFS Traversal: ";
    g.BFS(start);

    auto endBFS = high_resolution_clock::now();

    auto bfsTime =
        duration_cast<nanoseconds>(endBFS - startBFS);

    cout << "\n\nExecution Time:";
    cout << "\nDFS: " << dfsTime.count() << " ns";
    cout << "\nBFS: " << bfsTime.count() << " ns";

    return 0;
}

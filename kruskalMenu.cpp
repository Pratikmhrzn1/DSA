#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Comparator function to sort edges by weight (Standard for Kruskal)
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Find function for Disjoint Set Union (DSU) with Path Compression
int findParent(int i, int parent[]) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent[i], parent);
}

// Union function to merge two subsets
void unionSet(int u, int v, int parent[]) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    if (rootU != rootV) {
        parent[rootU] = rootV;
    }
}

void kruskal(Edge edges[], int V, int E) {
    // 1. Sort all edges in non-decreasing order of weight
    sort(edges, edges + E, compareEdges);

    int parent[20]; // Array for DSU (Assuming max 20 vertices)
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int mst_weight = 0;
    int edges_count = 0;

    cout << "\nEdges in the Minimum Spanning Tree:\n";
    cout << "Edge \tWeight\n";

    // 2. Iterate through sorted edges
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        // 3. Check if the picked edge forms a cycle
        if (findParent(u, parent) != findParent(v, parent)) {
            cout << u << " - " << v << " \t" << w << endl;
            mst_weight += w;
            unionSet(u, v, parent);
            edges_count++;
        }

        // Optimization: MST always has V-1 edges
        if (edges_count == V - 1) break;
    }

    cout << "\nTotal Weight of MST: " << mst_weight << endl;
}

int main() {
    int V, E;
    Edge edges[100]; // Array of edges

    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(edges, V, E);

    return 0;
}

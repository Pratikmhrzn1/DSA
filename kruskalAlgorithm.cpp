#include <iostream>
#include <algorithm>
using namespace std;

#define V 4
#define E 5

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Comparator to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set (Union-Find)
int parent[V];

// Find function
int find(int i) {
    if (parent[i] == i)
        return i;
    return find(parent[i]);
}

// Union function
void unionSet(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    parent[xset] = yset;
}

void kruskalMST(Edge edges[]) {
    sort(edges, edges + E, compare);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "Edges in MST:\n";

    int count = 0;
    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) {
            cout << u << " - " << v << " : " << edges[i].weight << endl;
            unionSet(set_u, set_v);
            count++;
        }
    }
}

int main() {
    Edge edges[E] = {
        {0, 1, 1},
        {0, 2, 3},
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 5}
    };

    kruskalMST(edges);
	cout<<"\nPratik Maharjan";
    return 0;
}

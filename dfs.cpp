#include <iostream>
#include <vector>
using namespace std;

#define V 5

vector<int> graph[V];
bool visited[V];

// Traverse(v)
void traverse(int v) {
    visited[v] = true;
    cout << v << " ";

    // for each w adjacent to v and not yet in T
    for (int i = 0; i < graph[v].size(); i++) {
        int w = graph[v][i];

        if (!visited[w]) {
            traverse(w);
        }
    }
}

// DFS(G, s)
void DFS(int s) {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    traverse(s);
}

int main() {
    // Graph (Adjacency List)
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(0);
    graph[3].push_back(1);
    graph[4].push_back(1);

    DFS(0);
	cout<<"\nPratik Maharjan";
    return 0;
}

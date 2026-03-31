#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    int cost[20][20];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter adjacency matrix (enter 0 if no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }
    int visited[20] = {0};
    int mincost = 0;
    visited[0] = 1;
    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (int edge = 0; edge < n - 1; edge++) {
        int min = INT_MAX;
        int u = -1, v = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        visited[v] = 1;
        cout << u << " - " << v << " : " << min << endl;
        mincost += min;
    }
    cout << "\nTotal cost of MST = " << mincost << endl;
    cout<<"\nPratik Maharjan";
    return 0;
}

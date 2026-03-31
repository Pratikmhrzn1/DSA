#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, source;
    int cost[20][20];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (enter 0 if no edge):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }

    cout << "Enter source vertex: ";
    cin >> source;

    int dist[20];
    int visited[20] = {0};

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = cost[source][i];

    dist[source] = 0;
    visited[source] = 1;

    for (int count = 1; count < n; count++)
    {
        int min = INT_MAX, u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && cost[u][v] != INT_MAX &&
                dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";
    for (int i = 0; i < n; i++)
        cout << source << " -> " << i << " = " << dist[i] << endl;

    return 0;
}

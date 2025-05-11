#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start, const vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from node " << start << " using Dijkstra's:\n";
    for (int i = 0; i < n; ++i) {
        cout << "To node " << i << ": ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

void bellman(int V, const vector<vector<pair<int, int>>>& adj, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Flatten the adjacency list into edges
    vector<tuple<int, int, int>> edges;
    for (int u = 0; u < V; ++u) {
        for (auto& edge : adj[u]) {
            edges.emplace_back(u, edge.first, edge.second);
        }
    }

    for (int i = 0; i < V - 1; ++i) {
        for (auto& edge : edges) {
            int u = get<0>(edge), v = get<1>(edge), wt = get<2>(edge);
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative cycles
    for (auto& edge : edges) {
        int u = get<0>(edge), v = get<1>(edge), wt = get<2>(edge);
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            cout << "A negative-weight cycle exists in the graph.\n";
            return;
        }
    }

    cout << "\nShortest distances from node " << source << " using Bellman-Ford:\n";
    for (int i = 0; i < V; ++i) {
        cout << "To node " << i << ": ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    int V, E, choice;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    cout << "Choose algorithm:\n1. Dijkstra's\n2. Bellman-Ford\n";
    cin >> choice;

    vector<vector<pair<int, int>>> adj(V);
    cout << "Enter each edge as: from to weight\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    if (choice == 1) {
        dijkstra(source, adj);
    } else if (choice == 2) {
        bellman(V, adj, source);
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}

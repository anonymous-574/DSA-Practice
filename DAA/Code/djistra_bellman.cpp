#include <bits/stdc++.h>
using namespace std;

// ---------- For Dijkstra's ----------
struct DijkstraEdge {
    int to, weight;
};

void dijkstra(int start, const vector<vector<DijkstraEdge>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const DijkstraEdge& e : graph[u]) {
            int v = e.to, weight = e.weight;
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

// ---------- For Bellman-Ford ----------
struct BellmanEdge {
    int u, v, wt;
};

void bellman(int V, int E, vector<BellmanEdge>& edges, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].u, v = edges[j].v, wt = edges[j].wt;
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < E; ++j) {
        int u = edges[j].u, v = edges[j].v, wt = edges[j].wt;
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

// ---------- Main ----------
int main() {
    int V, E, choice;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    cout << "Choose algorithm:\n1. Dijkstra's\n2. Bellman-Ford\n";
    cin >> choice;

    if (choice == 1) {
        vector<vector<DijkstraEdge>> graph(V);
        cout << "Enter each edge as: from to weight (non-negative weights only)\n";
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
        }
        int source;
        cout << "Enter source node: ";
        cin >> source;
        dijkstra(source, graph);
    } else if (choice == 2) {
        vector<BellmanEdge> edges(E);
        cout << "Enter each edge as: from to weight (can be negative)\n";
        for (int i = 0; i < E; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].wt;
        }
        int source;
        cout << "Enter source node: ";
        cin >> source;
        bellman(V, E, edges, source);
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}

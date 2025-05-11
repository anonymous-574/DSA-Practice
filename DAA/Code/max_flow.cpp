#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int>> flow, residual, capacity;

// Utility to print shortest path
void printPath(vector<int>& parent, int v) {
    if (parent[v] == -1) {
        cout << v << " ";
        return;
    }
    printPath(parent, parent[v]);
    cout << v << " ";
}

// Bellman-Ford for shortest paths from source
void bellmanFord(int V, vector<vector<int>>& adj, int src) {
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    dist[src] = 0;

    vector<tuple<int, int, int>> edges;
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != INF) {
                edges.push_back(make_tuple(u, v, adj[u][v]));
            }
        }
    }

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            int u, v, weight;
            tie(u, v, weight) = edges[j];
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (int j = 0; j < edges.size(); j++) {
        int u, v, weight;
        tie(u, v, weight) = edges[j];
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << "Algorithm Used: Bellman-Ford\n";
            cout << "Graph contains a negative weight cycle\n";
            return;
        }
    }

    cout << "\nAlgorithm Used: Bellman-Ford\n";
    cout << "Bellman-Ford Shortest Paths from Node " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " Distance: " << (dist[i] == INF ? -1 : dist[i]) << " Path: ";
        if (dist[i] != INF) printPath(parent, i);
        cout << "\n";
    }
}

// DFS for augmenting path (Ford-Fulkerson)
int dfs(int V, int s, int t, vector<int>& visited, vector<int>& parent) {
    if (s == t) return 1;
    visited[s] = 1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && residual[s][i] > 0) {
            parent[i] = s;
            if (dfs(V, i, t, visited, parent)) return 1;
        }
    }
    return 0;
}

// Ford-Fulkerson algorithm (Max Flow)
void Ford_Fulkerson(int V, int s, int t) {
    flow.assign(V, vector<int>(V, 0));
    int maxFlow = 0;

    while (true) {
        vector<int> visited(V, 0);
        vector<int> parent(V, -1);
        if (!dfs(V, s, t, visited, parent)) break;

        int path_flow = INT_MAX;
        int v = t;
        while (v != s) {
            int u = parent[v];
            path_flow = min(path_flow, residual[u][v]);
            v = u;
        }

        cout << "\nAugmenting path (from sink to source): ";
        v = t;
        while (v != s) {
            cout << v << " <- ";
            v = parent[v];
        }
        cout << s << "\n";
        cout << "Bottleneck capacity = " << path_flow << "\n";

        v = t;
        cout << "Updated flow on edges in the path:\n";
        while (v != s) {
            int u = parent[v];
            if (capacity[u][v] > 0) flow[u][v] += path_flow;
            else flow[v][u] -= path_flow;
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
            cout << " Edge (" << u << " -> " << v << "): flow = " << flow[u][v] << " / capacity = " << capacity[u][v] << "\n";
            v = u;
        }

        maxFlow += path_flow;
    }

    cout << "\nNo more augmenting paths. Maximum Flow = " << maxFlow << "\n";
    cout << "\nFinal flows (u -> v):\n";
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            if (capacity[u][v])
                cout << "(" << u << " -> " << v << "): " << flow[u][v] << " / " << capacity[u][v] << "\n";
}

int main() {
    int V, E;
    cout << "Vertices and Edges: ";
    cin >> V >> E;

    capacity.assign(V, vector<int>(V, 0));
    vector<vector<int>> adj(V, vector<int>(V, INF));

    cout << "Edges (format: u v capacity):\n";
    for (int i = 0; i < E; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        capacity[u][v] = cap;
        adj[u][v] = cap; // for Bellman-Ford
    }

    residual = capacity;

    int s, t;
    cout << "Source and Sink: ";
    cin >> s >> t;

    Ford_Fulkerson(V, s, t);
    bellmanFord(V, adj, s);

    return 0;
}

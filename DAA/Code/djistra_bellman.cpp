#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start, const vector<vector<pair<int, int>>> adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (const pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
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

void bellman(int V, const vector<vector<pair<int, int>>> adj, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    //just make the tuple
    vector<tuple<int, int, int>> edges;
    for (int u = 0; u < V; ++u) {
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            edges.push_back(make_tuple(u, v, w));
        }
    }

    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            int u = get<0>(edges[j]);
            int v = get<1>(edges[j]);
            int wt = get<2>(edges[j]);
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (int j = 0; j < edges.size(); ++j) {
        int u = get<0>(edges[j]);
        int v = get<1>(edges[j]);
        int wt = get<2>(edges[j]);
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
        adj[u].push_back(make_pair(v, w));
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

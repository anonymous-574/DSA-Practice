#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <fstream>
#include <tuple>

using namespace std;

#define INF numeric_limits<int>::max()

void printPath(vector<int> &parent, int node, ofstream &outfile) {
    if (node == -1) return;
    printPath(parent, parent[node], outfile);
    outfile << node << " ";
}

void dijkstra(int V, vector<vector<int>> &adj, int src, ofstream &outfile) {
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < V; v++) {
            if (adj[u][v] != INF && dist[u] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    outfile << "Algorithm Used: Dijkstra\n";
    outfile << "Dijkstra Shortest Paths:\n";
    for (int i = 0; i < V; i++) {
        outfile << "Node " << i << " Distance: " << (dist[i] == INF ? -1 : dist[i]) << " Path: ";
        if (dist[i] != INF) printPath(parent, i, outfile);
        outfile << "\n";
    }
}

void bellmanFord(int V, vector<vector<int>> &adj, int src, ofstream &outfile) {
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    dist[src] = 0;

    vector<tuple<int, int, int>> edges;
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != INF) {
                edges.push_back({u, v, adj[u][v]});
            }
        }
    }

    for (int i = 0; i < V - 1; i++) {
        for (auto &[u, v, weight] : edges) {
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (auto &[u, v, weight] : edges) {
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            outfile << "Algorithm Used: Bellman-Ford\n";
            outfile << "Graph contains a negative weight cycle\n";
            return;
        }
    }

    outfile << "Algorithm Used: Bellman-Ford\n";
    outfile << "Bellman-Ford Shortest Paths:\n";
    for (int i = 0; i < V; i++) {
        outfile << "Node " << i << " Distance: " << (dist[i] == INF ? -1 : dist[i]) << " Path: ";
        if (dist[i] != INF) printPath(parent, i, outfile);
        outfile << "\n";
    }
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile) {
        cerr << "Error opening input file\n";
        return 1;
    }

    int testCases;
    infile >> testCases;
    infile.ignore();

    for (int t = 1; t <= testCases; t++) {
        int V, E, src;
        infile >> V >> E;

        if (V <= 0 || E < 0) {
            cerr << "Invalid graph dimensions\n";
            continue;
        }

        vector<vector<int>> adj(V, vector<int>(V, INF));

        for (int i = 0; i < V; i++)
            adj[i][i] = 0;

        bool hasNegative = false;

        for (int i = 0; i < E; i++) {
            int u, v, weight;
            infile >> u >> v >> weight;
            if (u >= V || v >= V || u < 0 || v < 0) {
                cerr << "Invalid edge: " << u << " -> " << v << "\n";
                continue;
            }
            adj[u][v] = weight;
            if (weight < 0) hasNegative = true;
        }

        infile >> src;
        if (src < 0 || src >= V) {
            cerr << "Invalid source node: " << src << "\n";
            continue;
        }

        infile.ignore();

        outfile << "Test Case #" << t << ":\n";
        outfile << "Vertices: " << V << ", Edges: " << E << ", Source: " << src << "\n";

        if (hasNegative)
            bellmanFord(V, adj, src, outfile);
        else
            dijkstra(V, adj, src, outfile);

        outfile << "\n-----------------------------------\n\n";
    }

    infile.close();
    outfile.close();
    return 0;
}

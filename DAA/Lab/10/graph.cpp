//David Daniels
//2023300038

#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void generateRandomConnectedGraph();
    void printGraph();
    void printVertexCover();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::generateRandomConnectedGraph() {
    srand(time(0));
    vector<pair<int, int>> edges;

    vector<int> vertices(V);
    for (int i = 0; i < V; ++i) vertices[i] = i;
    random_shuffle(vertices.begin(), vertices.end());

    for (int i = 1; i < V; ++i) {
        int u = vertices[i];
        int v = vertices[rand() % i];
        addEdge(u, v);
        edges.push_back({u, v});
    }

    int extraEdges = rand() % (V + 5);  
    while (extraEdges--) {
        int u = rand() % V;
        int v = rand() % V;
        if (u != v) {
            bool exists = false;
            for (int x : adj[u])
                if (x == v)
                    exists = true;
            if (!exists) {
                addEdge(u, v);
                edges.push_back({u, v});
            }
        }
    }
}

void Graph::printGraph() {
    cout << "Graph Adjacency List:\n";
    for (int v = 0; v < V; ++v) {
        cout << v << ": ";
        for (int neighbor : adj[v])
            cout << neighbor << " ";
        cout << "\n";
    }
    cout << "\n";
}

void Graph::printVertexCover() {
    bool visited[V] = {false};

    for (int u = 0; u < V; u++) {
        if (!visited[u]) {
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[u] = true;
                    visited[v] = true;
                    break;
                }
            }
        }
    }

    cout << "Vertex Cover: ";
    for (int i = 0; i < V; i++)
        if (visited[i])
            cout << i << " ";
    cout << "\n";
}

int main() {
    Graph g(10);
    g.generateRandomConnectedGraph();
    g.printGraph();
    g.printVertexCover();
    return 0;
}

#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <numeric>

using namespace std;

#define V 20 // Number of vertices

class directed_graph {
public:
    vector<vector<int>> generate(int vertices, int d);
    bool edgeExists(const vector<vector<int>>& adj_matrix, int u, int v);
};

bool directed_graph::edgeExists(const vector<vector<int>>& adj_matrix, int u, int v) {
    return adj_matrix[u][v] != 0;
}

vector<vector<int>> directed_graph::generate(int vertices, int d) {
    float density = d / 100.0;
    int edges = round(density * vertices * (vertices - 1));
    vector<vector<int>> adj_matrix(vertices, vector<int>(vertices, 0));

    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> weight_dist(1, 100);

    vector<int> v_vertices(vertices - 1);
    iota(v_vertices.begin(), v_vertices.end(), 1);

    int random = 0, random1;
    for (int i = 0; i < vertices - 1; i++) {
        uniform_int_distribution<int> vertex_dist(0, v_vertices.size() - 1);
        random1 = vertex_dist(e1);

        int weight = weight_dist(e1);
        adj_matrix[random][v_vertices[random1]] = weight;

        random = v_vertices[random1];
        v_vertices.erase(v_vertices.begin() + random1);
    }

    adj_matrix[random][0] = weight_dist(e1);

    int needed = edges - (vertices - 1);
    uniform_int_distribution<int> vertex_dist(0, vertices - 1);

    for (int i = 0; i < needed;) {
        int u = vertex_dist(e1);
        int v = vertex_dist(e1);

        if (u != v && !edgeExists(adj_matrix, u, v)) {
            int weight = weight_dist(e1);
            adj_matrix[u][v] = weight;
            i++;
        }
    }

    return adj_matrix;
}

bool bfs(vector<vector<int>> &rGraph, int s, int t, vector<int> &parent) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

bool dfsUtil(vector<vector<int>> &rGraph, int s, int t, vector<int> &parent, vector<bool> &visited) {
    visited[s] = true;
    if (s == t) return true;
    
    for (int v = 0; v < V; v++) {
        if (!visited[v] && rGraph[s][v] > 0) {
            parent[v] = s;
            if (dfsUtil(rGraph, v, t, parent, visited)) return true;
        }
    }
    return false;
}

bool dfs(vector<vector<int>> &rGraph, int s, int t, vector<int> &parent) {
    vector<bool> visited(V, false);
    return dfsUtil(rGraph, s, t, parent, visited);
}

void dfsPrint(vector<vector<int>> &rGraph, int s, vector<bool> &visited) {
    visited[s] = true;
    cout << s << " ";
    for (int v = 0; v < V; v++) {
        if (rGraph[s][v] > 0 && !visited[v]) {
            dfsPrint(rGraph, v, visited);
        }
    }
}

int fordFulkerson(vector<vector<int>> &graph, int s, int t, bool useDFS) {
    vector<vector<int>> rGraph = graph;
    vector<int> parent(V);
    int max_flow = 0;
    
    cout << "\n===============================" << endl;
    cout << (useDFS ? "Using DFS" : "Using BFS") << " for Ford-Fulkerson Algorithm" << endl;
    cout << "===============================\n" << endl;
    
    while ((useDFS ? dfs(rGraph, s, t, parent) : bfs(rGraph, s, t, parent))) {
        int path_flow = INT_MAX;
        vector<int> path;
        
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
            path.push_back(v);
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        
        cout << "Path Used: ";
        for (int node : path) {
            cout << node << " -> ";
        }
        cout << "(Capacity: " << path_flow << ")" << endl;
        
        max_flow += path_flow;
    }
    
    cout << "\nFinal Residual Graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << rGraph[i][j] << " ";
        }
        cout << endl;
    }
    
    
    cout << endl;
    
    return max_flow;
}

void printGraph(const vector<vector<int>>& graph) {
    int n = graph.size();
    cout << "\nAdjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices = V;
    int density = 30;

    directed_graph graphGen;
    vector<vector<int>> graph = graphGen.generate(vertices, density);

    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> vertex_dist(0, vertices - 1);

    int source = vertex_dist(e1);
    int sink;
    do {
        sink = vertex_dist(e1);
    } while (sink == source);

    cout << "\nSource: " << source << "\nSink: " << sink << "\n";
    printGraph(graph);

    cout << "\nUsing BFS: Maximum possible flow: " << fordFulkerson(graph, source, sink, false) << "\n";
    cout << "\nUsing DFS: Maximum possible flow: " << fordFulkerson(graph, source, sink, true) << "\n";
    
    return 0;
}
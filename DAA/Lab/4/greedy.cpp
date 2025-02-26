#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <fstream>
#include <chrono>
#include <queue>
#include <cmath>

using namespace std;
using namespace std::chrono;

class undirected_graph {
public:
    vector<vector<int>> generate(int vertices, int d);
    bool edgeExists(const vector<vector<int>>& adj_matrix, int u, int v);
};

bool undirected_graph::edgeExists(const vector<vector<int>>& adj_matrix, int u, int v) {
    return adj_matrix[u][v] != 0;  // Check if an edge already exists
}

vector<vector<int>> undirected_graph::generate(int vertices, int d) {
    float density = d / 100.0;
    int edges = round(density * vertices * (vertices - 1) / 2);
    vector<vector<int>> adj_matrix(vertices, vector<int>(vertices, 0));

    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> weight_dist(1, 100);

    vector<int> v_vertices(vertices - 1);
    iota(v_vertices.begin(), v_vertices.end(), 1);  // Start from 1, exclude 0

    int random = 0, random1;
    for (int i = 0; i < vertices - 1; i++) {
        uniform_int_distribution<int> vertex_dist(0, v_vertices.size() - 1);
        random1 = vertex_dist(e1);

        int weight = weight_dist(e1);
        adj_matrix[random][v_vertices[random1]] = weight;
        adj_matrix[v_vertices[random1]][random] = weight;

        random = v_vertices[random1];
        v_vertices.erase(v_vertices.begin() + random1);
    }

    int needed = edges - (vertices - 1);
    uniform_int_distribution<int> vertex_dist(0, vertices - 1);

    for (int i = 0; i < needed;) {
        int u = vertex_dist(e1);
        int v = vertex_dist(e1);

        if (u != v && !edgeExists(adj_matrix, u, v)) {
            int weight = weight_dist(e1);
            adj_matrix[u][v] = weight;
            adj_matrix[v][u] = weight;
            i++;
        }
    }

    return adj_matrix;
}

class union_find {
private:
    vector<int> parent, rank;
public:
    union_find(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);  // Path compression
        return parent[i];
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] >= rank[root_j]) {  
                parent[root_j] = root_i;
                if (rank[root_i] == rank[root_j])  
                    rank[root_i]++;
            } else {
                parent[root_i] = root_j;
            }
        }
    }
};

vector<vector<int>> prims(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> tree;
    vector<bool> visited(n, false);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    visited[0] = true;
    for (int j = 0; j < n; j++) {
        if (graph[0][j] > 0) {
            pq.push({graph[0][j], {0, j}});
        }
    }

    while (!pq.empty() && tree.size() < n - 1) {
        pair<int, pair<int, int>> topElement = pq.top();
        pq.pop();
        int weight = topElement.first;
        int u = topElement.second.first;
        int v = topElement.second.second;

        if (visited[v]) continue;

        tree.push_back({u, v, weight});
        visited[v] = true;

        for (int j = 0; j < n; j++) {
            if (graph[v][j] > 0 && !visited[j]) {
                pq.push({graph[v][j], {v, j}});
            }
        }
    }

    return tree;
}

vector<vector<int>> kruskal(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> tree;
    union_find uf(n);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] > 0) {
                pq.push({graph[i][j], {i, j}});
            }
        }
    }

    while (!pq.empty() && tree.size() < n - 1) {
        pair<int, pair<int, int>> topElement = pq.top();
        pq.pop();
        int weight = topElement.first;
        int u = topElement.second.first;
        int v = topElement.second.second;

        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            tree.push_back({u, v, weight});
        }
    }

    return tree;
}

void saveMatrixToFile(const vector<vector<int>>& matrix, const string& filename, int vertices) {
    ofstream file(filename, ios::app); // Append mode
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file << "Adjacency Matrix for " << vertices << " vertices:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            file << val << "\t";
        }
        file << "\n";
    }
    file << "----------------------\n";
}

void saveTreeToFile(const vector<vector<int>>& tree, const string& filename, string algo, int vertices) {
    ofstream file(filename, ios::app); // Append mode
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file << algo << " Tree for " << vertices << " vertices:\n";
    for (const auto& edge : tree) {
        file << edge[0] << ", " << edge[1] << ", " << edge[2] << "\n";
    }
    file << "----------------------\n";
}

int main() {
    undirected_graph graph;
    ofstream timeFile("time.txt", ios::trunc);
    ofstream matrixFile("matrix.txt", ios::trunc); // Clear matrix file at start
    ofstream treeFile("tree.txt", ios::trunc); // Clear tree file at start

    timeFile << "number, prim, kruskal\n";

    vector<int> vertex_counts = {8, 15, 20};

    for (int vertices : vertex_counts) {
        vector<vector<int>> adj_matrix = graph.generate(vertices, 50);

        saveMatrixToFile(adj_matrix, "matrix.txt", vertices);

        auto start1 = high_resolution_clock::now();
        vector<vector<int>> prim_tree = prims(adj_matrix);
        auto end1 = high_resolution_clock::now();
        auto prim_time = duration_cast<nanoseconds>(end1 - start1).count();

        auto start2 = high_resolution_clock::now();
        vector<vector<int>> kruskal_tree = kruskal(adj_matrix);
        auto end2 = high_resolution_clock::now();
        auto kruskal_time = duration_cast<nanoseconds>(end2 - start2).count();

        timeFile << vertices << ", " << prim_time << ", " << kruskal_time << "\n";

        saveTreeToFile(prim_tree, "tree.txt", "Prim's", vertices);
        saveTreeToFile(kruskal_tree, "tree.txt", "Kruskal's", vertices);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// ---------- For Prim's ----------
void prim(int start, vector<vector<pair<int, int>>> &graph) {
    int n = graph.size();
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> inMST(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    key[start] = 0;
    pq.push({0, start});

    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += key[u];

        for (const auto &e : graph[u]) {
            int v = e.first, weight = e.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "\nEdges in the MST (Prim's):\n";
    for (int v = 0; v < n; ++v) {
        if (parent[v] != -1)
            cout << parent[v] << " - " << v << " (Weight: " << key[v] << ")\n";
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

// ---------- For Kruskal's ----------
bool cmp(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<2>(a) < get<2>(b); // Compare based on the weight
}

int findSet(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = findSet(parent, parent[x]);
    return parent[x];
}

void unionSet(int parent[], int rank[], int x, int y) {
    int rootX = findSet(parent, x);
    int rootY = findSet(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

void kruskal(int V, vector<tuple<int, int, int>>& edges) {
    int parent[V], rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sort(edges.begin(), edges.end(), cmp);
    int mstWeight = 0, edgeUsed = 0;

    cout << "\nEdges in the MST (Kruskal's):\n";
    for (auto &e : edges) {
        if (edgeUsed == V - 1) break;
        int u = get<0>(e), v = get<1>(e), w = get<2>(e);
        if (findSet(parent, u) != findSet(parent, v)) {
            unionSet(parent, rank, u, v);
            cout << u << " - " << v << " (Weight: " << w << ")\n";
            mstWeight += w;
            edgeUsed++;
        }
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

// ---------- Main ----------
int main() {
    int V, E, algoChoice;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    cout << "Choose algorithm:\n1. Prim's\n2. Kruskal's\n";
    cin >> algoChoice;

    if (algoChoice == 1) {
        vector<vector<pair<int, int>>> graph(V);
        cout << "Enter each edge as: from to weight\n";
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        int start;
        cout << "Enter starting node: ";
        cin >> start;
        prim(start, graph);
    } else if (algoChoice == 2) {
        vector<tuple<int, int, int>> edges(E);
        cout << "Enter each edge as: from to weight\n";
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = make_tuple(u, v, w);
        }
        kruskal(V, edges);
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}

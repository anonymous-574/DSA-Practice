#include <bits/stdc++.h>
using namespace std;

// ---------- For Prim's ----------
struct PrimEdge {
    int to, weight;
};

void prim(int start, vector<vector<PrimEdge>> &graph) {
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

        for (const PrimEdge &e : graph[u]) {
            int v = e.to, weight = e.weight;
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
struct KruskalEdge {
    int u, v, weight;
};

bool cmp(KruskalEdge a, KruskalEdge b) {
    return a.weight < b.weight;
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

void kruskal(int V, vector<KruskalEdge> &edges) {
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
        int u = e.u, v = e.v, w = e.weight;
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
        vector<vector<PrimEdge>> graph(V);
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
        vector<KruskalEdge> edges(E);
        cout << "Enter each edge as: from to weight\n";
        for (int i = 0; i < E; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        }
        kruskal(V, edges);
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}

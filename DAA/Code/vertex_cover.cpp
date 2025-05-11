#include <bits/stdc++.h>
using namespace std;

vector<int> approximateVertexCover(int V, const vector<pair<int, int>> &edges) {
    vector<bool> visited(V, false);
    vector<int> cover;

    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        if (!visited[u] && !visited[v]) {
            visited[u] = true;
            visited[v] = true;
            cover.push_back(u);
            cover.push_back(v);
        }
    }

    return cover;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<pair<int, int>> edges;
    cout << "Enter " << E << " edges (format: u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    // Print edge list
    cout << "\nGraph Edge List:\n";
    for (int i = 0; i < E; ++i)
        cout << edges[i].first << " - " << edges[i].second << "\n";

    // Get and print vertex cover
    vector<int> cover = approximateVertexCover(V, edges);
    cout << "\nVertex Cover (approximate): ";
    for (int i = 0; i < cover.size(); ++i)
        cout << cover[i] << " ";
    cout << "\n";

    return 0;
}

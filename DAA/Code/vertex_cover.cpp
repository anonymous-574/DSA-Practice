#include <bits/stdc++.h>
using namespace std;
void approx_vertex(int V, int E, vector<pair<int,int>> &edges){
    vector<bool> inCover(V,false);
    vector<bool> active(E,true);

    vector<vector<int>> incident(V);
    for(int i = 0; i<E; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        incident[u].push_back(i);
        incident[v].push_back(i);
    }
    int nextEdge = 0;

    while(true){
        while(nextEdge < E && !active[nextEdge])
            nextEdge++;
        if(nextEdge == E) break;

        int u   = edges[nextEdge].first;
        int v   = edges[nextEdge].second;

        inCover[u] = inCover[v] = true;

        cout <<"Edge "<< u << " - " << v << " covered\n";

        for(int j : incident[u]) active[j] = false;
        for(int j : incident[v]) active[j] = false;  
    }
    int c =0;
    cout<<"Vertex: ";
    for (int i = 0; i < V; i++)
        if (inCover[i]){
            cout << i <<" ";c++;
        }
            
    cout << "Cover size = " << c;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>> edges(E);
    for(int i =0;i < E;i++) cin>>edges[i].first>>edges[i].second;
    approx_vertex(V,E,edges);
    return 0;
}
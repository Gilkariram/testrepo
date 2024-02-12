#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& e) const {
        return w < e.w;
    }
};

vector<int> parent;

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    parent[find(u)] = find(v);
}

vector<Edge> kruskal(vector<Edge> edges, int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end());
    vector<Edge> mst;
    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            mst.push_back(e);
        }
    }
    return mst;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    vector<Edge> edges(m);
    string line;
    int u, v, w;
    getline(cin, line); // consume newline character after m
    for (int i = 0; i < m; i++) {
        cout << "Enter edge " << i + 1 << " in the format u v w: ";
        getline(cin, line);
        stringstream ss(line);
        ss >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    vector<Edge> mst = kruskal(edges, n);
    int mst_weight = 0;
    for (Edge e : mst) {
        mst_weight += e.w;
    }
    cout << "Minimum Spanning Tree weight: " << mst_weight << endl;

    for (Edge e : mst) {
        cout << e.u << " " << e.v << " " << e.w << endl;
    }
    return 0;
}

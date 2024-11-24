#include <bits/stdc++.h>
using namespace std;

ifstream fin("building.in");
ofstream fout("building.out");

vector<int> components;
vector<bool> visited;
vector<vector<int> > adj;

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int N, M;
    fin >> N >> M;

    adj.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            components.push_back(i);
            dfs(i);
        }
    }

    int roads = components.size() - 1;
    fout << roads << endl;

    for (int i = 1; i < components.size(); i++) {
        fout << components[i - 1] << " " << components[i] << endl;
    }

    return 0;
}

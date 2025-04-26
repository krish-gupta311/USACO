#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> pic;

ifstream fin("revegetate.in");
ofstream fout("revegetate.out");

vector<vector<pic> > adj;
vector<bool> visited;
vector<vector<int> > components;
vector<int> colors;

void dfs(int node, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor.first]) {
            dfs(neighbor.first, component);
        }
    }
}

bool bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    colors[node] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto neighbor : adj[current]) {
            int neighborNode = neighbor.first;
            char relation = neighbor.second;

            if (colors[neighborNode] == -1) {
                // Assign a color based on the relationship
                if (relation == 'S') {
                    colors[neighborNode] = colors[current];
                } else { // 'D'
                    colors[neighborNode] = 1 - colors[current];
                }
                q.push(neighborNode);
                visited[neighborNode] = true;
            } else {
                // Check for conflicts
                if (relation == 'S' && colors[neighborNode] != colors[current]) {
                    return false;
                }
                if (relation == 'D' && colors[neighborNode] == colors[current]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int N, M;
    fin >> N >> M;
    adj.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < M; i++) {
        char sd;
        int a, b;
        fin >> sd >> a >> b;
        a--;
        b--;
        adj[a].emplace_back(b, sd);
        adj[b].emplace_back(a, sd);
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, component);
            components.push_back(component);
        }
    }
    fill(visited.begin(), visited.end(), false);

    colors.resize(N, -1);
    for (auto& component : components) {
        if (!bfs(component[0])) {
            fout << 0 << endl;
            return 0;
        }
    }

    fout << 1;
    for (size_t i = 0; i < components.size(); i++) {
        fout << 0;
    }
    fout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// ifstream fin("flights.in");
// ofstream fout("flights.out");

vector<bool> visited;
vector<vector<int> > adj, rev_adj;

void dfs(int node, vector<vector<int> >& graph) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    rev_adj.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    visited.assign(N + 1, false);
    dfs(1, adj);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
    }

    visited.assign(N + 1, false);
    dfs(1, rev_adj);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}

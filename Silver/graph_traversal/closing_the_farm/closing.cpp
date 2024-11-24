#include <bits/stdc++.h>
using namespace std;

ifstream fin("closing.in");
ofstream fout("closing.out");

vector<vector<int> > adj;
vector<bool> active;

void dfs(int node, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor] && active[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}

bool connected(int N) {
    vector<bool> visited(N + 1, false);
    
    // Find an active barn to start the DFS from
    int start = -1;
    for (int i = 1; i <= N; i++) {
        if (active[i]) {
            start = i;
            break;
        }
    }
    
    if (start == -1) return true;  // No barns left, so it's trivially connected

    dfs(start, visited);
    
    for (int i = 1; i <= N; i++) {
        if (active[i] && !visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    fin >> N >> M;

    adj.resize(N + 1);
    active.resize(N + 1, true);

    for (int i = 0; i < M; i++) {
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> closing_order(N);
    for (int i = 0; i < N; i++) {
        fin >> closing_order[i];
    }

    vector<string> results;
    for (int i = 0; i < N; i++) {
        if (connected(N)) {
            results.push_back("YES");
        } else {
            results.push_back("NO");
        }

        int barn_to_remove = closing_order[i];
        active[barn_to_remove] = false;  // Mark the barn as removed
    }

    for (const string &result : results) {
        fout << result << endl;
    }
    
    return 0;
}

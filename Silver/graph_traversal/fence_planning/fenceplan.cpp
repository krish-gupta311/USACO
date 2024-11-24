#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

// Graph representation
vector<vector<int> > adj;  // Adjacency list
vector<bool> visited;     // Visited nodes
vector<pii> coords;       // Cow coordinates

// Variables for bounding box
int min_x, max_x, min_y, max_y;

// Perform DFS to find connected components and their bounding boxes
void dfs(int node) {
    visited[node] = true;

    // Update bounding box coordinates
    min_x = min(min_x, coords[node].first);
    max_x = max(max_x, coords[node].first);
    min_y = min(min_y, coords[node].second);
    max_y = max(max_y, coords[node].second);

    // Explore neighbors
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    // Input
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");

    int N, M;
    fin >> N >> M;

    // Initialize data structures
    adj.resize(N);
    visited.resize(N, false);
    coords.resize(N);

    // Read coordinates
    for (int i = 0; i < N; i++) {
        fin >> coords[i].first >> coords[i].second;
    }

    // Read moo connections and build adjacency list
    for (int i = 0; i < M; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;  // Convert to 0-based indexing
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Find all connected components and calculate perimeters
    int min_perimeter = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            // Initialize bounding box
            min_x = INT_MAX;
            max_x = INT_MIN;
            min_y = INT_MAX;
            max_y = INT_MIN;

            // Perform DFS for this component
            dfs(i);

            // Calculate perimeter of bounding box
            int perimeter = 2 * ((max_x - min_x) + (max_y - min_y));
            min_perimeter = min(min_perimeter, perimeter);
        }
    }

    // Output result
    fout << min_perimeter << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// ifstream fin("building.in");
// ofstream fout("building.out");

vector<vector<int> > adj;
map<int,int> color;

bool bipartite(int N) {

    for (int i = 0; i < N; i++) {
        color[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                for (int neighbor : adj[current]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[current];
                        q.push(neighbor);
                    } else if (color[current] == color[neighbor]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;

}

int main() {

    int N, M;
    cin >> N >> M;

    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (!bipartite(N)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cout << color[i] + 1 << " ";
    }

    return 0;

}
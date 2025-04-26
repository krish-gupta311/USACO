#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> colors;
vector<vector<int>> adj;

void bipartite(int N) {
    for (int i = 0; i < N; i++) {
        colors[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        if (colors[i] == -1) {
            queue<int> q;
            q.push(i);
            colors[i] = 0;
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                for (int neighbor : adj[current]) {
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 1 - colors[current];
                        q.push(neighbor);
                    }
                }
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    adj.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    colors.resize(N);
    bipartite(N);

    ll red_count = 0, green_count = 0;
    for (int i = 0; i < N; i++) {
        if (colors[i] == 0) {
            red_count++;
        } else {
            green_count++;
        }
    }

    ll total_possible_edges = red_count * green_count;
    ll additional_edges = total_possible_edges - (N - 1);

    cout << additional_edges << endl;
    return 0;
}

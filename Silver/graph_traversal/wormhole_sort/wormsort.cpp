#include <bits/stdc++.h>
using namespace std;

vector<int> loc, lhs, rhs, weight, component;
vector<vector<pair<int, int> > > edges;

void dfs(int curr, int label, int minW) {
    if (component[curr] == label) return;
    component[curr] = label;
    for (size_t i = 0; i < edges[curr].size(); i++) {
        if (edges[curr][i].second >= minW) {
            dfs(edges[curr][i].first, label, minW);
        }
    }
}

bool valid(int minW, int n) {
    fill(component.begin(), component.end(), -1);
    int numcomps = 0;
    for (int i = 0; i < n; i++) {
        if (component[i] < 0) {
            dfs(i, numcomps++, minW);
        }
    }
    for (int i = 0; i < n; i++) {
        if (component[i] != component[loc[i]]) return false;
    }
    return true;
}

int main() {
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");

    int n, m;
    fin >> n >> m;

    loc.resize(n);
    component.resize(n);
    edges.resize(n);
    lhs.resize(m);
    rhs.resize(m);
    weight.resize(m);

    for (int i = 0; i < n; i++) {
        fin >> loc[i];
        loc[i]--; // Convert to 0-based index
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        fin >> a >> b >> w;
        a--, b--; // Convert to 0-based index
        edges[a].push_back(make_pair(b, w));
        edges[b].push_back(make_pair(a, w));
    }

    int minW = 0;
    int maxW = 1000000001;

    while (minW != maxW) {
        int mid = (minW + maxW + 1) / 2;
        if (valid(mid, n)) {
            minW = mid;
        } else {
            maxW = mid - 1;
        }
    }

    if (minW > 1e9) minW = -1;
    fout << minW << endl;

    return 0;
}

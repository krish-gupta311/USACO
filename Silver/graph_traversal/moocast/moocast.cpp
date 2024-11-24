#include <bits/stdc++.h>
using namespace std;

ifstream fin("moocast.in");
ofstream fout("moocast.out");

vector<vector<int> > adj;
vector<int> components;

void dfs(int node, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}

int connected(int N,int start) {

    vector<bool> visited(N,false);

    dfs(start,visited);

    int size = 0;
    for (bool val : visited) {

        if (val) size++;

    }

    return size;

}

int main() {

    int N;
    fin >> N;

    adj.resize(N);

    vector<vector<int> > coords;
    for (int i = 0; i < N; i++) {
        int x,y,p;
        fin >> x >> y >> p;
        vector<int> coord;
        coord.push_back(x);
        coord.push_back(y);
        coord.push_back(p);
        coords.push_back(coord);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                vector<int> c1 = coords[i];
                vector<int> c2 = coords[j];
                if (pow(pow(c1[0]-c2[0],2)+pow(c1[1]-c2[1],2),.5) <= c1[2]) {
                    adj[i].push_back(j);
                }
            }
        }
    }

    int max_size = 0;
    for (int i = 0; i < N; i++) {
        max_size = max(connected(N,i),max_size);
    }

    fout << max_size << endl;

    return 0;

}


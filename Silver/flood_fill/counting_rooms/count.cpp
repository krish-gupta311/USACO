#include <bits/stdc++.h>
using namespace std;

// ifstream fin("count.in");
// ofstream fout("count.out");

vector<vector<bool> > visited;

void flood_fill(vector<vector<char> >& grid, int x, int y) {

    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return;
    if (visited[x][y] || grid[x][y] != '.') return;

    visited[x][y] = true;
    
    flood_fill(grid,x+1,y);
    flood_fill(grid,x-1,y);
    flood_fill(grid,x,y+1);
    flood_fill(grid,x,y-1);

}

int main() {

    int N,M;
    cin >> N >> M;

    visited.resize(N, vector<bool>(M,false));

    vector<vector<char> > grid;
    for (int i = 0; i < N; i++) {
        vector<char> row;
        for (int j = 0; j < M; j++) {
            char a;
            cin >> a;
            row.push_back(a);
        }
        grid.push_back(row);
    }

    int rooms = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j] == '.') {
                flood_fill(grid,i,j);
                rooms++;
            }
        }
    }

    cout << rooms << endl;

}
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

// Input and output files
ifstream fin("perimeter.in");
ofstream fout("perimeter.out");

// Directions for flood fill (N, S, E, W)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// Function to check if a cell is within bounds
bool inBounds(int x, int y, int N) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

// DFS-based flood fill function
void dfs(vector<vector<char> >& grid, vector<vector<bool> >& visited, int x, int y, int& area, int& perimeter, int N) {
    visited[x][y] = true;
    area++;

    int sides = 4; // Assume all sides contribute to the perimeter initially

    // Explore all 4 directions
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (inBounds(nx, ny, N)) {
            if (grid[nx][ny] == '#') {
                sides--; // Neighbor reduces the perimeter contribution
                if (!visited[nx][ny]) {
                    dfs(grid, visited, nx, ny, area, perimeter, N);
                }
            }
        }
    }

    perimeter += sides; // Add the remaining perimeter for this cell
}

int main() {
    int N;
    fin >> N;

    vector<vector<char> > grid(N, vector<char>(N));
    vector<vector<bool> > visited(N, vector<bool>(N, false));

    // Read the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fin >> grid[i][j];
        }
    }

    int maxArea = 0, minPerimeter = INT_MAX;

    // Iterate through the grid to find all blobs
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && grid[i][j] == '#') {
                int area = 0, perimeter = 0;
                dfs(grid, visited, i, j, area, perimeter, N);

                // Update the maximum area and minimum perimeter
                if (area > maxArea || (area == maxArea && perimeter < minPerimeter)) {
                    maxArea = area;
                    minPerimeter = perimeter;
                }
            }
        }
    }

    // Output the result
    fout << maxArea << " " << minPerimeter << endl;

    return 0;
}

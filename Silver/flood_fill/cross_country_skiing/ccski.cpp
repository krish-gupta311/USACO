// #include <bits/stdc++.h>
// using namespace std;
// typedef  long long ll;
// typedef pair<int,int> pii;

// ifstream fin("ccski.in");
// ofstream fout("ccski.out");

// vector<vector<ll> > grid;
// vector<pii> waypoints;
// vector<vector<bool> > visited;

// void flood_fill(int x, int y, ll mid) {

//     if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
//         return;
//     }
//     if (visited[x][y]) {
//         return;
//     }
//     visited[x][y] = true;
//     if (abs(grid[x+1][y]-grid[x][y]) <= mid) flood_fill(x + 1, y, mid);
//     if (abs(grid[x-1][y]-grid[x][y]) <= mid) flood_fill(x - 1, y, mid);
//     if (abs(grid[x][y+1]-grid[x][y]) <= mid) flood_fill(x, y + 1, mid);
//     if (abs(grid[x][y-1]-grid[x][y]) <= mid) flood_fill(x, y - 1, mid);

// }

// bool f(ll mid) {

//     flood_fill(waypoints[0].first,waypoints[0].second,mid);
//     for (auto point : waypoints) {
//         if (!visited[point.first][point.second]) {
//             return false;
//         }
//     }
//     return true;

// }

// ll first_true(ll lo, ll hi) {

//     lo--;
//     while (lo < hi) {
//         int mid = (lo + floor((hi-lo)/2));
//         if (f(mid)) {
//             hi = mid;
//         } else {
//             lo = mid + 1;
//         }
//         visited.resize(grid.size(),vector<bool>(grid[0].size(),false));
//     }
//     return lo;

// }


// int main() {

//     int N,M;
//     fin >> N >> M;

//     grid.resize(N,vector<ll>(M));
//     visited.resize(N,vector<bool>(M,false));

//     ll minA = __LONG_LONG_MAX__;
//     ll maxA = -__LONG_LONG_MAX__;
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             fin >> grid[i][j];
//             minA = min(minA,grid[i][j]);
//             maxA = max(maxA,grid[i][j]);
//         }
//     }
//     int maxD = maxA - minA;

//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             int a;
//             fin >> a;
//             if (a == 1) waypoints.emplace_back(i,j);
//         }
//     }

//     ll diff = first_true(0LL,maxD);
//     fout << diff << endl;

//     return 0;

// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ifstream fin("ccski.in");
ofstream fout("ccski.out");

vector<vector<ll> > grid;
vector<pii> waypoints;
vector<vector<bool> > visited;

// Directions: Right, Left, Down, Up
const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void reset_visited() {
    for (int i = 0; i < visited.size(); i++) {
        fill(visited[i].begin(), visited[i].end(), false);
    }
}

void dfs(int x, int y, ll mid) {
    visited[x][y] = true;

    for (int d = 0; d < 4; d++) {
        int nx = x + directions[d][0];
        int ny = y + directions[d][1];

        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && !visited[nx][ny]) {
            if (abs(grid[nx][ny] - grid[x][y]) <= mid) {
                dfs(nx, ny, mid);
            }
        }
    }
}

bool f(ll mid) {
    reset_visited();
    dfs(waypoints[0].first, waypoints[0].second, mid);

    for (auto point : waypoints) {
        if (!visited[point.first][point.second]) {
            return false;
        }
    }
    return true;
}

ll first_true(ll lo, ll hi) {
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    int N, M;
    fin >> N >> M;

    grid.resize(N, vector<ll>(M));
    visited.resize(N, vector<bool>(M));

    ll minA = LLONG_MAX, maxA = LLONG_MIN;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fin >> grid[i][j];
            minA = min(minA, grid[i][j]);
            maxA = max(maxA, grid[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int a;
            fin >> a;
            if (a == 1) waypoints.emplace_back(i, j);
        }
    }

    ll diff = first_true(0LL, maxA - minA);
    fout << diff << endl;

    return 0;
}

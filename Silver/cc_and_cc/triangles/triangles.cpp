#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

// Structure for modulo arithmetic
struct ModInt {
    int v; 
    explicit operator int() const { return v; }
    ModInt(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    ModInt() : ModInt(0) {}
};
ModInt operator+(ModInt a, ModInt b) { return ModInt(a.v + b.v); }
ModInt operator-(ModInt a, ModInt b) { return ModInt(a.v - b.v); }
ModInt operator*(ModInt a, ModInt b) { return ModInt((ll)a.v * b.v); }

int N;
vector<pair<int, int>> points; // Store the coordinates of the points
vector<ModInt> sum[100005];    // Store calculated sum distances for x and y groups
vector<pair<int, int>> groups[20001]; // Group points by x or y coordinates

void calculateSumDistances() {
    for (int i = 0; i <= 20000; ++i) {
        if (!groups[i].empty()) {
            int size = groups[i].size();
            sort(groups[i].begin(), groups[i].end());

            ModInt cur = 0;
            // Calculate initial sum of distances
            for (int j = 0; j < size; ++j) {
                cur = cur + groups[i][j].first - groups[i][0].first;
            }

            for (int j = 0; j < size; ++j) {
                if (j > 0) {
                    cur = cur + (2 * j - size) * (groups[i][j].first - groups[i][j - 1].first);
                }
                sum[groups[i][j].second].push_back(cur);
            }
        }
    }
}

int main() {
    // Open input and output files
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    // Read the number of points
    cin >> N; 
    points.resize(N);
    
    // Read the coordinates and prepare groups
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    // Process x groups (group by x and sort by y)
    for (int i = 0; i <= 20000; ++i) groups[i].clear();
    for (int i = 0; i < N; ++i) 
        groups[points[i].first + 10000].emplace_back(points[i].second, i);
    calculateSumDistances();

    // Process y groups (group by y and sort by x)
    for (int i = 0; i <= 20000; ++i) groups[i].clear();
    for (int i = 0; i < N; ++i) 
        groups[points[i].second + 10000].emplace_back(points[i].first, i);
    calculateSumDistances();

    // Calculate the total area contribution from all points
    ModInt totalArea = 0;
    for (int i = 0; i < N; ++i) 
        totalArea = totalArea + sum[i][0] * sum[i][1];

    // Output the result (2 times the total area modulo MOD)
    cout << totalArea.v << "\n";

    return 0;
}

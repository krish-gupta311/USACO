#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ifstream fin("towers.in");
// ofstream fout("towers.out");

int main() {

    int N;
    cin >> N;

    vector<ll> cubes(N);
    for (int i = 0; i < N; i++) {
        cin >> cubes[i];
    }

    vector<ll> towers;
    for (const ll &cube : cubes) {
        if (towers.empty()) {
            towers.push_back(cube);
        } else {
            auto it = upper_bound(towers.begin(), towers.end(), cube);
            if (it == towers.end()) {
                towers.push_back(cube);
            } else {
                towers[it - towers.begin()] = cube;
            }
        }
    }

    cout << towers.size();

    return 0;
    
}